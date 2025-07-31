#include "absoperation.h"

#include <cmath>
#include <stdexcept>

Complex AbsOperation::execute(const Complex &a, const Complex &b) const {
    // 1. Dùng std::abs để tính độ lớn (magnitude) của số phức 'a'.
    //    Kết quả trả về là một số thực kiểu 'double'.
    double magnitude = std::abs(a);

    // 2. Hàm execute() yêu cầu trả về một đối tượng 'Complex'.
    //    Vì vậy, ta tạo một số phức mới với phần thực là độ lớn vừa tính
    //    và phần ảo bằng 0.
    return Complex(magnitude, 0.0);
}
