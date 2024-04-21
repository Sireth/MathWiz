/**
 * @file BinaryOperator.cpp
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "BinaryOperator.h"

namespace mw {
    BinaryOperator::BinaryOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right, const OperatorType op):
        Ast(Type::binary_operator) {
        this->m_left = std::move(left);
        this->m_right = std::move(right);
        this->m_op = op;
    }

    std::shared_ptr<Ast> & BinaryOperator::left() {
        return m_left;
    }

    std::shared_ptr<Ast> & BinaryOperator::right() {
        return m_right;
    }

    BinaryOperator::OperatorType & BinaryOperator::op() {
        return m_op;
    }
} // mw
