#include "operationfactory.h"
#include "addoperation.h" // +
#include "suboperation.h" // -
#include "muloperation.h" // *
#include "divoperation.h" // /
#include "sqrtoperation.h"// sqrt
#include "modoperation.h" // mod
#include "powoperation.h" // ^
#include "sinoperation.h" // sin
#include "cosoperation.h" // cos
#include "tanoperation.h" // tan
#include "cotoperation.h" // cotan
#include "logoperation.h" // log
#include "lnoperation.h" //  ln
#include "absoperation.h" //  abs
#include "sinhoperation.h" // sinh
#include "coshoperation.h" // cosh
#include "tanhoperation.h" // tanh
#include "reoperation.h" // Re
#include "imoperation.h" // Im
#include "argoperation.h" // Arg
#include "conjoperation.h"// Conj
#include <QString>

std::unique_ptr<Operation> OperationFactory::getOperation(const QString& op) {
    if (op == QString("+")) return std::make_unique<AddOperation>();
    else if (op == QString("-")) return std::make_unique<SubOperation>();
    else if (op == QString("*")) return std::make_unique<MulOperation>();
    else if (op == QString("/")) return std::make_unique<DivOperation>();
    else if (op == QString("sqrt")) return std::make_unique<SqrtOperation>();
    else if (op == QString("mod")) return std::make_unique<ModOperation>();
    else if (op == QString("^")) return std::make_unique<PowOperation>();
    else if (op == QString("sin")) return std::make_unique<SinOperation>();
    else if (op == QString("cos")) return std::make_unique<CosOperation>();
    else if (op == QString("tan")) return std::make_unique<TanOperation>();
    else if (op == QString("cot")) return std::make_unique<CotOperation>();
    else if (op == QString("log")) return std::make_unique<LogOperation>();
    else if (op == QString("ln")) return std::make_unique<LnOperation>();
    else if (op == QString("abs")) return std::make_unique<AbsOperation>();
    else if (op == QString("sinh")) return std::make_unique<SinhOperation>();
    else if (op == QString("cosh")) return std::make_unique<CoshOperation>();
    else if (op == QString("tanh")) return std::make_unique<TanhOperation>();
    else if (op == QString("Re")) return std::make_unique<ReOperation>();
    else if (op == QString("Im")) return std::make_unique<ImOperation>();
    else if (op == QString("Arg")) return std::make_unique<ArgOperation>();
    else if (op == QString("conj")) return std::make_unique<ConjOperation>();
    else return nullptr;
}
