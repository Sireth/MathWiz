/**
 * @file GreaterEqualOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef GREATEREQUALOPERATOR_H
#define GREATEREQUALOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class GreaterEqualOperator : public BinaryOperator {
    public:
        explicit GreaterEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //GREATEREQUALOPERATOR_H
