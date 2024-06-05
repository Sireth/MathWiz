/**
 * @file OrOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef OROPERATOR_H
#define OROPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class OrOperator : public BinaryOperator {
    public:
        explicit OrOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //OROPERATOR_H
