/**
 * @file DivideOperator.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "DivideOperator.h"

namespace mw {
    DivideOperator::DivideOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), div) {
    }
} // mw
