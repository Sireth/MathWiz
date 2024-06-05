/**
 * @file BinaryOperator.h
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include "Ast.h"

namespace mw {
    class BinaryOperator : public Ast {
    public:
        enum OperatorType {
            add,
            sub,
            mul,
            div,

            gr,
            le,
            eq,
            gr_eq,
            le_eq,
            n_eq,

            in,

            _and,
            _or
        };

        BinaryOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right, OperatorType op);

        std::shared_ptr<Ast> & left();

        std::shared_ptr<Ast> & right();

        OperatorType & op();

    protected:

        std::shared_ptr<Ast> m_left;

        std::shared_ptr<Ast> m_right;

        OperatorType m_op;
    };
} // mw

#endif //BINARYOPERATOR_H
