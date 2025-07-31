#ifndef ABSOPERATION_H
#define ABSOPERATION_H

#include "operation.h"

class AbsOperation : public Operation
{
public:
    Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // ABSOPERATION_H
