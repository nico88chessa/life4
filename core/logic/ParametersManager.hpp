#ifndef MACHINEPARAMETERS_HPP
#define MACHINEPARAMETERS_HPP

#include <iostream>
#include <QString>
#include <QVariant>
#include <QMap>
#include <QSettings>
#include <QDebug>
#include <configure.h>
#include <core/data/Parameters.hpp>
#include <core/data/DigitalIO.hpp>
#include <core/data/AnalogicIO.hpp>
#include <memory>


namespace life {

class ParametersManager {
public:
    using Ptr = ParametersManager *;
    using ConstPtr = const ParametersManager *;

private:
    QMap<QString, QVariant> parameters; // parametri chiave, valore
    QMap<QString, std::shared_ptr<SimpleIO> > ios; // parametri chiave, shared_ptr<valore>

public:
    ParametersManager();

public:

    template <typename T>
    T getParameter(const QString& name) const {
        if (parameters.contains(name))
            return static_cast<QVariant>(parameters.value(name)).value<T>();
        return T();
    }

    template <typename T>
    void setParameter(const QString& name, const T& value) {
        if (parameters.contains(name))
            parameters.insert(name, value);
    }

    const QMap<QString, QVariant>& getParameters() const { return parameters; }

    template <typename T>
    std::shared_ptr<const T> getIO(const QString& name) const {
        if (ios.contains(name))
            if (auto&& value = std::const_pointer_cast<T>(ios.value(name)))
                return value;

        return std::make_shared<T>();
    }

    template <typename T>
    void setIO(const QString& name, const T& value) {
        if (ios.contains(name))
            ios.remove(name);

        static_assert(isDigitalIO<T>::value || isAnalogicIO<T>::value, "IO type must be DigitalIO or AnalogicIO.");

        ios.insert(name, std::make_shared<T>(value));
    }

    const QMap<QString, std::shared_ptr<const SimpleIO> > getIOs() const {
        QMap<QString, std::shared_ptr<const SimpleIO> > newMap;
        for (auto&& key: ios.keys())
            newMap[key] = std::const_pointer_cast<SimpleIO>(ios[key]);

        return newMap;
    }

    void load();

    void flush() const;

};


}



#endif // MACHINEPARAMETERS_HPP
