#include "sinoperation.h"
#include <cmath>
#include <stdexcept>

Complex SinOperation::execute(const Complex &a, const Complex &b) const {
    constexpr double DEG2RAD = M_PI / 180.0;
    return std::sin(a * DEG2RAD);
}
