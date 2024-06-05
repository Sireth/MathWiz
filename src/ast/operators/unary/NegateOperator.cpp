/**
 * @file NegateOperator.cpp
 *
 * @date 05.06.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "NegateOperator.h"

namespace mw {
    NegateOperator::NegateOperator(std::shared_ptr<Ast> left):
        UnaryOperator(std::move(left), negate) {
    }
} // mw
