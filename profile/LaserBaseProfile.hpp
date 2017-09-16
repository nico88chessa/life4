#ifndef LASERBASEPROFILE_HPP
#define LASERBASEPROFILE_HPP

#include <QtGlobal>
#include <QtMath>


class LaserBaseProfile {
public:
    using Ptr = LaserBaseProfile *;
    using ConstPtr = const LaserBaseProfile *;

protected:
    static constexpr float defaultMaxTimeOn = 1;
    static constexpr quint32 defaultPower = 100;
    static constexpr float defaultMinTimeOn = 0;

protected:
    quint32 power;          // potenza del laser [%]
    float minTimeOn;        // tempo Ton minimo [us]
    float maxTimeOn;        // tempo Ton massimo [us]

public:
    LaserBaseProfile();
    LaserBaseProfile(quint32 _power, float _minTimeOn, float _maxTimeOn);
    virtual ~LaserBaseProfile() { }

    virtual float getMinTimeOn() const;
    virtual void setMinTimeOn(const float& value);

    virtual float getMaxTimeOn() const;
    virtual void setMaxTimeOn(const float& value);

    virtual quint32 getPower() const;
    virtual void setPower(quint32 value);

};

template <class T>
struct isLaserBaseProfile {
    constexpr static bool value = false;
    using type = T;
};

template <>
struct isLaserBaseProfile<LaserBaseProfile> {
    constexpr static bool value = true;
    using type = LaserBaseProfile;
};

#endif // LASERBASEPROFILE_HPP

