#include "tanoperation.h"
#include <stdexcept>
#include <complex>   // Dùng header này cho std::tan với số phức
#include <cmath>

Complex TanOperation::execute(const Complex &a, const Complex &b) const {
    constexpr double DEG2RAD = M_PI / 180.0;
    return std::tan(a * DEG2RAD);
}
