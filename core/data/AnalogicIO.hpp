#ifndef ANALOGICTYPES_HPP
#define ANALOGICTYPES_HPP

#include <configure.h>
#include "CommonIO.hpp"
#include <global/utils/Utility.hpp>
#include <QSettings>
#include <QMap>

namespace life {

template <typename T>
struct AnalogicIO : public SimpleIO<T> {
    static_assert(isFloat<T>::value || isDouble<T>::value, "AnalogicIO expect only float or double type.");
    using type = T;

    AnalogicIO() { }
    AnalogicIO(const QString& n, unsigned int c, device_type d, direction_type dt, bool ia, const QString& at, bool il)
        : SimpleIO<type>(n, c, d, dt, ia, at),
          hysteresis(), lowerLimit(), upperLimit(), measureUnit(), gain(), offset() { }

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

class MachineAnalogicIO {
public:
    using Ptr = MachineAnalogicIO *;
    using ConstPtr = const MachineAnalogicIO *;

private:
    QMap<QString, AnalogicIO<double> > analogicIO;

public:
    MachineAnalogicIO();

    void load();

    void flush() const;

};

}

#endif // ANALOGICTYPES_HPP
