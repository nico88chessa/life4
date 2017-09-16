#ifndef LASERPULSEDPROFILE_HPP
#define LASERPULSEDPROFILE_HPP

#include <LaserBaseProfile.hpp>
#include <MathUtils.hpp>

class LaserPulsedProfile : public LaserBaseProfile {
public:
    using Ptr = LaserPulsedProfile *;
    using ConstPtr = const LaserPulsedProfile *;

private:
    quint32 minPulsesNumber;    // numero impulsi minimo
    quint32 maxPulsesNumber;    // numero impulsi massimo
    float pulseWidth;           // larghezza impulso [us]
    float frequency;            // frequenza laser [Hz]

protected:
    static constexpr quint32 defaultMinPulsesNumber = 0;
    static constexpr quint32 defaultMaxPulsesNumber = 1;
    static constexpr float defaultPulseWidth = 100;
    static constexpr float defaultFrequency = 1000;

public:
    LaserPulsedProfile();

    LaserPulsedProfile(
            quint32 _power,
            float _pulseWidth,
            float _frequency,
            quint32 _maxPulsesNumber, quint32 _minPulsesNumber);

    virtual ~LaserPulsedProfile() { }

    quint32 getMinPulsesNumber() const;
    void setMinPulsesNumber(const quint32& value);

    quint32 getMaxPulsesNumber() const;
    void setMaxPulsesNumber(const quint32& value);

    float getPulseWidth() const;
    void setPulseWidth(float value);

    float getFrequency() const;
    void setFrequency(float value);

    virtual quint32 getPower() const { return power; }
    virtual void setPower(quint32 value) { power = value; }

    virtual float getMinTimeOn() const { return minTimeOn; }
    virtual float getMaxTimeOn() const { return maxTimeOn; }

};

template <>
struct isLaserBaseProfile<LaserPulsedProfile> {
    constexpr static bool value = true;
    using type = LaserPulsedProfile;
};

#endif // PULSEDPROFILE_HPP
