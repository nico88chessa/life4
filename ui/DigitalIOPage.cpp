#include "DigitalIOPage.hpp"
#include "ui_DigitalIOPage.h"

using namespace life;

TableErrorWidget::TableErrorWidget(QWidget *parent) : QTableWidget(parent) {

    this->setColumnCount(3);
    this->setRowCount(0);
    this->horizontalHeader()->hide();
    this->verticalHeader()->hide();

    this->setCellWidget(0,0, new QComboBox());
}

void TableErrorWidget::updateConflicts(const QList<TableErrorWidget::ConflictItem> &items) {

    this->clear();
    this->setColumnCount(3);
    this->setRowCount(items.size());

    int i=0;
    for (auto&& row : items) {
        this->setItem(i, 0, new QTableWidgetItem(life::DeviceKindStr[static_cast<int>(row.device)]));
        this->setItem(i, 1, new QTableWidgetItem(QString::number(row.channel)));
        QString names;
        for (auto&& io: row.digitalIO) {
            if (io == row.digitalIO.last())
                names.append(io.name);
            else
                names.append(io.name + " - ");
        }
        this->setItem(i, 2, new QTableWidgetItem(names));
        ++i;
    }

}

DigitalIOPage::DigitalIOPage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DigitalIOPage) {

    ui->setupUi(this);

}

DigitalIOPage::~DigitalIOPage() {
    delete ui;
}

void DigitalIOPage::init(const std::shared_ptr<ParametersManager>& parameterManager) {

    this->parameterManager = parameterManager;

    this->setupGraphics();

    this->createConnections();

    this->model2View();

}

void DigitalIOPage::reset() {

    QModelIndex itemSelected = ui->IOList->currentIndex();

    ui->IOList->disconnect(ui->IOList, &QListWidget::currentItemChanged, this, &DigitalIOPage::IOItemListActivated);
    ui->IOList->clear();
    ui->IOList->connect(ui->IOList, &QListWidget::currentItemChanged, this, &DigitalIOPage::IOItemListActivated);

    auto&& allParameters = parameterManager->getIOs();

    this->digitalParameters.clear();

    for (auto&& key: allParameters.keys()) {

        if (auto&& digitalItem = std::dynamic_pointer_cast<const DigitalIO>(allParameters.value(key))) {
            auto test = *digitalItem;
            this->digitalParameters[key] = test;
            new QListWidgetItem(key, ui->IOList);
        }
    }

    ui->IOList->setCurrentIndex(itemSelected);
    this->validate();
    // this->model2View(); questo non lo chiamo perche' viene implicitamente chiamato quando cambio l'indice su IOList
    // grazie al segnale currentItemChanged
}

bool DigitalIOPage::save() {

    // se c'e' una item selezionato, devo prendere il valore corrente
    //QModelIndex index = ui->IOList->currentIndex();
    //if (index.isValid()) {
    //    QString key = ui->IOList->item(index.row())->text();
    //    *this->digitalParameters[key] = digitalIOSelected;
    //}

    if (!validate())
        return false;

    for (auto&& key: digitalParameters.keys()) {
        auto&& value = digitalParameters.value(key);
        parameterManager->setIO(key, value);
    }
    return true;

}



void DigitalIOPage::IOItemListActivated(QListWidgetItem *current, QListWidgetItem *previous) {

    using namespace life;

    //if (previous != nullptr) {
    //    QString previousKey = previous->text();
    //    *this->digitalParameters[previousKey] = digitalIOSelected;
    //}

    digitalIOSelectedKey = current->text();
    model2View();

}

void DigitalIOPage::setupGraphics() {

    using namespace life;

    ui->name->setReadOnly(true);

    for (const QString& direction: DirectionTypeStr)
        ui->direction->addItem(direction);

    for (const QString& device: DeviceKindStr)
        ui->device->addItem(device);

    auto&& allParameters = parameterManager->getIOs();

    for (auto&& key: allParameters.keys()) {

        if (auto&& digitalItem = std::dynamic_pointer_cast<const DigitalIO>(allParameters.value(key))) {
            auto test = *digitalItem;
            this->digitalParameters[key] = test;
            new QListWidgetItem(key, ui->IOList);
        }

    }
}

