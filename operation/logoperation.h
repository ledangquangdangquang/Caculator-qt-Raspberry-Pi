#ifndef LOGOPERATION_H
#define LOGOPERATION_H


#include "operation.h"
class LogOperation : public Operation
{
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // LOGOPERATION_H
