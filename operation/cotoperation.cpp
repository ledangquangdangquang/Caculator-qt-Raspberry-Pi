#include "cotoperation.h"
#include <cmath>
#include <stdexcept>

Complex CotOperation::execute(const Complex &a, const Complex &b) const {
    constexpr double DEG2RAD = M_PI / 180.0;
    return Complex(1.0)/std::tan(a * DEG2RAD);
}

