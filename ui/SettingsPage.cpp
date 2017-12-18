#include "SettingsPage.hpp"
#include "ui_SettingsPage.h"

SettingsPage::SettingsPage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingsPage) {

    ui->setupUi(this);

    this->setupGraphics();

    this->model2View();
}

SettingsPage::~SettingsPage() {
    delete ui;
}

void SettingsPage::removeAllWidgets() {
    QLayoutItem* item;
    while ((item = ui->verticalLayout->takeAt(0)) != nullptr) {
        delete item;
    }

}

void SettingsPage::updateSetting() {

    auto value = qobject_cast<QComboBox*>(sender());
    if (value) {

        qDebug() << this->sender();
    }
}

void SettingsPage::setupGraphics() {

    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::MACHINE_ETH_INTERFACE_LAN));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::MACHINE_ETH_INTERFACE_DEVICES));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::GUI_LANGUAGE));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::GUI_UNIT_MEASURE));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::GUI_SPLASH_ENABLE));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CN_IP));

    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_STEPPERUNIT));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_ZEROACC));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_ZEROSPEED));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_ACC));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_SPEED));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_STEPSPEED));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_STEPACC));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_MINPOS));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_MAXPOS));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_BASEOFFSET));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_FEEDBACK));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_KIND));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISX_SAFETYPOSITION));

    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_STEPPERUNIT));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_ZEROACC));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_ZEROSPEED));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_ACC));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_SPEED));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_STEPADJ));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_MINPOS));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_MAXPOS));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_COLLISIONREF));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_MANUALADJ));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_SAFETYPOSITION));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::AXISZ_PRESENT));

    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_STEPPERUNIT));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_ZEROSPEED));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_ZEROACC));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_ACCMIN));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_ACCMAX));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_HEAVYSELECTOR));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_MINDIAMETER));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_MAXDIAMETER));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_MINLENGTH));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_MAXLENGTH));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_MINSPEED));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_MAXSPEED));
    ui->verticalLayout->addLayout(widgetParameter(life::machineparameters::CYLINDER_NUMOFENCODERS));

}

void SettingsPage::model2View() {

    using namespace life::machineparameters;

    auto parameters = parameterManager.getParameters();

    for (auto&& key : parameters.keys()) {
        auto value = parameters.value(key);
        auto widget = this->ui->scrollAreaWidgetContents->findChild<QWidget*>(key);

        if (auto lineEdit = qobject_cast<QLineEdit*>(widget)) {
            lineEdit->setText(value.toString());
        } else if (auto checkBox = qobject_cast<QCheckBox*>(widget)) {
            checkBox->setChecked(value.toBool());
        } else if (auto spinBox = qobject_cast<QSpinBox*>(widget)) {
            spinBox->setValue(value.toInt());
        } else if (auto comboBox = qobject_cast<QComboBox*>(widget)) {
            if (comboBox->objectName().compare(GUI_UNIT_MEASURE.key) == 0) {
                //for (auto it: GuiUnitMeasure)
                //    if (GuiUnitMeasureStr[it] == value)
                //        comboBox->setCurrentIndex(GuiUnitMeasureStr[it]);
            }
        }

    }

}

void SettingsPage::view2Model() {

}

