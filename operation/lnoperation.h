#ifndef LNOPERATION_H
#define LNOPERATION_H

#include "operation.h"
class LnOperation : public Operation
{
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // LNOPERATION_H
