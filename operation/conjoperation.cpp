#include "conjoperation.h"
#include <stdexcept>
#include <cmath>

Complex ConjOperation::execute(const Complex &a, const Complex &b) const {
    return std::conj(a);
}
