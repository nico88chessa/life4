#ifndef MACHINEPARAMETERS_HPP
#define MACHINEPARAMETERS_HPP

#include <iostream>
#include <QString>
#include <QVariant>
#include <QMap>
#include <QSettings>
#include <configure.h>

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


DECL_MACHINE_PARAMETER(PREF_MACHINE_ETH_INTERFACE_LAN, QString, "Machine/EthInterfaceLan", "eth0")
DECL_MACHINE_PARAMETER(PREF_MACHINE_ETH_INTERFACE_DEVICES, QString, "Machine/EthInterfaceDevices", "eth1")
DECL_MACHINE_PARAMETER(PREF_GUI_LANGUAGE, QString, "GUI/Language", "IT")
DECL_MACHINE_PARAMETER(PREF_GUI_UNIT_MEASURE, QString, "GUI/UnitMeasure", "mm")
DECL_MACHINE_PARAMETER(PREF_GUI_SPLASH_ENABLE, bool, "GUI/SplashEnable", true)

DECL_MACHINE_PARAMETER(PREF_AXISX_STEPPERUNIT, quint32, "AxisX/StepPerUnit", 1000)
DECL_MACHINE_PARAMETER(PREF_AXISX_BASEOFFSET, double, "AxisX/BaseOffset", 0)
DECL_MACHINE_PARAMETER(PREF_AXISX_FEEDBACK, QString, "AxisX/Feedback", "linear")
DECL_MACHINE_PARAMETER(PREF_AXISX_KIND, QString, "AxisX/Kind", "linear")
DECL_MACHINE_PARAMETER(PREF_AXISX_MAXPOS, quint32, "AxisX/MaxPos", 1440)
DECL_MACHINE_PARAMETER(PREF_AXISX_MINPOS, quint32, "AxisX/MinPos", 0)
DECL_MACHINE_PARAMETER(PREF_AXISX_SAFETYPOSITION, double, "AxisX/SafetyPosition", 160)
DECL_MACHINE_PARAMETER(PREF_AXISX_STEPSPEED, quint32, "AxisX/StepSpeed", 20)
DECL_MACHINE_PARAMETER(PREF_AXISX_STEPACC, quint32, "AxisX/StepAcc", 200)
DECL_MACHINE_PARAMETER(PREF_AXISX_ACC, quint32, "AxisX/Acc", 100)
DECL_MACHINE_PARAMETER(PREF_AXISX_SPEED, quint32, "AxisX/Speed", 100)
DECL_MACHINE_PARAMETER(PREF_AXISX_ZEROACC, quint32, "AxisX/ZeroAcc", 100)
DECL_MACHINE_PARAMETER(PREF_AXISX_ZEROSPEED, quint32, "AxisX/ZeroSpeed", 20)

DECL_MACHINE_PARAMETER(PREF_AXISZ_ACC, quint32, "AxisZ/Acc", 40)
DECL_MACHINE_PARAMETER(PREF_AXISZ_COLISIONREF, quint32, "AxisZ/ColisionRef", 200)
DECL_MACHINE_PARAMETER(PREF_AXISZ_MANUALADJ, bool, "AxisZ/ManualAdj", false)
DECL_MACHINE_PARAMETER(PREF_AXISZ_MAXPOS, quint32, "AxisZ/MaxPos", 200)
DECL_MACHINE_PARAMETER(PREF_AXISZ_MINPOS, quint32, "AxisZ/MinPos", 0)
DECL_MACHINE_PARAMETER(PREF_AXISZ_PRESENT, bool, "AxisZ/Present", true)
DECL_MACHINE_PARAMETER(PREF_AXISZ_SAFETYPOSITION, quint32, "AxisZ/SafetyPosition", 20)
DECL_MACHINE_PARAMETER(PREF_AXISZ_SPEED, quint32, "AxisZ/Speed", 20)
DECL_MACHINE_PARAMETER(PREF_AXISZ_STEPADJ, quint32, "AxisZ/StepAdj", 1)
DECL_MACHINE_PARAMETER(PREF_AXISZ_STEPPERUNIT, quint32, "AxisZ/StepPerUnit", 1000)
DECL_MACHINE_PARAMETER(PREF_AXISZ_ZEROACC, quint32, "AxisZ/ZeroAcc", 10)
DECL_MACHINE_PARAMETER(PREF_AXISZ_ZEROSPEED, quint32, "AxisZ/ZeroSpeed", 5)

DECL_MACHINE_PARAMETER(PREF_CYLINDER_ACCMAX, quint32, "Cylinder/AccMax", 30)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_ACCMIN, quint32, "Cylinder/AccMin", 30)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_HEAVYSELECTOR, bool, "Cylinder/HeavySelector", false)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_MAXDIAMETER, quint32, "Cylinder/MaxDiameter", 250)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_MAXLENGTH, quint32, "Cylinder/MaxLength", 1000)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_MAXSPEED, quint32, "Cylinder/MaxSpeed", 1200)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_MINDIAMETER, quint32, "Cylinder/MinDiameter", 10)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_MINLENGTH, quint32, "Cylinder/MinLength", 10)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_MINSPEED, quint32, "Cylinder/MinSpeed", 10)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_NUMOFENCODERS, quint32, "Cylinder/NumOfEncoders", 1)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_STEPPERUNIT, quint32, "Cylinder/StepPerUnit", 25000)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_ZEROACC, quint32, "Cylinder/ZeroAcc", 10)
DECL_MACHINE_PARAMETER(PREF_CYLINDER_ZEROSPEED, quint32, "Cylinder/ZeroSpeed", 2)

}

class MachineParameters {
public:
    using Ptr = MachineParameters *;
    using ConstPtr = const MachineParameters *;

private:
    QMap<QString, QVariant> parameters;

public:
    MachineParameters();

public:

    template <typename T>
    T getValue(const machineparameters::MachineParameter<T>& parameter) const {
        return static_cast<QVariant>(parameters.value(parameter.key)).value<T>();
    }

    template <typename T>
    void setValue(const machineparameters::MachineParameter<T>& parameter, const T& value) {
        parameters.insert(parameter.key, value);
    }

    const QMap<QString, QVariant>& getMap() const { return parameters; }

    int size() const { return parameters.size(); }

    void load();

    void flush() const;

};

}



#endif // MACHINEPARAMETERS_HPP
