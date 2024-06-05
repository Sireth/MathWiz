/**
 * @file NotEqualOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef NOTEQUALOPERATOR_H
#define NOTEQUALOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class NotEqualOperator : public BinaryOperator {
    public:
        explicit NotEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //NOTEQUALOPERATOR_H
