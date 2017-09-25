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
struct MachineParameterTraits {
    static const bool value = false;
    using type = void;
};

template <typename T>
struct MachineParameterTraits<MachineParameter<T> > {
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
    QVariant getValue(const machineparameters::MachineParameter<T>& parameter) const {
        return parameters.value(parameter.key);
    }

    template <typename T>
    T getValue2(const machineparameters::MachineParameter<T>& parameter) const {
        return static_cast<QVariant>(parameters.value(parameter.key)).value<T>();
    }

    template <typename T>
    void setValue(const machineparameters::MachineParameter<T>& parameter, const T& value) {
        parameters.insert(parameter.key, value);
    }

    void load();

    void flush() const;

};

}



#endif // MACHINEPARAMETERS_HPP
