#ifndef ANALOGICTYPES_HPP
#define ANALOGICTYPES_HPP

#include "SimpleIO.hpp"
#include <global/utils/Utility.hpp>
#include <QtGlobal>

namespace life {

static constexpr char ANALOGIC_ARRAY_NAME[] = "AnalogicIO";

static constexpr const char* const ANALOGIC_PARAMETER_NAME = SIMPLE_IO_NAME;
static constexpr const char* const ANALOGIC_PARAMETER_CHANNEL = SIMPLE_IO_CHANNEL;
static constexpr const char* const ANALOGIC_PARAMETER_DEVICE = SIMPLE_IO_DEVICE;
static constexpr const char* const ANALOGIC_PARAMETER_DIRECTION = SIMPLE_IO_DIRECTION;
static constexpr const char* const ANALOGIC_PARAMETER_ISALARM = SIMPLE_IO_ISALARM;
static constexpr const char* const ANALOGIC_PARAMETER_ALARMTEXT = SIMPLE_IO_ALARMTEXT;
static constexpr char ANALOGIC_PARAMETER_HYSTERESIS[] = "Hysteresis";
static constexpr char ANALOGIC_PARAMETER_LOWERLIMIT[] = "LowerLimit";
static constexpr char ANALOGIC_PARAMETER_UPPERLIMIT[] = "UpperLimit";
static constexpr char ANALOGIC_PARAMETER_GAIN[] = "Gain";
static constexpr char ANALOGIC_PARAMETER_OFFSET[] = "Offset";
static constexpr char ANALOGIC_PARAMETER_MEASUREUNIT[] = "MeasureUnit";

#define ANALOGIC_IO_TYPE(aio) std::remove_const<decltype(aio.gain)>::type

template <typename T>
struct AnalogicIO : public SimpleIO {
    static_assert(isFloat<T>::value || isDouble<T>::value, "AnalogicIO expect only float or double type.");
    using type = T;

    AnalogicIO() { }
    AnalogicIO(const QString& n, unsigned int c, device_type d, direction_type dt, bool ia, const QString& at,
               type h, type ll, type ul, type g, type o, const QString& mu)
        : SimpleIO(n, c, d, dt, ia, at),
          hysteresis(h), lowerLimit(ll), upperLimit(ul), gain(g), offset(o), measureUnit(mu) { }

    virtual ~AnalogicIO() { }

    type hysteresis;
    type lowerLimit;
    type upperLimit;
    type gain;
    type offset;
    QString measureUnit;
};

template <typename T>
struct isAnalogicIO {
    static constexpr bool value = false;
    using type = void;
};

template <typename T>
struct isAnalogicIO<AnalogicIO<T> > {
    static constexpr bool value = true;
    using type = T;
};

using AnalogicIOFloat = AnalogicIO<float>;
using AnalogicIODouble = AnalogicIO<double>;

#define DECL_STANDARD_ANALOGIC_IO(TYPE, NAME, CHANNEL, DEVICE, DIRECTION, IS_ALARM, ALARM_TEXT, HYSTERESIS, LOWERLIMIT, UPPERLIMIT, GAIN, OFFSET, MEASUREUNIT) \
    static const AnalogicIO<TYPE> Analogic##NAME = { #NAME, CHANNEL, DEVICE, DIRECTION, IS_ALARM, ALARM_TEXT, \
                                                        HYSTERESIS, LOWERLIMIT, UPPERLIMIT, GAIN, OFFSET, MEASUREUNIT };

#define DECL_STANDARD_ANALOGIC_IO_FLOAT(...) DECL_STANDARD_ANALOGIC_IO(float, __VA_ARGS__)
#define DECL_STANDARD_ANALOGIC_IO_DOUBLE(...) DECL_STANDARD_ANALOGIC_IO(double, __VA_ARGS__)

DECL_STANDARD_ANALOGIC_IO_FLOAT(MirrorTemperature, 1, PLC, INPUT, true, QT_TRANSLATE_NOOP("Header", "Mirror temperature too high!"), 1.0, 20.0, 40.0, 1.0, 0.0, "°C")



}

#endif // ANALOGICTYPES_HPP
