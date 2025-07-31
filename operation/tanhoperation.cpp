#include "tanhoperation.h"
#include <cmath>
#include <stdexcept>

Complex TanhOperation::execute(const Complex &a, const Complex &b) const {
    return std::tanh(a);
}
