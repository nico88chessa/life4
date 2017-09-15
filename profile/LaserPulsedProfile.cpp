#include <LaserPulsedProfile.hpp>

LaserPulsedProfile::LaserPulsedProfile(
        quint32 _power,
        float _pulseWidth,
        float _frequency,
        quint32 _maxPulsesNumber, quint32 _minPulsesNumber)
    : LaserBaseProfile(_power, 0, 0),
      pulseWidth(_pulseWidth), frequency(_frequency) {

    setMinPulsesNumber(_minPulsesNumber);
    setMaxPulsesNumber(_maxPulsesNumber);

}

quint32 LaserPulsedProfile::getMinPulsesNumber() const {
    return minPulsesNumber;
}

void LaserPulsedProfile::setMinPulsesNumber(const quint32& value) {

    minPulsesNumber = value;
    setMinTimeOn(dv::MathUtils::roundf(1 / frequency * minPulsesNumber, 2) );
}

quint32 LaserPulsedProfile::getMaxPulsesNumber() const {
    return maxPulsesNumber;
}

void LaserPulsedProfile::setMaxPulsesNumber(const quint32& value) {

    maxPulsesNumber = value;
    setMaxTimeOn(dv::MathUtils::roundf(1 / frequency * maxPulsesNumber, 2) );
}

float LaserPulsedProfile::getPulseWidth() const {
    return pulseWidth;
}

void LaserPulsedProfile::setPulseWidth(float value) {
    pulseWidth = value;
}

float LaserPulsedProfile::getFrequency() const {
    return frequency;
}

void LaserPulsedProfile::setFrequency(float value) {
    frequency = value;
}
