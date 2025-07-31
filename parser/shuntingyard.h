#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <QString>
#include <QVector>
#include <QMap>

class ShuntingYard {
public:
    // Chuyển biểu thức token (infix) thành postfix (hậu tố)
    static QVector<QString> toPostfix(const QVector<QString>& tokens);
    // Kiểm tra token là hàm (ví dụ "sqrt")
    static bool isFunction(const QString& token); // Cho len public de lam ham insertImplitMultiplication

private:
    // Trợ giúp: xác định độ ưu tiên của toán tử
    static int precedence(const QString& op);
    // Kiểm tra token là toán tử
    static bool isOperator(const QString& token);
};

#endif // SHUNTINGYARD_H
