#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <iostream>
#include <array>
#include <QString>
#include <QMetaType>
#include <utils/Utility.hpp>


namespace life {

namespace machineparameters {

#define ENUM_AXISX_FEEDBACK(ITEM) \
    ITEM(linear), \
    ITEM(brushless)
DECL_ENUMS(AxisXFeedback, ENUM_AXISX_FEEDBACK)


#define ENUM_AXISX_KIND(ITEM) \
    ITEM(linear), \
    ITEM(normal)
DECL_ENUMS(AxisXKind, ENUM_AXISX_KIND)


#define ENUM_GUI_UNIT_MEASURE(ITEM) \
    ITEM(mm), \
    ITEM(dpi)
DECL_ENUMS(GuiUnitMeasure, ENUM_GUI_UNIT_MEASURE)


enum struct MachineParameterOption {
    IP_ADDRESS
};


template <typename T>
struct MachineParameter {
    const QString key;
    const T defaultValue;
    const std::initializer_list<MachineParameterOption> options;
    const QString unitMeasure;
};

template <class T>
struct isMachineParameter {
    static const bool value = false;
    static const int optionSize = 0;
    using type = void;
};

template <typename T>
struct isMachineParameter<MachineParameter<T> > {
    static const bool value = true;
    using type = T;
};

#define MACHINE_PARAMETER_TYPE(mp) std::remove_const<decltype(mp.defaultValue)>::type

#define DECL_MACHINE_PARAMETER(NAME, TYPE, KEY, DFLT_VALUE, OPTIONS, UNIT_MEASURE) \
    static const MachineParameter<TYPE> NAME = { KEY, DFLT_VALUE, {OPTIONS}, UNIT_MEASURE}; \

#define DECL_MACHINE_PARAMETER_NOOPTIONS(NAME, TYPE, KEY, DFLT_VALUE, UNIT_MEASURE) \
    DECL_MACHINE_PARAMETER(NAME, TYPE, KEY, DFLT_VALUE, , UNIT_MEASURE)


DECL_MACHINE_PARAMETER_NOOPTIONS(MACHINE_ETH_INTERFACE_LAN, QString, "Machine/EthInterfaceLan", "eth0", "")
DECL_MACHINE_PARAMETER_NOOPTIONS(MACHINE_ETH_INTERFACE_DEVICES, QString, "Machine/EthInterfaceDevices", "eth1", "")
DECL_MACHINE_PARAMETER_NOOPTIONS(GUI_LANGUAGE, QString, "GUI/Language", "IT", "")
DECL_MACHINE_PARAMETER_NOOPTIONS(GUI_UNIT_MEASURE, GuiUnitMeasure, "GUI/UnitMeasure", GuiUnitMeasure::mm, "")
DECL_MACHINE_PARAMETER_NOOPTIONS(GUI_SPLASH_ENABLE,  bool, "GUI/SplashEnable", true, "")
DECL_MACHINE_PARAMETER(CN_IP, QString, "CN/IP", 0, MachineParameterOption::IP_ADDRESS, "")

DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_STEPPERUNIT, quint32, "AxisX/StepPerUnit", 1000, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_ZEROACC, quint32, "AxisX/ZeroAcc", 100, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_ZEROSPEED, quint32, "AxisX/ZeroSpeed", 20, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_ACC, quint32, "AxisX/Acc", 100, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_SPEED, quint32, "AxisX/Speed", 100, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_STEPSPEED, quint32, "AxisX/StepSpeed", 20, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_STEPACC, quint32, "AxisX/StepAcc", 200, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_MINPOS, quint32, "AxisX/MinPos", 0, "mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_MAXPOS, quint32, "AxisX/MaxPos", 1440, "mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_BASEOFFSET, quint32, "AxisX/BaseOffset", 0, "mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_FEEDBACK, AxisXFeedback, "AxisX/Feedback", AxisXFeedback::linear, "")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_KIND, AxisXKind, "AxisX/Kind", AxisXKind::linear, "")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISX_SAFETYPOSITION, quint32, "AxisX/SafetyPosition", 160, "mm")

DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_STEPPERUNIT, quint32, "AxisZ/StepPerUnit", 1000, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_ZEROACC, quint32, "AxisZ/ZeroAcc", 10, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_ZEROSPEED, quint32, "AxisZ/ZeroSpeed", 5, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_ACC, quint32, "AxisZ/Acc", 40, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_SPEED, quint32, "AxisZ/Speed", 20, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_STEPADJ, quint32, "AxisZ/StepAdj", 1, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_MINPOS, quint32, "AxisZ/MinPos", 0, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_MAXPOS, quint32, "AxisZ/MaxPos", 200, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_COLLISIONREF, quint32, "AxisZ/CollisionRef", 200, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_MANUALADJ, bool, "AxisZ/ManualAdj", false, "")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_SAFETYPOSITION, quint32, "AxisZ/SafetyPosition", 20, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(AXISZ_PRESENT, bool, "AxisZ/Present", true, "")

DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_STEPPERUNIT, quint32, "Cylinder/StepPerUnit", 25000, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_ZEROSPEED, quint32, "Cylinder/ZeroSpeed", 2, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_ZEROACC, quint32, "Cylinder/ZeroAcc", 10, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_ACCMIN, quint32, "Cylinder/AccMin", 30, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_ACCMAX, quint32, "Cylinder/AccMax", 30, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_HEAVYSELECTOR, bool, "Cylinder/HeavySelector", false, "")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_MINDIAMETER, quint32, "Cylinder/MinDiameter", 10, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_MAXDIAMETER, quint32, "Cylinder/MaxDiameter", 250, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_MINLENGTH, quint32, "Cylinder/MinLength", 10, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_MAXLENGTH, quint32, "Cylinder/MaxLength", 1000, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_MINSPEED, quint32, "Cylinder/MinSpeed", 10, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_MAXSPEED, quint32, "Cylinder/MaxSpeed", 1200, "i/mm")
DECL_MACHINE_PARAMETER_NOOPTIONS(CYLINDER_NUMOFENCODERS, quint32, "Cylinder/NumOfEncoders", 1, "")


}

}

Q_DECLARE_METATYPE(life::machineparameters::AxisXFeedback)
Q_DECLARE_METATYPE(life::machineparameters::AxisXKind)
Q_DECLARE_METATYPE(life::machineparameters::GuiUnitMeasure)

#endif // PARAMETERS_HPP
