#include "argoperation.h"

#include <cmath>
#include <stdexcept>

Complex ArgOperation::execute(const Complex &a, const Complex &b) const {
   return Complex(std::arg(a), 0);  // Góc pha (radian)
}


