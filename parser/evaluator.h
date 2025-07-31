#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <QString>
#include <QVector>
#include <memory>
#include "operation/operationfactory.h"
#include <complex>

using Complex = std::complex<double>;

class Evaluator {
public:
    // Tính toán kết quả từ dãy token postfix
    // Trả về true nếu thành công, false nếu lỗi
    static bool evaluate(const QVector<QString>& postfixTokens, Complex& result);
private:
    static bool isUnaryFunction(const QString& token);
    static Complex roundComplex(const Complex& z, int decimals);
};

#endif // EVALUATOR_H
