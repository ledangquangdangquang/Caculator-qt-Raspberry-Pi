#ifndef IMOPERATION_H
#define IMOPERATION_H

#include "operation.h"

class ImOperation : public Operation
{
public:
    Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // IMOPERATION_H
