#include "reoperation.h"
#include <cmath>
#include <stdexcept>

Complex ReOperation::execute(const Complex &a, const Complex &b) const {
    return Complex(a.real(), 0);
}
