#include "coshoperation.h"
#include <cmath>
#include <stdexcept>

Complex CoshOperation::execute(const Complex &a, const Complex &b) const {
    return std::cosh(a);
}
