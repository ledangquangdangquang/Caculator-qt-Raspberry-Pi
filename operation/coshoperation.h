#ifndef COSHOPERATION_H
#define COSHOPERATION_H


#include "operation.h"

class CoshOperation : public Operation {
public:
 Complex execute(const Complex &a, const Complex &b = Complex(0)) const override;
};

#endif // COSHOPERATION_H
