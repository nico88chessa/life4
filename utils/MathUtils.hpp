#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

#include <cmath>

namespace dv {

class MathUtils {
public:

    inline static float roundf(float value, int digit) {

        double multiplier = std::pow(10, digit);
        double temp = std::round((double)value * multiplier);
        double res = (double) temp / multiplier;
        return static_cast<float>(res);
    }

};

}

#endif // MATHUTILS_HPP
