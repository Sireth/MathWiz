/**
 * @file SubtractOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef SUBTRACTOPERATOR_H
#define SUBTRACTOPERATOR_H

#include "BinaryOperator.h"

namespace mw {
    class SubtractOperator : public BinaryOperator {
    public:
        explicit SubtractOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //SUBTRACTOPERATOR_H
