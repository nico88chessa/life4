#ifndef MACHINEPARAMETERS_HPP
#define MACHINEPARAMETERS_HPP

#include <QString>
#include <QVariant>
#include <QMap>
#include <QSettings>
#include <configure.h>

namespace life {

namespace machineparameters {

constexpr static char PREF_MACHINE_ETH_INTERFACE_LAN[] = "Machine/EthInterfaceLan";
constexpr static char PREF_MACHINE_ETH_INTERFACE_LAN_DFLT[] = "eth0";

constexpr static char PREF_MACHINE_ETH_INTERFACE_DEVICES[] = "Machine/EthInterfaceDevices";
constexpr static char PREF_MACHINE_ETH_INTERFACE_DEVICES_DFLT[] = "eth1";

constexpr static char PREF_GUI_LANGUAGE[] = "GUI/Language";
constexpr static char PREF_GUI_LANGUAGE_DFLT[] = "IT";

constexpr static char PREF_GUI_UNIT_MEASURE[] = "GUI/UnitMeasure";
constexpr static char PREF_GUI_UNIT_MEASURE_DFLT[] = "mm";

constexpr static char PREF_GUI_SPLASH_ENABLE[] = "GUI/SplashEnable";
constexpr static char PREF_GUI_SPLASH_ENABLE_DFLT[] = "true";

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

    QVariant getValue(const QString& key) const;

    void setValue(const QString& key, const QVariant& value);

    void load();

    void flush() const;

};

}

#endif // MACHINEPARAMETERS_HPP
