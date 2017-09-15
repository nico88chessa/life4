#ifndef LASERDUTYPROFILE_HPP
#define LASERDUTYPROFILE_HPP

#include <LaserBaseProfile.hpp>
#include <MathUtils.hpp>
#include <QtDebug>

class LaserDutyProfile : public LaserBaseProfile {
public:
    using Ptr = LaserDutyProfile*;
    using ConstPtr = const LaserDutyProfile*;

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
    virtual float getMaxTimeOn() const override {
        qDebug() << "jowengownegowno";
        return maxTimeOn;
    }

private:
    inline void updateTimeOn();

};

template <class T>
struct isLaserDutyProfile {
    constexpr static bool value = false;
};

template <>
struct isLaserDutyProfile<LaserDutyProfile> {
    constexpr static bool value = true;
};

#endif // LASERDUTYPROFILE_HPP
