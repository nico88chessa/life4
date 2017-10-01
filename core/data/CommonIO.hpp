#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <QString>

namespace life {

enum device_type { DEVICE_UNDEFINED, CN, PLC };
enum direction_type { DIRECTION_UNDEFINED, INPUT, OUTPUT };

inline QString deviceType2Str(device_type t) {
    switch (t) {
    case CN: return "CN"; break;
    case PLC: return "PLC"; break;
    default: return "UNDEFINED"; break;
    }
}

inline device_type str2DeviceType(const QString& s) {
    if (s.compare("CN", Qt::CaseInsensitive) == 0)
        return CN;
    else if (s.compare("PLC", Qt::CaseInsensitive) == 0)
        return PLC;
    return DEVICE_UNDEFINED;
}

inline QString directionType2Str(direction_type t) {
    switch (t) {
    case INPUT: return "INPUT"; break;
    case OUTPUT: return "OUTPUT"; break;
    default: return "UNDEFINED";  break;
    }
}

inline direction_type str2DirectionType(const QString& s) {
    if (s.compare("INPUT", Qt::CaseInsensitive) == 0)
        return INPUT;
    else if (s.compare("OUTPUT", Qt::CaseInsensitive) == 0)
        return OUTPUT;
    return DIRECTION_UNDEFINED;
}

template <typename T>
struct SimpleIO {
    using type = T;

    SimpleIO() { }
    SimpleIO(const QString& n, unsigned int c, device_type d, direction_type dt, bool ia, const QString& at)
        : name(n), channel(c), device(d), direction(dt), isAlarm(ia), alarmText(at) { }

    QString name;
    unsigned int channel;
    device_type device;
    direction_type direction;
    bool isAlarm;
    QString alarmText;
};

template <typename T>
struct isSimpleIO {
    static constexpr bool value = false;
    using type = void;
};

template <typename T>
struct isSimpleIO<SimpleIO<T> > {
    static constexpr bool value = true;
    using type = T;
};

}

#endif // COMMON_HPP
