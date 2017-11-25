#include "ParametersManager.hpp"

using namespace life;
using namespace machineparameters;

ParametersManager::ParametersManager() {
    load();
}

void ParametersManager::load() {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    parameters.insert(MACHINE_ETH_INTERFACE_LAN.key, settings.value(MACHINE_ETH_INTERFACE_LAN.key, MACHINE_ETH_INTERFACE_LAN.defaultValue).value<MACHINE_PARAMETER_TYPE(MACHINE_ETH_INTERFACE_LAN)>());
    parameters.insert(MACHINE_ETH_INTERFACE_DEVICES.key, settings.value(MACHINE_ETH_INTERFACE_DEVICES.key, MACHINE_ETH_INTERFACE_DEVICES.defaultValue).value<MACHINE_PARAMETER_TYPE(MACHINE_ETH_INTERFACE_DEVICES)>());
    parameters.insert(GUI_LANGUAGE.key, settings.value(GUI_LANGUAGE.key, GUI_LANGUAGE.defaultValue).value<MACHINE_PARAMETER_TYPE(GUI_LANGUAGE)>());
    parameters.insert(GUI_UNIT_MEASURE.key, settings.value(GUI_UNIT_MEASURE.key, GUI_UNIT_MEASURE.defaultValue).value<MACHINE_PARAMETER_TYPE(GUI_UNIT_MEASURE)>());
    parameters.insert(GUI_SPLASH_ENABLE.key, settings.value(GUI_SPLASH_ENABLE.key, GUI_SPLASH_ENABLE.defaultValue).value<MACHINE_PARAMETER_TYPE(GUI_SPLASH_ENABLE)>());

    parameters.insert(AXISX_STEPPERUNIT.key, settings.value(AXISX_STEPPERUNIT.key, AXISX_STEPPERUNIT.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_STEPPERUNIT)>());
    parameters.insert(AXISX_ZEROACC.key, settings.value(AXISX_ZEROACC.key, AXISX_ZEROACC.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_ZEROACC)>());
    parameters.insert(AXISX_ZEROSPEED.key, settings.value(AXISX_ZEROSPEED.key, AXISX_ZEROSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_ZEROSPEED)>());
    parameters.insert(AXISX_ACC.key, settings.value(AXISX_ACC.key, AXISX_ACC.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_ACC)>());
    parameters.insert(AXISX_SPEED.key, settings.value(AXISX_SPEED.key, AXISX_SPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_SPEED)>());
    parameters.insert(AXISX_STEPSPEED.key, settings.value(AXISX_STEPSPEED.key, AXISX_STEPSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_STEPSPEED)>());
    parameters.insert(AXISX_STEPACC.key, settings.value(AXISX_STEPACC.key, AXISX_STEPACC.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_STEPACC)>());
    parameters.insert(AXISX_MINPOS.key, settings.value(AXISX_MINPOS.key, AXISX_MINPOS.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_MINPOS)>());
    parameters.insert(AXISX_MAXPOS.key, settings.value(AXISX_MAXPOS.key, AXISX_MAXPOS.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_MAXPOS)>());
    parameters.insert(AXISX_BASEOFFSET.key, settings.value(AXISX_BASEOFFSET.key, AXISX_BASEOFFSET.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_BASEOFFSET)>());
    parameters.insert(AXISX_FEEDBACK.key, settings.value(AXISX_FEEDBACK.key, AXISX_FEEDBACK.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_FEEDBACK)>());
    parameters.insert(AXISX_KIND.key, settings.value(AXISX_KIND.key, AXISX_KIND.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_KIND)>());
    parameters.insert(AXISX_SAFETYPOSITION.key, settings.value(AXISX_SAFETYPOSITION.key, AXISX_SAFETYPOSITION.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISX_SAFETYPOSITION)>());

    parameters.insert(AXISZ_STEPPERUNIT.key, settings.value(AXISZ_STEPPERUNIT.key, AXISZ_STEPPERUNIT.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_STEPPERUNIT)>());
    parameters.insert(AXISZ_ZEROACC.key, settings.value(AXISZ_ZEROACC.key, AXISZ_ZEROACC.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_ZEROACC)>());
    parameters.insert(AXISZ_ZEROSPEED.key, settings.value(AXISZ_ZEROSPEED.key, AXISZ_ZEROSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_ZEROSPEED)>());
    parameters.insert(AXISZ_ACC.key, settings.value(AXISZ_ACC.key, AXISZ_ACC.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_ACC)>());
    parameters.insert(AXISZ_SPEED.key, settings.value(AXISZ_SPEED.key, AXISZ_SPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_SPEED)>());
    parameters.insert(AXISZ_STEPADJ.key, settings.value(AXISZ_STEPADJ.key, AXISZ_STEPADJ.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_STEPADJ)>());
    parameters.insert(AXISZ_MINPOS.key, settings.value(AXISZ_MINPOS.key, AXISZ_MINPOS.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_MINPOS)>());
    parameters.insert(AXISZ_MAXPOS.key, settings.value(AXISZ_MAXPOS.key, AXISZ_MAXPOS.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_MAXPOS)>());
    parameters.insert(AXISZ_COLISIONREF.key, settings.value(AXISZ_COLISIONREF.key, AXISZ_COLISIONREF.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_COLISIONREF)>());
    parameters.insert(AXISZ_MANUALADJ.key, settings.value(AXISZ_MANUALADJ.key, AXISZ_MANUALADJ.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_MANUALADJ)>());
    parameters.insert(AXISZ_SAFETYPOSITION.key, settings.value(AXISZ_SAFETYPOSITION.key, AXISZ_SAFETYPOSITION.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_SAFETYPOSITION)>());
    parameters.insert(AXISZ_PRESENT.key, settings.value(AXISZ_PRESENT.key, AXISZ_PRESENT.defaultValue).value<MACHINE_PARAMETER_TYPE(AXISZ_PRESENT)>());

    parameters.insert(CYLINDER_STEPPERUNIT.key, settings.value(CYLINDER_STEPPERUNIT.key, CYLINDER_STEPPERUNIT.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_STEPPERUNIT)>());
    parameters.insert(CYLINDER_ZEROSPEED.key, settings.value(CYLINDER_ZEROSPEED.key, CYLINDER_ZEROSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_ZEROSPEED)>());
    parameters.insert(CYLINDER_ZEROACC.key, settings.value(CYLINDER_ZEROACC.key, CYLINDER_ZEROACC.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_ZEROACC)>());
    parameters.insert(CYLINDER_ACCMIN.key, settings.value(CYLINDER_ACCMIN.key, CYLINDER_ACCMIN.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_ACCMIN)>());
    parameters.insert(CYLINDER_ACCMAX.key, settings.value(CYLINDER_ACCMAX.key, CYLINDER_ACCMAX.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_ACCMAX)>());
    parameters.insert(CYLINDER_HEAVYSELECTOR.key, settings.value(CYLINDER_HEAVYSELECTOR.key, CYLINDER_HEAVYSELECTOR.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_HEAVYSELECTOR)>());
    parameters.insert(CYLINDER_MINDIAMETER.key, settings.value(CYLINDER_MINDIAMETER.key, CYLINDER_MINDIAMETER.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_MINDIAMETER)>());
    parameters.insert(CYLINDER_MAXDIAMETER.key, settings.value(CYLINDER_MAXDIAMETER.key, CYLINDER_MAXDIAMETER.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_MAXDIAMETER)>());
    parameters.insert(CYLINDER_MINLENGTH.key, settings.value(CYLINDER_MINLENGTH.key, CYLINDER_MINLENGTH.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_MINLENGTH)>());
    parameters.insert(CYLINDER_MAXLENGTH.key, settings.value(CYLINDER_MAXLENGTH.key, CYLINDER_MAXLENGTH.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_MAXLENGTH)>());
    parameters.insert(CYLINDER_MINSPEED.key, settings.value(CYLINDER_MINSPEED.key, CYLINDER_MINSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_MINSPEED)>());
    parameters.insert(CYLINDER_MAXSPEED.key, settings.value(CYLINDER_MAXSPEED.key, CYLINDER_MAXSPEED.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_MAXSPEED)>());
    parameters.insert(CYLINDER_NUMOFENCODERS.key, settings.value(CYLINDER_NUMOFENCODERS.key, CYLINDER_NUMOFENCODERS.defaultValue).value<MACHINE_PARAMETER_TYPE(CYLINDER_NUMOFENCODERS)>());

}

void ParametersManager::flush() const {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    for (const QString& key: parameters.keys())
        settings.setValue(key, parameters.value(key));

}
