#include "LaserBaseProfile.hpp"

LaserBaseProfile::LaserBaseProfile() : LaserBaseProfile(0, 0, 0) { }

LaserBaseProfile::LaserBaseProfile(quint32 _power, float _minTimeOn, float _maxTimeOn)
    : power(_power), minTimeOn(_minTimeOn), maxTimeOn(_maxTimeOn) {

}

float LaserBaseProfile::getMinTimeOn() const {
    return minTimeOn;
}

void LaserBaseProfile::setMinTimeOn(const float& value) {
    minTimeOn = value;
}

float LaserBaseProfile::getMaxTimeOn() const {
    return maxTimeOn;
}

void LaserBaseProfile::setMaxTimeOn(const float& value) {
    maxTimeOn = value;
}

quint32 LaserBaseProfile::getPower() const {
    return power;
}

void LaserBaseProfile::setPower(quint32 value) {
    power = value;
}
