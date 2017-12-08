#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <QString>

namespace life {


static constexpr char SIMPLE_IO_NAME[] = "Name";
static constexpr char SIMPLE_IO_CHANNEL[] = "Channel";
static constexpr char SIMPLE_IO_DEVICE[] = "Device";
static constexpr char SIMPLE_IO_DIRECTION[] = "Direction";
static constexpr char SIMPLE_IO_ISALARM[] = "IsAlarm";
static constexpr char SIMPLE_IO_ALARMTEXT[] = "AlarmText";

static constexpr char CN_NAME[] = "CN";
static constexpr char PLC_NAME[] = "PLC";

static constexpr char INPUT_NAME[] = "INPUT";
static constexpr char OUTPUT_NAME[] = "OUTPUT";

static constexpr char UNDEFINED_NAME[] = "UNDEFINED";

enum device_type { DEVICE_UNDEFINED, CN, PLC };
enum direction_type { DIRECTION_UNDEFINED, INPUT, OUTPUT };


inline QString deviceType2Str(device_type t) {
    switch (t) {
    case CN: return CN_NAME; break;
    case PLC: return PLC_NAME; break;
    default: return UNDEFINED_NAME; break;
    }
}

inline device_type str2DeviceType(const QString& s) {
    if (s.compare(CN_NAME, Qt::CaseInsensitive) == 0)
        return CN;
    else if (s.compare(PLC_NAME, Qt::CaseInsensitive) == 0)
        return PLC;
    return DEVICE_UNDEFINED;
}


inline QString directionType2Str(direction_type t) {
    switch (t) {
    case INPUT: return INPUT_NAME; break;
    case OUTPUT: return OUTPUT_NAME; break;
    default: return UNDEFINED_NAME;  break;
    }
}

inline direction_type str2DirectionType(const QString& s) {
    if (s.compare(INPUT_NAME, Qt::CaseInsensitive) == 0)
        return INPUT;
    else if (s.compare(OUTPUT_NAME, Qt::CaseInsensitive) == 0)
        return OUTPUT;
    return DIRECTION_UNDEFINED;
}


struct SimpleIO {
    SimpleIO() { }
    SimpleIO(const QString& n, unsigned int c, device_type d, direction_type dt, bool ia, const QString& at)
        : name(n), channel(c), device(d), direction(dt), isAlarm(ia), alarmText(at) { }

    virtual ~SimpleIO() { }

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
};

template <>
struct isSimpleIO<SimpleIO> {
    static constexpr bool value = true;
};


}

#endif // COMMON_HPP
