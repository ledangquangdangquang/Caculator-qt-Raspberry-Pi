#ifndef REOPERATION_H
#define REOPERATION_H

#include "operation.h"

class ReOperation : public Operation
{
public:
    Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // REOPERATION_H
