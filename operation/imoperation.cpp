#include "imoperation.h"
#include <cmath>
#include <stdexcept>

Complex ImOperation::execute(const Complex &a, const Complex &b) const {
    return Complex(a.imag(), 0);
}
