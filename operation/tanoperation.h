#ifndef TANOPERATION_H
#define TANOPERATION_H

#include "operation.h"

class TanOperation : public Operation
{
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // TANOPERATION_H
