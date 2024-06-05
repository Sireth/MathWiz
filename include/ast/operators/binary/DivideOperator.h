/**
 * @file DivideOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef DIVIDEOPERATOR_H
#define DIVIDEOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class DivideOperator : public BinaryOperator {
    public:
        explicit DivideOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //DIVIDEOPERATOR_H
