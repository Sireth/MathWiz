/**
 * @file MultiplyOperator.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include <utility>

#include "../../../../include/ast/operators/binary/MultiplyOperator.h"

namespace mw {
    MultiplyOperator::MultiplyOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), mul) {
    }
} // mw
