#include "evaluator.h"
#include <QStack>
#include <QDebug>
#include <QSet>
#include <cmath>

Complex Evaluator::roundComplex(const Complex& z, int decimals) {
    double scale = std::pow(10.0, decimals);
    return Complex(
        std::round(z.real() * scale) / scale,
        std::round(z.imag() * scale) / scale
        );
}

bool Evaluator::isUnaryFunction(const QString& token) {
    static const QSet<QString> unaryFunctions = {
        "sqrt", "sin", "cos", "tan", "cot", "log", "ln", "abs",
        "sinh", "cosh", "tanh", "Re", "Im", "Arg", "conj"
    };
    return unaryFunctions.contains(token);
}

bool Evaluator::evaluate(const QVector<QString>& postfixTokens, Complex& result) {
    QStack<Complex> stack;
    constexpr double DEG2RAD = M_PI / 180.0;
    const int decimals = 5;

    for (const QString& token : postfixTokens) {
        bool isNumber = false;
        double realVal = token.toDouble(&isNumber);

        if (isNumber) {
            // Token là số thực
            stack.push(Complex(realVal, 0));
        } else if (token == "i") {
            // Đơn vị ảo
            stack.push(Complex(0, 1));
        } else {
            // Lấy operation từ factory
            auto operation = OperationFactory::getOperation(token);
            if (!operation) {
                qWarning() << "ERROR: unknown operator or function:" << token;
                return false;
            }

            if (isUnaryFunction(token)) {
                if (stack.isEmpty()) {
                    qWarning() << "ERROR: stack empty for unary operation:" << token;
                    return false;
                }
                Complex a = stack.pop();

                // Kiểm tra lỗi đặc biệt
                if (token == "sqrt") {
                    if (a.imag() != 0 || a.real() < 0) {
                        qWarning() << "ERROR: sqrt of negative or complex number";
                        return false;
                    }
                } else if ((token == "log" || token == "ln") && (a.real() <= 0 && std::abs(a.imag()) < 1e-12)) {
                    qWarning() << "ERROR: log/ln of non-positive real number";
                    return false;
                } else if (token == "cot") {
                    Complex tanVal = std::tan(a * DEG2RAD);
                    if (std::abs(tanVal) < 1e-12) {
                        qWarning() << "ERROR: cotangent undefined (tan ≈ 0)";
                        return false;
                    }
                }

                Complex res = operation->execute(a, Complex(0));
                stack.push(roundComplex(res, decimals));
            } else {
                // Phép toán nhị phân
                if (stack.size() < 2) {
                    qWarning() << "ERROR: stack too small for binary operator:" << token;
                    return false;
                }
                Complex b = stack.pop();
                Complex a = stack.pop();

                if ((token == "/" || token == "÷") && std::abs(b.real()) < 1e-12 && std::abs(b.imag()) < 1e-12) {
                    qWarning() << "ERROR: Division by zero";
                return false;
            }

            Complex res = operation->execute(a, b);
            stack.push(roundComplex(res, decimals));

            }
        }
    }

    if (stack.size() != 1) {
        qWarning() << "ERROR: stack size after evaluation not 1";
        return false;
    }

    result = stack.pop();
    return true;
}
