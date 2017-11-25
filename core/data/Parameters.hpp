#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <QString>

namespace life {

namespace machineparameters {


template <typename T>
struct MachineParameter {
    const QString key;
    const T defaultValue;
};

template <class T>
struct isMachineParameter {
    static const bool value = false;
    using type = void;
};

template <typename T>
struct isMachineParameter<MachineParameter<T> > {
    static const bool value = true;
    using type = T;
};


#define MACHINE_PARAMETER_TYPE(mp) std::remove_const<decltype(mp.defaultValue)>::type

#define DECL_MACHINE_PARAMETER(NAME, TYPE, KEY, DFLT_VALUE) \
    static const MachineParameter<TYPE> NAME = { KEY, DFLT_VALUE };


DECL_MACHINE_PARAMETER(MACHINE_ETH_INTERFACE_LAN, QString, "Machine/EthInterfaceLan", "eth0")
DECL_MACHINE_PARAMETER(MACHINE_ETH_INTERFACE_DEVICES, QString, "Machine/EthInterfaceDevices", "eth1")
DECL_MACHINE_PARAMETER(GUI_LANGUAGE, QString, "GUI/Language", "IT")
DECL_MACHINE_PARAMETER(GUI_UNIT_MEASURE, QString, "GUI/UnitMeasure", "mm")
DECL_MACHINE_PARAMETER(GUI_SPLASH_ENABLE, bool, "GUI/SplashEnable", true)

DECL_MACHINE_PARAMETER(AXISX_STEPPERUNIT, quint32, "AxisX/StepPerUnit", 1000)
DECL_MACHINE_PARAMETER(AXISX_ZEROACC, quint32, "AxisX/ZeroAcc", 100)
DECL_MACHINE_PARAMETER(AXISX_ZEROSPEED, quint32, "AxisX/ZeroSpeed", 20)
DECL_MACHINE_PARAMETER(AXISX_ACC, quint32, "AxisX/Acc", 100)
DECL_MACHINE_PARAMETER(AXISX_SPEED, quint32, "AxisX/Speed", 100)
DECL_MACHINE_PARAMETER(AXISX_STEPSPEED, quint32, "AxisX/StepSpeed", 20)
DECL_MACHINE_PARAMETER(AXISX_STEPACC, quint32, "AxisX/StepAcc", 200)
DECL_MACHINE_PARAMETER(AXISX_MINPOS, quint32, "AxisX/MinPos", 0)
DECL_MACHINE_PARAMETER(AXISX_MAXPOS, quint32, "AxisX/MaxPos", 1440)
DECL_MACHINE_PARAMETER(AXISX_BASEOFFSET, double, "AxisX/BaseOffset", 0)
DECL_MACHINE_PARAMETER(AXISX_FEEDBACK, QString, "AxisX/Feedback", "linear")
DECL_MACHINE_PARAMETER(AXISX_KIND, QString, "AxisX/Kind", "linear")
DECL_MACHINE_PARAMETER(AXISX_SAFETYPOSITION, double, "AxisX/SafetyPosition", 160)

DECL_MACHINE_PARAMETER(AXISZ_STEPPERUNIT, quint32, "AxisZ/StepPerUnit", 1000)
DECL_MACHINE_PARAMETER(AXISZ_ZEROACC, quint32, "AxisZ/ZeroAcc", 10)
DECL_MACHINE_PARAMETER(AXISZ_ZEROSPEED, quint32, "AxisZ/ZeroSpeed", 5)
DECL_MACHINE_PARAMETER(AXISZ_ACC, quint32, "AxisZ/Acc", 40)
DECL_MACHINE_PARAMETER(AXISZ_SPEED, quint32, "AxisZ/Speed", 20)
DECL_MACHINE_PARAMETER(AXISZ_STEPADJ, quint32, "AxisZ/StepAdj", 1)
DECL_MACHINE_PARAMETER(AXISZ_MINPOS, quint32, "AxisZ/MinPos", 0)
DECL_MACHINE_PARAMETER(AXISZ_MAXPOS, quint32, "AxisZ/MaxPos", 200)
DECL_MACHINE_PARAMETER(AXISZ_COLISIONREF, quint32, "AxisZ/ColisionRef", 200)
DECL_MACHINE_PARAMETER(AXISZ_MANUALADJ, bool, "AxisZ/ManualAdj", false)
DECL_MACHINE_PARAMETER(AXISZ_SAFETYPOSITION, quint32, "AxisZ/SafetyPosition", 20)
DECL_MACHINE_PARAMETER(AXISZ_PRESENT, bool, "AxisZ/Present", true)

DECL_MACHINE_PARAMETER(CYLINDER_STEPPERUNIT, quint32, "Cylinder/StepPerUnit", 25000)
DECL_MACHINE_PARAMETER(CYLINDER_ZEROSPEED, quint32, "Cylinder/ZeroSpeed", 2)
DECL_MACHINE_PARAMETER(CYLINDER_ZEROACC, quint32, "Cylinder/ZeroAcc", 10)
DECL_MACHINE_PARAMETER(CYLINDER_ACCMIN, quint32, "Cylinder/AccMin", 30)
DECL_MACHINE_PARAMETER(CYLINDER_ACCMAX, quint32, "Cylinder/AccMax", 30)
DECL_MACHINE_PARAMETER(CYLINDER_HEAVYSELECTOR, bool, "Cylinder/HeavySelector", false)
DECL_MACHINE_PARAMETER(CYLINDER_MINDIAMETER, quint32, "Cylinder/MinDiameter", 10)
DECL_MACHINE_PARAMETER(CYLINDER_MAXDIAMETER, quint32, "Cylinder/MaxDiameter", 250)
DECL_MACHINE_PARAMETER(CYLINDER_MINLENGTH, quint32, "Cylinder/MinLength", 10)
DECL_MACHINE_PARAMETER(CYLINDER_MAXLENGTH, quint32, "Cylinder/MaxLength", 1000)
DECL_MACHINE_PARAMETER(CYLINDER_MINSPEED, quint32, "Cylinder/MinSpeed", 10)
DECL_MACHINE_PARAMETER(CYLINDER_MAXSPEED, quint32, "Cylinder/MaxSpeed", 1200)
DECL_MACHINE_PARAMETER(CYLINDER_NUMOFENCODERS, quint32, "Cylinder/NumOfEncoders", 1)


}

}

#endif // PARAMETERS_HPP
