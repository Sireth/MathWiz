/**
 * @file LessEqualOperator.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "LessEqualOperator.h"

namespace mw {
    LessEqualOperator::LessEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), le_eq) {
    }
} // mw
