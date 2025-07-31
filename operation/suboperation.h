// suboperation.h
#ifndef SUBOPERATION_H
#define SUBOPERATION_H

#include "operation.h"

class SubOperation : public Operation {
public:
    Complex execute(const Complex &a, const Complex &b) const override;  // chỉ khai báo
};

#endif // SUBOPERATION_H

