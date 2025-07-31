#ifndef SQRTOPERATION_H
#define SQRTOPERATION_H

#include "operation.h"

class SqrtOperation : public Operation {
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // SQRTOPERATION_H
