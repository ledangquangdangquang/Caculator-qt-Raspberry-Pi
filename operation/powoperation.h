#ifndef POWOPERATION_H
#define POWOPERATION_H

#include "operation.h"

class PowOperation : public Operation
{
public:
    Complex execute(const Complex &a, const Complex &b) const override;  // chỉ khai báo
};

#endif // POWOPERATION_H
