/**
 * @file LessEqualOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef LESSEQUALOPERATOR_H
#define LESSEQUALOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class LessEqualOperator : public BinaryOperator {
    public:
        explicit LessEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //LESSEQUALOPERATOR_H
