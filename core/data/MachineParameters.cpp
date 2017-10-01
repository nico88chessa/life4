#include "MachineParameters.hpp"

using namespace life;
using namespace machineparameters;

MachineParameters::MachineParameters() {
    load();
}

void MachineParameters::load() {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    parameters.insert(PREF_MACHINE_ETH_INTERFACE_LAN.key,
                      settings.value(PREF_MACHINE_ETH_INTERFACE_LAN.key, PREF_MACHINE_ETH_INTERFACE_LAN.defaultValue).
                      value<MACHINE_PARAMETER_TYPE(PREF_MACHINE_ETH_INTERFACE_LAN)>());

    parameters.insert(PREF_MACHINE_ETH_INTERFACE_DEVICES.key,
                      settings.value(PREF_MACHINE_ETH_INTERFACE_DEVICES.key, PREF_MACHINE_ETH_INTERFACE_DEVICES.defaultValue).
                      value<MACHINE_PARAMETER_TYPE(PREF_MACHINE_ETH_INTERFACE_DEVICES)>());

    parameters.insert(PREF_GUI_LANGUAGE.key,
                      settings.value(PREF_GUI_LANGUAGE.key, PREF_GUI_LANGUAGE.defaultValue).
                      value<MACHINE_PARAMETER_TYPE(PREF_GUI_LANGUAGE)>());

    parameters.insert(PREF_GUI_UNIT_MEASURE.key,
                      settings.value(PREF_GUI_UNIT_MEASURE.key, PREF_GUI_UNIT_MEASURE.defaultValue).
                      value<MACHINE_PARAMETER_TYPE(PREF_GUI_UNIT_MEASURE)>());

    parameters.insert(PREF_GUI_SPLASH_ENABLE.key,
                      settings.value(PREF_GUI_SPLASH_ENABLE.key, PREF_GUI_SPLASH_ENABLE.defaultValue).
                      value<MACHINE_PARAMETER_TYPE(PREF_GUI_SPLASH_ENABLE)>());

}

void MachineParameters::flush() const {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    for (const QString& key: parameters.keys())
        settings.setValue(key, parameters.value(key));

}
