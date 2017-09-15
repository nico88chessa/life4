#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <QString>
#include <LaserBaseProfile.hpp>
#include <LaserDutyProfile.hpp>
#include <LaserPulsedProfile.hpp>
#include <utility>

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
    Profile(type&& _laserConfiguration) : laserConfiguration(std::forward<type>(_laserConfiguration)) {
        qDebug() << "enso";
    }/*, Profile("", 1, 1, 1) {
//        static_assert(isLaserBaseProfile<L>::value ||
//                      isLaserDutyProfile<L>::value ||
//                      isLaserPulsedProfile<L>::value, "template L argument isn't a LaserType");

    }*/

    Profile(const QString& _name,
            quint32 _beams,
            float _yResolution,
            quint32 _shotsPerPixel)/*,
            type&& _laserConfiguration)*/
        : name(_name), beams(_beams), yResolution(_yResolution), shotsPerPixel(_shotsPerPixel) { } //, laserConfiguration(std::move(_laserConfiguration)) { }

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
//        static_assert(isLaserBaseProfile<L>::value ||
//                      isLaserDutyProfile<L>::value ||
//                      isLaserPulsedProfile<L>::value, "template L argument isn't a LaserType");

//        auto laser = (LaserBaseProfile) laserConfiguration;

        return static_cast<LaserBaseProfile>(laserConfiguration).getMaxTimeOn();
    }

};

#endif // PROFILE_HPP

