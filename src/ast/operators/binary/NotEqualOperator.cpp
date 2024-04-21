/**
 * @file NotEqualOperator.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "NotEqualOperator.h"

namespace mw {
    NotEqualOperator::NotEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), n_eq) {
    }
} // mw
