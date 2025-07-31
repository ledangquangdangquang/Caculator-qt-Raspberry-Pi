#ifndef MODOPERATION_H
#define MODOPERATION_H

#include "operation.h"

class ModOperation : public Operation {
public:
//    double execute(double a, double b) const override;
    Complex execute(const Complex &a, const Complex &b ) const override;
};

#endif // MODOPERATION_H
