// divoperation.h
#ifndef DIVOPERATION_H
#define DIVOPERATION_H

#include "operation.h"
#include <stdexcept>

class DivOperation : public Operation {
public:
    Complex execute(const Complex &a, const Complex &b) const override;  // chỉ khai báo
};

#endif // DIVOPERATION_H

