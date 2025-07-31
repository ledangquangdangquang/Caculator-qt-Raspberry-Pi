#ifndef ADDOPERATION_H
#define ADDOPERATION_H

#include "operation.h"

class AddOperation : public Operation {
public:
    Complex execute(const Complex &a, const Complex &b) const override;  // chỉ khai báo
};

#endif

