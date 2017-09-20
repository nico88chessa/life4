#include "MachineParameters.hpp"

using namespace life;

MachineParameters::MachineParameters() {
    load();
}

QVariant MachineParameters::getValue(const QString& key) const {  return parameters.value(key); }

void MachineParameters::setValue(const QString& key, const QVariant& value) {

    parameters.insert(key, value);

}

void MachineParameters::load() {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    using namespace life::machineparameters;

    parameters.insert(QString(PREF_MACHINE_ETH_INTERFACE_LAN),
                      settings.value(PREF_MACHINE_ETH_INTERFACE_LAN, PREF_MACHINE_ETH_INTERFACE_LAN_DFLT).value<QString>());
    parameters.insert(QString(PREF_MACHINE_ETH_INTERFACE_DEVICES),
                      settings.value(PREF_MACHINE_ETH_INTERFACE_DEVICES, PREF_MACHINE_ETH_INTERFACE_DEVICES_DFLT).value<QString>());
    parameters.insert(QString(PREF_GUI_LANGUAGE),
                      settings.value(PREF_GUI_LANGUAGE, PREF_GUI_LANGUAGE_DFLT).value<QString>());
    parameters.insert(QString(PREF_GUI_UNIT_MEASURE),
                      settings.value(PREF_GUI_UNIT_MEASURE, PREF_GUI_UNIT_MEASURE_DFLT).value<QString>());
    parameters.insert(QString(PREF_GUI_SPLASH_ENABLE),
                      settings.value(PREF_GUI_SPLASH_ENABLE, PREF_GUI_SPLASH_ENABLE_DFLT).value<QString>());

}

void MachineParameters::flush() const {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    for (QString key: parameters.keys())
        settings.setValue(key, parameters.value(key));

}
