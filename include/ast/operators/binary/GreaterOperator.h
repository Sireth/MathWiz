/**
 * @file GreaterOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef GREATEROPERATOR_H
#define GREATEROPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class GreaterOperator : public BinaryOperator {
    public:
        explicit GreaterOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //GREATEROPERATOR_H
