#ifndef LASERDUTYPROFILE_HPP
#define LASERDUTYPROFILE_HPP

#include "LaserBaseProfile.hpp"
#include <global/utils/MathUtils.hpp>
#include <QtDebug>

namespace life {

class LaserDutyProfile : public LaserBaseProfile {
public:
    using Ptr = LaserDutyProfile*;
    using ConstPtr = const LaserDutyProfile*;

protected:
    static constexpr quint32 defaultDuty = 70;
    static constexpr float defaultPulseWidth = 5;

private:
    quint32 duty;     // duty cycle [%]
    float pulseWidth; // larghezza dell'impulso reale [us]

public:
    LaserDutyProfile();
    LaserDutyProfile(quint32 _power, quint32 _duty, float _pulseWidth, float _minTimeOn=0);

    virtual ~LaserDutyProfile() { }

    quint32 getDuty() const;
    void setDuty(const quint32& value);

    float getPulseWidth() const;
    void setPulseWidth(const float& value);

    virtual quint32 getPower() const { return power; }
    virtual void setPower(quint32 value) { power = value; }

    virtual float getMinTimeOn() const { return minTimeOn; }
    virtual float getMaxTimeOn() const { return maxTimeOn; }

private:
    inline void updateTimeOn();

};

template <>
struct isLaserBaseProfile<LaserDutyProfile> {
    constexpr static bool value = true;
    using type = LaserDutyProfile;
};

}

#endif // LASERDUTYPROFILE_HPP
