#ifndef COTOPERATION_H
#define COTOPERATION_H

#include "operation.h"

class CotOperation : public Operation
{
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // COTOPERATION_H
