#ifndef ABSTRACTLASERDEVICE_HPP
#define ABSTRACTLASERDEVICE_HPP

#include "AbstractDevice.hpp"

namespace life {

template <class S>
class AbstractLaser : public AbstracDevice {
public:
    using Ptr = AbstractLaser *;
    using ConstPtr = const AbstractLaser *;

public:

    /**
     * questa funzione serve per impostare i parametri del laser a
     * seconda del profilo di stampa scelto
     */
    template <class P>
    virtual bool configureFromProfile(const P& profile) = 0;

    /**
     * @brief getStatus
     * @return S lo stato del laser
     */
    virtual S getStatus() const = 0;

    /**
     * @brief emissionOn
     * @return emission On
     */
    virtual bool emissionOn() = 0;

    /**
     * @brief emissionOff
     * @return emission Off
     */
    virtual bool emissionOff() = 0;

};

}

#endif // ABSTRACTLASERDEVICE_HPP
