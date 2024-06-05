/**
 * @file UnaryOperator.h
 *
 * @date 05.06.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef UNARYOPERATOR_H
#define UNARYOPERATOR_H

#include "Ast.h"

namespace mw {
    class UnaryOperator : public Ast {
    public:
        enum OperatorType {
            _not,

            negate,
        };

        UnaryOperator(std::shared_ptr<Ast> left, OperatorType op);

        std::shared_ptr<Ast> &left();

        OperatorType &op();

    protected:
        std::shared_ptr<Ast> m_left;

        OperatorType m_op;
    };
} // mw

#endif //UNARYOPERATOR_H
