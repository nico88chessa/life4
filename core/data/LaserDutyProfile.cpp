#include "LaserDutyProfile.hpp"

using namespace life;

LaserDutyProfile::LaserDutyProfile()
    : LaserDutyProfile(defaultPower, defaultDuty, defaultMinTimeOn) { }

LaserDutyProfile::LaserDutyProfile(quint32 _power, quint32 _duty, float _pulseWidth, float _minTimeOn)
    : LaserBaseProfile(_power, _minTimeOn, 0), duty(_duty) {

    setPulseWidth(_pulseWidth);
}


quint32 LaserDutyProfile::getDuty() const {
    return duty;
}

void LaserDutyProfile::setDuty(const quint32& value) {

    duty = value;
    updateTimeOn();
}

float LaserDutyProfile::getPulseWidth() const {
    return pulseWidth;
}

void LaserDutyProfile::setPulseWidth(const float& value) {

    pulseWidth = value;
    updateTimeOn();
}

void LaserDutyProfile::updateTimeOn() {

    float timeOnMax = MathUtils::roundf(pulseWidth * 100 / duty, 2);
    this->setMaxTimeOn(timeOnMax);
}
