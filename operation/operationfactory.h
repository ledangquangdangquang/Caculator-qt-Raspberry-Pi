// operationfactory.h
#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include <QChar>
#include <memory>
#include "operation.h"

class OperationFactory {
public:
    static std::unique_ptr<Operation> getOperation(const QString& op);
};

#endif // OPERATIONFACTORY_H
