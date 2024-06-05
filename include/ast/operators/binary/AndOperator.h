/**
 * @file AndOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef ANDOPERATOR_H
#define ANDOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class AndOperator : public BinaryOperator {
    public:
        explicit AndOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //ANDOPERATOR_H
