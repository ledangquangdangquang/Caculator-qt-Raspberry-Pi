#include "divoperation.h"

Complex DivOperation::execute(const Complex &a, const Complex &b) const {  // <-- KHÔNG dùng override ở đây
    if (b == Complex(0))
        throw std::runtime_error("Divide by zero");
    return a / b;
}
