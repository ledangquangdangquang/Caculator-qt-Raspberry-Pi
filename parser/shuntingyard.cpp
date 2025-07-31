#include "shuntingyard.h"
#include <QStack>
#include <QDebug>
#include <cmath>

int ShuntingYard::precedence(const QString& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/" || op == "mod" || op == "^") return 2;
    // Nếu bạn muốn thêm operator khác, nâng cấp ở đây
    return 0;
}

bool ShuntingYard::isOperator(const QString& token) {
    return token == "+" || token == "-" ||
           token == "*" || token == "/"  ||
           token == "mod"|| token == "^";
}

bool ShuntingYard::isFunction(const QString& token) {
    // Ví dụ: chỉ có sqrt
    return token == "sqrt" || token == "sin" ||
           token == "cos" || token == "tan" ||
           token == "cot" || token == "log" ||
           token == "ln" || token == "abs" ||
           token == "sinh" || token == "cosh" ||
           token == "tanh" ||  token == "Re" ||
           token == "Im" || token == "Arg" ||
           token == "conj";
}

QVector<QString> ShuntingYard::toPostfix(const QVector<QString>& tokens) {
    QVector<QString> outputQueue;
    QStack<QString> operatorStack;

    QString lastToken; // Lưu token trước đó để phát hiện dấu âm

    for (int i = 0; i < tokens.size(); ++i) {
        QString token = tokens[i];
        if (token.isEmpty())
            continue;

        // Xử lý unary minus: nếu token là "-" và sau đó là số
        if (token == "-" &&
            (lastToken.isEmpty() || isOperator(lastToken) || lastToken == "(") &&
            i + 1 < tokens.size())
        {
            QString nextToken = tokens[i + 1];
            bool isNum;
            nextToken.toDouble(&isNum);
            if (isNum) {
                // Ghép "-" và số thành 1 token: "-5"
                outputQueue.append("-" + nextToken);
                i++; // Bỏ qua nextToken
                lastToken = nextToken; // Đánh dấu đã xử lý số
                continue;
            }
        }
        if (token == "+" &&
            (lastToken.isEmpty() || isOperator(lastToken) || lastToken == "(") &&
            i + 1 < tokens.size())
        {
            QString nextToken = tokens[i + 1];
            bool isNum;
            nextToken.toDouble(&isNum);
            if (isNum) {
                // Ghép "-" và số thành 1 token: "-5"
                outputQueue.append(nextToken);
                i++; // Bỏ qua nextToken
                lastToken = nextToken; // Đánh dấu đã xử lý số
                continue;
            }
        }

        // Nếu token là số
        bool isNumber;
        token.toDouble(&isNumber);
        if (isNumber) {
            outputQueue.append(token);
        }
        // Nếu token là hằng số e (Euler)
        else if (token == "e") {
            outputQueue.append(QString::number(M_E)); // hoặc QString::number(M_E, 'g', 15)
        }
        // Nếu token là hằng số e (Euler)
        else if (token == "pi") {
            outputQueue.append(QString::number(M_PI)); // hoặc QString::number(M_E, 'g', 15)
        }
        // Nếu token là số phức "i"
        else if (token == "i") {
            outputQueue.append(token);
        }
        // Nếu là hàm
        else if (isFunction(token)) {
            operatorStack.push(token);
        }
        // Nếu là toán tử
        else if (isOperator(token)) {
            while (!operatorStack.isEmpty()) {
                QString top = operatorStack.top();
                if ((isOperator(top) && precedence(top) >= precedence(token)) || isFunction(top)) {
                    outputQueue.append(operatorStack.pop());
                } else {
                    break;
                }
            }
            operatorStack.push(token);
        }
        // Nếu là dấu "("
        else if (token == "(") {
            operatorStack.push(token);
        }
        // Nếu là dấu ")"
        else if (token == ")") {
            while (!operatorStack.isEmpty() && operatorStack.top() != "(") {
                outputQueue.append(operatorStack.pop());
            }
            if (!operatorStack.isEmpty() && operatorStack.top() == "(") {
                operatorStack.pop();
            }
            if (!operatorStack.isEmpty() && isFunction(operatorStack.top())) {
                outputQueue.append(operatorStack.pop());
            }
        }

        lastToken = token;
    }

    while (!operatorStack.isEmpty()) {
        outputQueue.append(operatorStack.pop());
    }

    return outputQueue;
}

