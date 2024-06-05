/**
 * @file AddOperator.h
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef ADDOPERATOR_H
#define ADDOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class AddOperator : public BinaryOperator {
    public:
        explicit AddOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //ADDOPERATOR_H
