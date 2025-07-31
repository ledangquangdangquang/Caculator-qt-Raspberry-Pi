#ifndef ARGOPERATION_H
#define ARGOPERATION_H

#include "operation.h"

class ArgOperation : public Operation
{
public:
    Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // ARGOPERATION_H
