#include "sqrtoperation.h"
#include <cmath>
#include <stdexcept>
#include <complex>

Complex SqrtOperation::execute(const Complex &a, const Complex &b) const {
    // Chỉ báo lỗi nếu a là số thực âm (phần ảo = 0, phần thực < 0)
    if (a.imag() == 0 && a.real() < 0)
        throw std::domain_error("Square root of negative real number");

    return std::sqrt(a);
}
