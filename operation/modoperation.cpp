#include "modoperation.h"
#include <complex> // Để dùng std::abs cho số phức
#include <cmath>   // Để dùng std::fmod cho số thực
#include <stdexcept>

Complex ModOperation::execute(const Complex &a, const Complex &b) const {
    // 1. Lấy độ lớn (giá trị tuyệt đối) của số phức 'a'
    double abs_a = std::abs(a);

    // 2. Lấy độ lớn của số phức 'b'
    double abs_b = std::abs(b);

    // 3. Kiểm tra chia cho 0
    if (abs_b == 0.0) {
        throw std::domain_error("Modulo by zero (based on absolute value)");
    }

    // 4. Dùng std::fmod trên hai độ lớn (là kiểu double)
    double result = std::fmod(abs_a, abs_b);

    // 5. Trả về kết quả dưới dạng số phức (với phần ảo bằng 0)
    return Complex(result, 0.0);
}
