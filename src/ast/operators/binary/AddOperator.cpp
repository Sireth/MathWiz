/**
 * @file AddOperator.cpp
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "AddOperator.h"

namespace mw {
    AddOperator::AddOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), add) {
    }
} // mw
