#ifndef CONJOPERATION_H
#define CONJOPERATION_H

#include "operation.h"

class ConjOperation : public Operation
{
public:
    Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // CONJOPERATION_H
