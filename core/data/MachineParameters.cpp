#include "MachineParameters.hpp"

using namespace life;
using namespace machineparameters;

MachineParameters::MachineParameters() {
    load();
}

void MachineParameters::load() {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    parameters.insert(PREF_MACHINE_ETH_INTERFACE_LAN.key, settings.value(PREF_MACHINE_ETH_INTERFACE_LAN.key, PREF_MACHINE_ETH_INTERFACE_LAN.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_MACHINE_ETH_INTERFACE_LAN)>());
    parameters.insert(PREF_MACHINE_ETH_INTERFACE_DEVICES.key, settings.value(PREF_MACHINE_ETH_INTERFACE_DEVICES.key, PREF_MACHINE_ETH_INTERFACE_DEVICES.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_MACHINE_ETH_INTERFACE_DEVICES)>());
    parameters.insert(PREF_GUI_LANGUAGE.key, settings.value(PREF_GUI_LANGUAGE.key, PREF_GUI_LANGUAGE.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_GUI_LANGUAGE)>());
    parameters.insert(PREF_GUI_UNIT_MEASURE.key, settings.value(PREF_GUI_UNIT_MEASURE.key, PREF_GUI_UNIT_MEASURE.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_GUI_UNIT_MEASURE)>());
    parameters.insert(PREF_GUI_SPLASH_ENABLE.key, settings.value(PREF_GUI_SPLASH_ENABLE.key, PREF_GUI_SPLASH_ENABLE.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_GUI_SPLASH_ENABLE)>());

    parameters.insert(PREF_AXISX_STEPPERUNIT.key, settings.value(PREF_AXISX_STEPPERUNIT.key, PREF_AXISX_STEPPERUNIT.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_STEPPERUNIT)>());
    parameters.insert(PREF_AXISX_BASEOFFSET.key, settings.value(PREF_AXISX_BASEOFFSET.key, PREF_AXISX_BASEOFFSET.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_BASEOFFSET)>());
    parameters.insert(PREF_AXISX_FEEDBACK.key, settings.value(PREF_AXISX_FEEDBACK.key, PREF_AXISX_FEEDBACK.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_FEEDBACK)>());
    parameters.insert(PREF_AXISX_KIND.key, settings.value(PREF_AXISX_KIND.key, PREF_AXISX_KIND.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_KIND)>());
    parameters.insert(PREF_AXISX_MAXPOS.key, settings.value(PREF_AXISX_MAXPOS.key, PREF_AXISX_MAXPOS.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_MAXPOS)>());
    parameters.insert(PREF_AXISX_MINPOS.key, settings.value(PREF_AXISX_MINPOS.key, PREF_AXISX_MINPOS.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_MINPOS)>());
    parameters.insert(PREF_AXISX_SAFETYPOSITION.key, settings.value(PREF_AXISX_SAFETYPOSITION.key, PREF_AXISX_SAFETYPOSITION.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_SAFETYPOSITION)>());
    parameters.insert(PREF_AXISX_STEPSPEED.key, settings.value(PREF_AXISX_STEPSPEED.key, PREF_AXISX_STEPSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_STEPSPEED)>());
    parameters.insert(PREF_AXISX_STEPACC.key, settings.value(PREF_AXISX_STEPACC.key, PREF_AXISX_STEPACC.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_STEPACC)>());
    parameters.insert(PREF_AXISX_ACC.key, settings.value(PREF_AXISX_ACC.key, PREF_AXISX_ACC.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_ACC)>());
    parameters.insert(PREF_AXISX_SPEED.key, settings.value(PREF_AXISX_SPEED.key, PREF_AXISX_SPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_SPEED)>());
    parameters.insert(PREF_AXISX_ZEROACC.key, settings.value(PREF_AXISX_ZEROACC.key, PREF_AXISX_ZEROACC.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_ZEROACC)>());
    parameters.insert(PREF_AXISX_ZEROSPEED.key, settings.value(PREF_AXISX_ZEROSPEED.key, PREF_AXISX_ZEROSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISX_ZEROSPEED)>());

    parameters.insert(PREF_AXISZ_ACC.key, settings.value(PREF_AXISZ_ACC.key, PREF_AXISZ_ACC.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_ACC)>());
    parameters.insert(PREF_AXISZ_COLISIONREF.key, settings.value(PREF_AXISZ_COLISIONREF.key, PREF_AXISZ_COLISIONREF.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_COLISIONREF)>());
    parameters.insert(PREF_AXISZ_MANUALADJ.key, settings.value(PREF_AXISZ_MANUALADJ.key, PREF_AXISZ_MANUALADJ.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_MANUALADJ)>());
    parameters.insert(PREF_AXISZ_MAXPOS.key, settings.value(PREF_AXISZ_MAXPOS.key, PREF_AXISZ_MAXPOS.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_MAXPOS)>());
    parameters.insert(PREF_AXISZ_MINPOS.key, settings.value(PREF_AXISZ_MINPOS.key, PREF_AXISZ_MINPOS.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_MINPOS)>());
    parameters.insert(PREF_AXISZ_PRESENT.key, settings.value(PREF_AXISZ_PRESENT.key, PREF_AXISZ_PRESENT.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_PRESENT)>());
    parameters.insert(PREF_AXISZ_SAFETYPOSITION.key, settings.value(PREF_AXISZ_SAFETYPOSITION.key, PREF_AXISZ_SAFETYPOSITION.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_SAFETYPOSITION)>());
    parameters.insert(PREF_AXISZ_SPEED.key, settings.value(PREF_AXISZ_SPEED.key, PREF_AXISZ_SPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_SPEED)>());
    parameters.insert(PREF_AXISZ_STEPADJ.key, settings.value(PREF_AXISZ_STEPADJ.key, PREF_AXISZ_STEPADJ.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_STEPADJ)>());
    parameters.insert(PREF_AXISZ_STEPPERUNIT.key, settings.value(PREF_AXISZ_STEPPERUNIT.key, PREF_AXISZ_STEPPERUNIT.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_STEPPERUNIT)>());
    parameters.insert(PREF_AXISZ_ZEROACC.key, settings.value(PREF_AXISZ_ZEROACC.key, PREF_AXISZ_ZEROACC.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_ZEROACC)>());
    parameters.insert(PREF_AXISZ_ZEROSPEED.key, settings.value(PREF_AXISZ_ZEROSPEED.key, PREF_AXISZ_ZEROSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_AXISZ_ZEROSPEED)>());

    parameters.insert(PREF_CYLINDER_ACCMAX.key, settings.value(PREF_CYLINDER_ACCMAX.key, PREF_CYLINDER_ACCMAX.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_ACCMAX)>());
    parameters.insert(PREF_CYLINDER_ACCMIN.key, settings.value(PREF_CYLINDER_ACCMIN.key, PREF_CYLINDER_ACCMIN.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_ACCMIN)>());
    parameters.insert(PREF_CYLINDER_HEAVYSELECTOR.key, settings.value(PREF_CYLINDER_HEAVYSELECTOR.key, PREF_CYLINDER_HEAVYSELECTOR.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_HEAVYSELECTOR)>());
    parameters.insert(PREF_CYLINDER_MAXDIAMETER.key, settings.value(PREF_CYLINDER_MAXDIAMETER.key, PREF_CYLINDER_MAXDIAMETER.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_MAXDIAMETER)>());
    parameters.insert(PREF_CYLINDER_MAXLENGTH.key, settings.value(PREF_CYLINDER_MAXLENGTH.key, PREF_CYLINDER_MAXLENGTH.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_MAXLENGTH)>());
    parameters.insert(PREF_CYLINDER_MAXSPEED.key, settings.value(PREF_CYLINDER_MAXSPEED.key, PREF_CYLINDER_MAXSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_MAXSPEED)>());
    parameters.insert(PREF_CYLINDER_MINDIAMETER.key, settings.value(PREF_CYLINDER_MINDIAMETER.key, PREF_CYLINDER_MINDIAMETER.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_MINDIAMETER)>());
    parameters.insert(PREF_CYLINDER_MINLENGTH.key, settings.value(PREF_CYLINDER_MINLENGTH.key, PREF_CYLINDER_MINLENGTH.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_MINLENGTH)>());
    parameters.insert(PREF_CYLINDER_MINSPEED.key, settings.value(PREF_CYLINDER_MINSPEED.key, PREF_CYLINDER_MINSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_MINSPEED)>());
    parameters.insert(PREF_CYLINDER_NUMOFENCODERS.key, settings.value(PREF_CYLINDER_NUMOFENCODERS.key, PREF_CYLINDER_NUMOFENCODERS.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_NUMOFENCODERS)>());
    parameters.insert(PREF_CYLINDER_STEPPERUNIT.key, settings.value(PREF_CYLINDER_STEPPERUNIT.key, PREF_CYLINDER_STEPPERUNIT.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_STEPPERUNIT)>());
    parameters.insert(PREF_CYLINDER_ZEROACC.key, settings.value(PREF_CYLINDER_ZEROACC.key, PREF_CYLINDER_ZEROACC.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_ZEROACC)>());
    parameters.insert(PREF_CYLINDER_ZEROSPEED.key, settings.value(PREF_CYLINDER_ZEROSPEED.key, PREF_CYLINDER_ZEROSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(PREF_CYLINDER_ZEROSPEED)>());

}

void MachineParameters::flush() const {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    for (const QString& key: parameters.keys())
        settings.setValue(key, parameters.value(key));

}