void DigitalIOPage::createConnections() {

    connect(ui->IOList, &QListWidget::currentItemChanged, this, &DigitalIOPage::IOItemListActivated);

    connect(ui->enabled, &QCheckBox::stateChanged, [this](int state) {
        if (state == Qt::Checked)
            this->digitalParameters[digitalIOSelectedKey].channel = 0;
        else
            this->digitalParameters[digitalIOSelectedKey].channel = -1;
        validate();
        model2View();
    });

    connect(ui->channel, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int value) {
        this->digitalParameters[digitalIOSelectedKey].channel = value;
//        this->digitalIOSelected.channel = value;
        validate();
        model2View();
    });

    connect(ui->device, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged), [this](const QString& value) {
//        this->digitalIOSelected.device = static_cast<life::DeviceKind>(life::DeviceKindFromString(value));
        this->digitalParameters[digitalIOSelectedKey].device = static_cast<life::DeviceKind>(life::DeviceKindFromString(value));
        validate();
        model2View();
    });

    connect(ui->direction, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged), [this](const QString& value) {
//        this->digitalIOSelected.direction = static_cast<life::DirectionType>(life::DirectionTypeFromString(value));
        this->digitalParameters[digitalIOSelectedKey].direction = static_cast<life::DirectionType>(life::DirectionTypeFromString(value));
        model2View();
    });

    connect(ui->invertLogic, &QCheckBox::stateChanged, [this](int state) {
//        this->digitalIOSelected.invertLogic = state == Qt::Checked;
        this->digitalParameters[digitalIOSelectedKey].invertLogic = state == Qt::Checked;
        model2View();
    });

    connect(ui->isAlarm, &QCheckBox::stateChanged, [this](int state) {
//        this->digitalIOSelected.isAlarm = state == Qt::Checked;
        this->digitalParameters[digitalIOSelectedKey].isAlarm = state == Qt::Checked;
        model2View();
    });

//    connect(ui->alarmText, &QLineEdit::editingFinished, [this](bool checked) {
//        model2ViewIoDetails();
//    });

}

void DigitalIOPage::model2View() {

    blockIoDetailsSignals(true);

//    bool enableIODetails = ui->IOList->currentItem() != nullptr;
    bool enableIODetails = !this->digitalIOSelectedKey.isEmpty();
    ui->IODetails->setEnabled(enableIODetails);

    if (enableIODetails) {
        DigitalIO current = digitalParameters[digitalIOSelectedKey];
        bool enableIoDetailsWidget = current.channel != -1;

        ui->channel->setEnabled(enableIoDetailsWidget);
        ui->device->setEnabled(enableIoDetailsWidget);
        ui->direction->setEnabled(enableIoDetailsWidget);
        ui->invertLogic->setEnabled(enableIoDetailsWidget);
        ui->isAlarm->setEnabled(enableIoDetailsWidget);
        ui->alarmText->setReadOnly(enableIoDetailsWidget);

        ui->name->setText(current.name);
        ui->enabled->setChecked(enableIoDetailsWidget);

        if (enableIoDetailsWidget) {
            ui->channel->setValue(current.channel);
            ui->device->setCurrentIndex(static_cast<int>(current.device));
            ui->direction->setCurrentIndex(static_cast<int>(current.direction));
            ui->invertLogic->setChecked(current.invertLogic);
            ui->isAlarm->setChecked(current.isAlarm);
            ui->alarmText->setText(current.alarmText);
        } else {
            ui->channel->clear();
            ui->device->setCurrentIndex(-1);
            ui->direction->setCurrentIndex(-1);
            ui->invertLogic->setChecked(false);
            ui->isAlarm->setChecked(false);
            ui->alarmText->clear();
        }
    } else {
        ui->name->clear();
        ui->channel->clear();
        ui->device->setCurrentIndex(-1);
        ui->direction->setCurrentIndex(-1);
        ui->invertLogic->setChecked(false);
        ui->isAlarm->setChecked(false);
        ui->alarmText->clear();
    }

    blockIoDetailsSignals(false);

}

void DigitalIOPage::blockIoDetailsSignals(bool value) {

    ui->name->blockSignals(value);
    ui->enabled->blockSignals(value);
    ui->channel->blockSignals(value);
    ui->device->blockSignals(value);
    ui->direction->blockSignals(value);
    ui->invertLogic->blockSignals(value);
    ui->isAlarm->blockSignals(value);
    ui->alarmText->blockSignals(value);
}

bool DigitalIOPage::validate() {

    QMap<int, QList<DigitalIO>> cnEntries;
    QMap<int, QList<DigitalIO>> plcEntries;


    DigitalIO current;
    if (!digitalIOSelectedKey.isEmpty())
        current = digitalParameters[digitalIOSelectedKey];


    for (auto&& key: this->digitalParameters.keys()) {

        if (key == current.name)
            continue;

        DeviceKind device = digitalParameters[key].device;
        int channel = digitalParameters[key].channel;

        if (channel == -1)
            continue;

        switch (device) {
        case DeviceKind::CN: cnEntries[channel].append(digitalParameters[key]); break;
        case DeviceKind::PLC: plcEntries[channel].append(digitalParameters[key]); break;
        default: break;
        }
    }

    switch (current.device) {
    case DeviceKind::CN: cnEntries[current.channel].append(current); break;
    case DeviceKind::PLC: plcEntries[current.channel].append(current); break;
    default: break;
    }

    QList<TableErrorWidget::ConflictItem> conflicts;

    // ora cerco se ci sono doppioni
    // per CN
    for (auto&& key: cnEntries.keys())
        if (cnEntries[key].count() > 1)
            conflicts.append( { DeviceKind::CN, key, cnEntries[key] } );

    // e per PLC
    for (auto&& key: plcEntries.keys())
        if (plcEntries[key].count() > 1)
            conflicts.append( { DeviceKind::PLC, key, plcEntries[key]} );

    this->ui->errorList->updateConflicts(conflicts);

    if (!conflicts.isEmpty())
        return false;

    return true;
}
