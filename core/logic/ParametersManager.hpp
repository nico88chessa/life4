#ifndef MACHINEPARAMETERS_HPP
#define MACHINEPARAMETERS_HPP

#include <iostream>
#include <QString>
#include <QVariant>
#include <QMap>
#include <QSettings>
#include <configure.h>
#include <core/data/Parameters.hpp>


namespace life {

class ParametersManager {
public:
    using Ptr = ParametersManager *;
    using ConstPtr = const ParametersManager *;

private:
    QMap<QString, QVariant> parameters;

public:
    ParametersManager();

public:

    template <typename T>
    T getValue(const machineparameters::MachineParameter<T>& parameter) const {
        if (parameters.contains(parameter.key))
            return static_cast<QVariant>(parameters.value(parameter.key)).value<T>();
        return T();
    }

    template <typename T>
    void setValue(const machineparameters::MachineParameter<T>& parameter, const T& value) {
        if (parameters.contains(parameter.key))
            parameters.insert(parameter.key, value);
    }

    const QMap<QString, QVariant>& getMap() const { return parameters; }

    int size() const { return parameters.size(); }

    void load();

    void flush() const;

};


}



#endif // MACHINEPARAMETERS_HPP
