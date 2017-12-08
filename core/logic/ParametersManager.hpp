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
    QMap<QString, std::shared_ptr<SimpleIO> > ios; // parametri chiave, valore

public:
    ParametersManager();

public:

//    template <typename T>
//    T getParameter(const machineparameters::MachineParameter<T>& parameter) const {
//        if (parameters.contains(parameter.key))
//            return static_cast<QVariant>(parameters.value(parameter.key)).value<T>();
//        return T();
//    }

//    template <typename T>
//    void setParameter(const machineparameters::MachineParameter<T>& parameter, const T& value) {
//        if (parameters.contains(parameter.key))
//            parameters.insert(parameter.key, value);
//    }

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
            if (auto&& value = std::dynamic_pointer_cast<T>(ios.value(name)))
                return value;

        return std::make_shared<T>();
    }

    const QMap<QString, std::shared_ptr<SimpleIO> >& getIOs() const { return ios; }

    int size() const { return parameters.size(); }

    void load();

    void flush() const;

};


}



#endif // MACHINEPARAMETERS_HPP
