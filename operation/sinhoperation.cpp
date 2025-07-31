#include "sinhoperation.h"
#include <cmath>
#include <stdexcept>

Complex SinhOperation::execute(const Complex &a, const Complex &b) const {
    return std::sinh(a);
}
