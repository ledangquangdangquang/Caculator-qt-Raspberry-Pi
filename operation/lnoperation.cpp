#include "lnoperation.h"
#include <cmath>
#include <stdexcept>

Complex LnOperation::execute(const Complex &a, const Complex &b) const {
    if (a.imag() == 0 && a.real() < 0)
        throw std::domain_error("Log of negative real number");
    return std::log(a);
}
