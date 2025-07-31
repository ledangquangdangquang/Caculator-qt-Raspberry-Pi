// muloperation.h
#ifndef MULOPERATION_H
#define MULOPERATION_H

#include "operation.h"

class MulOperation : public Operation {
public:
    Complex execute(const Complex &a, const Complex &b) const override;  // chỉ khai báo
};

#endif // MULOPERATION_H

