#ifndef TANHOPERATION_H
#define TANHOPERATION_H


#include "operation.h"

class TanhOperation : public Operation {
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // TANHOPERATION_H
