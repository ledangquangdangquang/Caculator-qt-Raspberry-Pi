#ifndef SINOPERATION_H
#define SINOPERATION_H

#include "operation.h"

class SinOperation : public Operation
{
public:
    Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};


#endif //	SINOPERATION_H
