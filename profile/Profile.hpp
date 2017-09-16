#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <QString>
#include <LaserBaseProfile.hpp>
#include <LaserDutyProfile.hpp>
#include <LaserPulsedProfile.hpp>
#include <utility>

static constexpr char defaultName[] = "Empty";
static constexpr quint32 defaultBeams = 1;
static constexpr float defaultYResolution = 1000;
static constexpr quint32 defaultShotsPerPixel = 1;

template <class L>
class Profile {
public:
    using Ptr = Profile *;
    using constPtr = const Profile *;
    using type = L;

private:
    QString name;
    quint32 beams;
    float yResolution;
    quint32 shotsPerPixel;
    type laserConfiguration;

public:

    Profile()
        :Profile(defaultName, defaultBeams, defaultYResolution, defaultShotsPerPixel) { }

    Profile(const type& _laserConfiguration)
        : Profile ("Empty", 1, 1, 1) { }

    Profile(const QString& _name, quint32 _beams, float _yResolution, quint32 _shotsPerPixel, const type& _laserConfiguration)
        : name(_name), beams(_beams), yResolution(_yResolution), shotsPerPixel(_shotsPerPixel), laserConfiguration(_laserConfiguration) {

        static_assert(isLaserBaseProfile<L>::value, "template type L isn't a Laser Base profile");
        qDebug() << "Profile Constructor 2";
    }

    template <typename... Types>
    Profile(const QString& _name,
            quint32 _beams,
            float _yResolution,
            quint32 _shotsPerPixel,
            Types... args)
        : name(_name), beams(_beams), yResolution(_yResolution), shotsPerPixel(_shotsPerPixel), laserConfiguration(args...) {

        static_assert(isLaserBaseProfile<L>::value, "template type L isn't a Laser Base profile");
        qDebug() << "Profile Constructor 2";
    }

    quint32 getShotsPerPixel() const {
        return shotsPerPixel;
    }

    void setShotsPerPixel(const quint32& value) {
        shotsPerPixel = value;
    }

    float getYResolution() const {
        return yResolution;
    }

    void setYResolution(float value) {
        yResolution = value;
    }

    quint32 getBeams() const {
        return beams;
    }

    void setBeams(const quint32& value) {
        beams = value;
    }

    QString getName() const {
        return name;
    }

    void setName(const QString& value) {
        name = value;
    }

    float getPixelTime() const {
        static_assert(isLaserBaseProfile<type>::value, "template type L isn't a Laser Base profile");
        return static_cast<const LaserBaseProfile&>(laserConfiguration).getMaxTimeOn() * this->shotsPerPixel;
    }

    const type& getLaserConfiguration() const {
        return laserConfiguration;
    }

    void setLaserConfiguration(const type &value) {
        laserConfiguration = value;
    }

};

using ProfileBase = Profile<LaserBaseProfile>;
using ProfileDuty = Profile<LaserDutyProfile>;
using ProfilePulsed = Profile<LaserPulsedProfile>;

#endif // PROFILE_HPP
