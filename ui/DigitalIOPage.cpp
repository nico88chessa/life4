#include "DigitalIOPage.hpp"
#include "ui_DigitalIOPage.h"

using namespace life;


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

    auto& allParameters = parameterManager->getIOs();

    for (auto&& key: allParameters.keys()) {

        if (auto&& digitalItem = std::dynamic_pointer_cast<const DigitalIO>(allParameters.value(key))) {
            auto test = std::make_shared<DigitalIO>(*digitalItem);
            this->digitalParameters[key] = test;
            new QListWidgetItem(key, ui->IOList);
        }
    }


    ui->IOList->setCurrentIndex(itemSelected);
    // this->model2View(); questo non lo chiamo perche' viene implicitamente chiamato quando cambio l'indice su IOList
    // grazie al segnale currentItemChanged
}

bool DigitalIOPage::save() {

    // se c'e' una item selezionato, devo prendere il valore corrente
    QModelIndex index = ui->IOList->currentIndex();
    if (index.isValid()) {
        QString key = ui->IOList->item(index.row())->text();
        *this->digitalParameters[key] = digitalIOSelected;
    }

    if (!validate())
        return false;

    for (auto&& key: digitalParameters.keys()) {
        auto&& value = digitalParameters.value(key);
        parameterManager->setIO(key, *value);
    }
    return true;

}



void DigitalIOPage::IOItemListActivated(QListWidgetItem *current, QListWidgetItem *previous) {

    using namespace life;

    if (previous != nullptr) {
        QString previousKey = previous->text();
        *this->digitalParameters[previousKey] = digitalIOSelected;
    }

    QString itemKey = current->text();
    digitalIOSelected = *this->digitalParameters.value(itemKey);
    model2View();

}

void DigitalIOPage::setupGraphics() {

    using namespace life;

    ui->name->setReadOnly(true);

    for (const QString& direction: DirectionTypeStr)
        ui->direction->addItem(direction);

    for (const QString& device: DeviceKindStr)
        ui->device->addItem(device);

    auto& allParameters = parameterManager->getIOs();

    for (auto&& key: allParameters.keys()) {

        if (auto&& digitalItem = std::dynamic_pointer_cast<const DigitalIO>(allParameters.value(key))) {
            auto test = std::make_shared<DigitalIO>(*digitalItem);
            this->digitalParameters[key] = test;
            new QListWidgetItem(key, ui->IOList);
        }

    }
}

void DigitalIOPage::createConnections() {

    connect(ui->IOList, &QListWidget::currentItemChanged, this, &DigitalIOPage::IOItemListActivated);

    connect(ui->enabled, &QCheckBox::stateChanged, [this](int state) {
        if (state == Qt::Checked)
            this->digitalIOSelected.channel = 0;
        else
            this->digitalIOSelected.channel = -1;
        model2View();
    });

    connect(ui->channel, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int value) {
        this->digitalIOSelected.channel = value;
        model2View();
    });

    connect(ui->device, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged), [this](const QString& value) {
        this->digitalIOSelected.device = static_cast<life::DeviceKind>(life::DeviceKindFromString(value));
        model2View();
    });

    connect(ui->direction, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged), [this](const QString& value) {
        this->digitalIOSelected.direction = static_cast<life::DirectionType>(life::DirectionTypeFromString(value));
        model2View();
    });

    connect(ui->invertLogic, &QCheckBox::stateChanged, [this](int state) {
        this->digitalIOSelected.invertLogic = state == Qt::Checked;
        model2View();
    });

    connect(ui->isAlarm, &QCheckBox::stateChanged, [this](int state) {
        this->digitalIOSelected.isAlarm = state == Qt::Checked;
        model2View();
    });

//    connect(ui->alarmText, &QLineEdit::editingFinished, [this](bool checked) {
//        model2ViewIoDetails();
//    });

}

void DigitalIOPage::model2View() {

    blockIoDetailsSignals(true);

    bool enableIODetails = ui->IOList->currentItem() != nullptr;
    ui->IODetails->setEnabled(enableIODetails);

    if (enableIODetails) {
        bool enableIoDetailsWidget = digitalIOSelected.channel != -1;

        ui->channel->setEnabled(enableIoDetailsWidget);
        ui->device->setEnabled(enableIoDetailsWidget);
        ui->direction->setEnabled(enableIoDetailsWidget);
        ui->invertLogic->setEnabled(enableIoDetailsWidget);
        ui->isAlarm->setEnabled(enableIoDetailsWidget);
        ui->alarmText->setReadOnly(enableIoDetailsWidget);

        ui->name->setText(digitalIOSelected.name);
        ui->enabled->setChecked(enableIoDetailsWidget);

        if (enableIoDetailsWidget) {
            ui->channel->setValue(digitalIOSelected.channel);
            ui->device->setCurrentIndex(static_cast<int>(digitalIOSelected.device));
            ui->direction->setCurrentIndex(static_cast<int>(digitalIOSelected.direction));
            ui->invertLogic->setChecked(digitalIOSelected.invertLogic);
            ui->isAlarm->setChecked(digitalIOSelected.isAlarm);
            ui->alarmText->setText(digitalIOSelected.alarmText);
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

    QMap<int, QList<QString>> cnEntries;
    QMap<int, QList<QString>> plcEntries;

    for (auto&& key: this->digitalParameters.keys()) {
        DeviceKind device = digitalParameters[key]->device;
        int channel = digitalParameters[key]->channel;

        switch (device) {
        case DeviceKind::CN: cnEntries[channel].append(key); break;
        case DeviceKind::PLC: plcEntries[channel].append(key); break;
        default: break;
        }
    }

    // ora cerco se ci sono doppioni
    // per CN
    for (auto&& key: cnEntries.keys())
        if (cnEntries[key].count() > 1)
            return false;

    // e per PLC
    for (auto&& key: plcEntries.keys())
        if (plcEntries[key].count() > 1)
            return false;

    return true;
}
