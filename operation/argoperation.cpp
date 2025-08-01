#include "argoperation.h"

#include <cmath>
#include <stdexcept>

Complex ArgOperation::execute(const Complex &a, const Complex &b) const {
    constexpr double RAD2DEG = 180.0 / M_PI;
    return Complex(std::arg(a) * RAD2DEG, 0);  // Góc pha (đơn vị độ)
}
