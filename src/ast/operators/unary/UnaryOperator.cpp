/**
 * @file UnaryOperator.cpp
 *
 * @date 05.06.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "UnaryOperator.h"

#include <utility>

namespace mw {
    UnaryOperator::UnaryOperator(std::shared_ptr<Ast> left, const OperatorType op) :
        Ast(Type::unary_operator) {
        m_left = std::move(left);
        m_op = op;
    }

    std::shared_ptr<Ast> & UnaryOperator::left() {
        return m_left;
    }

    UnaryOperator::OperatorType & UnaryOperator::op() {
        return m_op;
    }
} // mw
