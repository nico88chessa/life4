#ifndef DIGITALIO_HPP
#define DIGITALIO_HPP

#include <configure.h>
#include "CommonIO.hpp"
#include <global/utils/Utility.hpp>
#include <QSettings>
#include <QMap>

namespace life {

struct DigitalIO : public SimpleIO<bool> {
    DigitalIO() { }
    DigitalIO(const QString& n, unsigned int c, device_type d, direction_type dt, bool ia, const QString& at, bool il)
        : SimpleIO(n, c, d, dt, ia, at),
          invertLogic(il) { }

    bool invertLogic;
};

template <typename T>
struct isDigitalIO {
    static constexpr bool value = false;
    using type = void;
};

template <>
struct isDigitalIO<DigitalIO> {
    static constexpr bool value = true;
    using type = bool;
};


class MachineDigitalIO {
public:
    using Ptr = MachineDigitalIO *;
    using ConstPtr = const MachineDigitalIO *;

private:
    QMap<QString, DigitalIO> listDigitalIO;

public:
    MachineDigitalIO();

    void load();

    void flush() const;

};

}

#endif // DIGITALIO_HPP
