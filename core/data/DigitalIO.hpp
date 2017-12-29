#ifndef DIGITALIO_HPP
#define DIGITALIO_HPP

#include "SimpleIO.hpp"
#include <global/utils/Utility.hpp>

namespace life {


static constexpr char DIGITAL_ARRAY_NAME[] = "DigitalIO";

static constexpr const char* const DIGITAL_PARAMETER_NAME = SIMPLE_IO_NAME;
static constexpr const char* const DIGITAL_PARAMETER_CHANNEL = SIMPLE_IO_CHANNEL;
static constexpr const char* const DIGITAL_PARAMETER_DEVICE = SIMPLE_IO_DEVICE;
static constexpr const char* const DIGITAL_PARAMETER_DIRECTION = SIMPLE_IO_DIRECTION;
static constexpr const char* const DIGITAL_PARAMETER_ISALARM = SIMPLE_IO_ISALARM;
static constexpr const char* const DIGITAL_PARAMETER_ALARMTEXT = SIMPLE_IO_ALARMTEXT;
static constexpr char DIGITAL_PARAMETER_INVERTLOGIC[] = "InvertLogic";


struct DigitalIO : public SimpleIO {
    DigitalIO() : DigitalIO("", -1, DeviceKind::CN, DirectionType::Input, false, "", false) { }
    DigitalIO(const QString& n, int c, DeviceKind d, DirectionType dt, bool ia, const QString& at, bool il)
        : SimpleIO(n, c, d, dt, ia, at),
          invertLogic(il) { }

    virtual ~DigitalIO() { }

    bool invertLogic;
};

template <typename T>
struct isDigitalIO {
    static constexpr bool value = false;
};

template <>
struct isDigitalIO<DigitalIO> {
    static constexpr bool value = true;
};


#define DECL_STANDARD_DIGITAL_IO(NAME, CHANNEL, DEVICE, DIRECTION, IS_ALARM, ALARM_TEXT, INVERT_LOGIC) \
    static const DigitalIO Digital##NAME = { #NAME, CHANNEL, DEVICE, DIRECTION, IS_ALARM, #ALARM_TEXT, INVERT_LOGIC };

DECL_STANDARD_DIGITAL_IO(Power, 0, DeviceKind::CN, DirectionType::Input, false, , false)
DECL_STANDARD_DIGITAL_IO(Cycle, 1, DeviceKind::CN, DirectionType::Input, false, , false)
DECL_STANDARD_DIGITAL_IO(Enable, 2, DeviceKind::PLC, DirectionType::Output, false, , false)
DECL_STANDARD_DIGITAL_IO(LaserPower, 3, DeviceKind::PLC, DirectionType::Output, false, , false)
DECL_STANDARD_DIGITAL_IO(GreenLamp, 4, DeviceKind::PLC, DirectionType::Output, false, , false)
DECL_STANDARD_DIGITAL_IO(RedLamp, 5, DeviceKind::PLC, DirectionType::Output, false, , false)



}

#endif // DIGITALIO_HPP
