#ifndef COSOPERATION_H
#define COSOPERATION_H

#include "operation.h"

class CosOperation : public Operation
{
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // COSOPERATION_H
