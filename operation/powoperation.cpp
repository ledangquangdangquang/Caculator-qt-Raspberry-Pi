#include "powoperation.h"
#include <cmath>

Complex PowOperation::execute(const Complex &a, const Complex &b) const
{
    return pow(a, b);
}
