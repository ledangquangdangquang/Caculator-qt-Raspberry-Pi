#include "logoperation.h"
#include <cmath>
#include <stdexcept>

Complex LogOperation::execute(const Complex &a, const Complex &b) const {
    if (a.imag() == 0 && a.real() < 0)
        throw std::domain_error("Log of negative real number");
    return std::log10(a);
}
