/**
 * @file InOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef INOPERATOR_H
#define INOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class InOperator : public BinaryOperator {
    public:
        explicit InOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //INOPERATOR_H
