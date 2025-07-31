#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QString>
#include <QVector>

class Tokenizer {

public:
    static QVector<QString> tokenize(const QString& expr);
private:
    static QVector<QString> fixMissingClosingParentheses(const QVector<QString>& tokens);
    static QVector<QString> insertImplicitMultiplication(QVector<QString>& tokens);
};

#endif // TOKENIZER_H
