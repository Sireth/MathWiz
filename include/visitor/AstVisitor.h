/**
 * @file AstVisitor.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef ASTVISITOR_H
#define ASTVISITOR_H

#include <memory>

namespace mw {
    class NegateOperator;
    class NotOperator;
    class Variable;
    class OrOperator;
    class AndOperator;
    class InOperator;
    class LessEqualOperator;
    class GreaterEqualOperator;
    class NotEqualOperator;
    class EqualOperator;
    class LessOperator;
    class GreaterOperator;
    class DivideOperator;
    class MultiplyOperator;
    class SubtractOperator;
    class AddOperator;
    class String;
    class Boolean;
    class Number;
    class BinaryOperator;
    class UnaryOperator;
    class Ast;

    class AstVisitor {
    public:
        virtual ~AstVisitor() = default;

        virtual void visit(std::shared_ptr<Ast> ast) = 0;

        virtual void visit(std::shared_ptr<BinaryOperator> ast) = 0;

        virtual void visit(std::shared_ptr<Number> ast) = 0;

        virtual void visit(std::shared_ptr<Boolean> ast) = 0;

        virtual void visit(std::shared_ptr<String> ast) = 0;

        virtual void visit(std::shared_ptr<Variable> ast) = 0;

        virtual void visit(std::shared_ptr<AddOperator> ast) = 0;

        virtual void visit(std::shared_ptr<SubtractOperator> ast) = 0;

        virtual void visit(std::shared_ptr<MultiplyOperator> ast) = 0;

        virtual void visit(std::shared_ptr<DivideOperator> ast) = 0;

        virtual void visit(std::shared_ptr<GreaterOperator> ast) = 0;

        virtual void visit(std::shared_ptr<LessOperator> ast) = 0;

        virtual void visit(std::shared_ptr<EqualOperator> ast) = 0;

        virtual void visit(std::shared_ptr<NotEqualOperator> ast) = 0;

        virtual void visit(std::shared_ptr<GreaterEqualOperator> ast) = 0;

        virtual void visit(std::shared_ptr<LessEqualOperator> ast) = 0;

        virtual void visit(std::shared_ptr<InOperator> ast) = 0;

        virtual void visit(std::shared_ptr<AndOperator> ast) = 0;

        virtual void visit(std::shared_ptr<OrOperator> ast) = 0;

        virtual void visit(std::shared_ptr<UnaryOperator> ast) = 0;

        virtual void visit(std::shared_ptr<NotOperator> ast) = 0;

        virtual void visit(std::shared_ptr<NegateOperator> ast) = 0;
    };
} // mw

#endif //ASTVISITOR_H
