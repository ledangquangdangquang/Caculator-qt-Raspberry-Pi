#ifndef SINHOPERATION_H
#define SINHOPERATION_H

#include "operation.h"

class SinhOperation : public Operation {
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // SINHOPERATION_H
