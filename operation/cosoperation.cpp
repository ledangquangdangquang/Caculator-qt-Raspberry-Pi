#include "cosoperation.h"

#include <cmath>
#include <stdexcept>

Complex CosOperation::execute(const Complex &a, const Complex &b) const {
    constexpr double DEG2RAD = M_PI / 180.0;
    return std::cos(a * DEG2RAD);
}
