#include "tokenizer.h"
#include <QRegularExpression>
#include "shuntingyard.h"
/// handle 6(2) = 6 * 2; 6i = i6 = 6*i
QVector<QString> Tokenizer::insertImplicitMultiplication(QVector<QString>& tokens) {
    QVector<QString> result;

    auto isConstant = [](const QString& token) {
        return token == "pi" || token == "e" || token == "i";
    };

    for (int i = 0; i < tokens.size(); ++i) {
        QString cur = tokens[i];
        result.append(cur);

        if (i + 1 < tokens.size()) {
            QString next = tokens[i + 1];

            bool curIsNumberOrConstOrParen =
                (!cur.isEmpty() && cur[0].isDigit()) || isConstant(cur) || cur == ")";

            bool nextIsNumberOrFuncOrParenOrConst =
                (!next.isEmpty() && next[0].isDigit()) || next == "(" || isConstant(next) || ShuntingYard::isFunction(next);

            // THÊM: Nếu cur là constant và next cũng là constant → cần nhân
            if (curIsNumberOrConstOrParen && nextIsNumberOrFuncOrParenOrConst) {
                result.append("*");
            }
        }
    }

    return result;
}


// handle 6(2 = 6(2)
QVector<QString> Tokenizer::fixMissingClosingParentheses(const QVector<QString>& tokens) {
    QVector<QString> fixedTokens = tokens;
    int openCount = 0;
    int closeCount = 0;
    for (const QString& t : tokens) {
        if (t == "(") openCount++;
        else if (t == ")") closeCount++;
    }
    int missing = openCount - closeCount;
    for (int i = 0; i < missing; i++) {
        fixedTokens.append(")");
    }
    return fixedTokens;
}

QVector<QString> Tokenizer::tokenize(const QString& expr) {
    QVector<QString> tokens;
    QString current;
    int i = 0;
    const int len = expr.length();

    // Danh sách các từ khóa đặc biệt
    QStringList knownWords = {
        "pi", "e", "i",
        "Re", "Im", "conj",
        "sqrt", "mod",
        "sin", "cos", "tan", "cot", "sec", "csc",
        "asin", "acos", "atan",
        "sinh", "cosh", "tanh",
        "log", "ln", "exp",
        "abs", "Arg"
    };


    while (i < len) {
        QChar ch = expr[i];

        if (ch.isDigit() || ch == '.') {
            current.clear();
            while (i < len && (expr[i].isDigit() || expr[i] == '.')) {
                current += expr[i];
                ++i;
            }
            tokens.append(current);
        }
        else if (ch.isSpace()) {
            ++i;
        }
        else if (ch.isLetter()) {
            // kiểm tra từ khóa phù hợp
            bool matched = false;
            for (const QString& word : knownWords) {
                int wordLen = word.length();
                if (i + wordLen <= len && expr.mid(i, wordLen) == word) {
                    tokens.append(word);
                    i += wordLen;
                    matched = true;
                    break;
                }
            }

            if (!matched) {
                // không khớp từ khóa nào, lấy từng chữ cái
                tokens.append(QString(ch));
                ++i;
            }
        }
        else {
            // ký tự đặc biệt: + - * / ( )
            tokens.append(QString(ch));
            ++i;
        }
    }

    tokens = Tokenizer::fixMissingClosingParentheses(tokens);
    tokens = Tokenizer::insertImplicitMultiplication(tokens);
    return tokens;
}
