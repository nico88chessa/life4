#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include <QtMath>

namespace life {

class Cylinder {
public:
    using Ptr = Cylinder *;
    using ConstPtr = const Cylinder *;

protected:
    static constexpr float defaultLength = 1;
    static constexpr float defaultCircumference = 100;
    static constexpr float defaultStartAt = 0;
    static constexpr float defaultCrossAt = 0;

public:
    Cylinder();
    Cylinder(float _length, float _diameter, float _startAt, float _crossAt);

private:
    float length;
    float circumference;
    float startAt;
    float crossAt;

public:
    float getLength() const;
    void setLength(float value);

    float getCircumference() const;
    void setCircumference(float value);

    float getStartAt() const;
    void setStartAt(float value);

    float getCrossAt() const;
    void setCrossAt(float value);

    float getDiameter() const;
    void setDiameter(float value);

};

}

#endif // CYLINDER_HPP
