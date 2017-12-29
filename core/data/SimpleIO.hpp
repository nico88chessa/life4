#ifndef COMMON_HPP
#define COMMON_HPP

#include <utils/Utility.hpp>
#include <iostream>
#include <QString>
#include <QMetaType>

namespace life {


static constexpr char SIMPLE_IO_NAME[] = "Name";
static constexpr char SIMPLE_IO_CHANNEL[] = "Channel";
static constexpr char SIMPLE_IO_DEVICE[] = "Device";
static constexpr char SIMPLE_IO_DIRECTION[] = "Direction";
static constexpr char SIMPLE_IO_ISALARM[] = "IsAlarm";
static constexpr char SIMPLE_IO_ALARMTEXT[] = "AlarmText";

#define ENUM_DEVICE_KIND(ITEM) \
    ITEM(CN), \
    ITEM(PLC)
DECL_ENUMS(DeviceKind, ENUM_DEVICE_KIND)

#define ENUM_DIRECTION_TYPE(ITEM) \
    ITEM(Input), \
    ITEM(Output)
DECL_ENUMS(DirectionType, ENUM_DIRECTION_TYPE)


struct SimpleIO {
    SimpleIO() { }
    SimpleIO(const QString& n, int c, DeviceKind d, DirectionType dt, bool ia, const QString& at)
        : name(n), channel(c), device(d), direction(dt), isAlarm(ia), alarmText(at) { }

    virtual ~SimpleIO() { }

    QString name;
    int channel;
    DeviceKind device;
    DirectionType direction;
    bool isAlarm;
    QString alarmText;
};

template <typename T>
struct isSimpleIO {
    static constexpr bool value = false;
};

template <>
struct isSimpleIO<SimpleIO> {
    static constexpr bool value = true;
};


}

Q_DECLARE_METATYPE(life::DeviceKind)
Q_DECLARE_METATYPE(life::DirectionType)

#endif // COMMON_HPP
