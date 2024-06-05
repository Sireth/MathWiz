/**
 * @file EvalVisitor.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */
 
#ifndef EVALVISITOR_H
#define EVALVISITOR_H

#include <boost/optional/optional.hpp>

#include "Ast.h"
#include "AstUtils.h"
#include "AstVisitor.h"
#include "Boolean.h"
#include "Number.h"
#include "String.h"
#include "BinaryOperator.h"
#include "UnaryOperator.h"

namespace mw {

class EvalVisitor : public AstVisitor {

public:
    void visit(std::shared_ptr<Ast> ast) override;

    void visit(std::shared_ptr<BinaryOperator> ast) override;

    void visit(std::shared_ptr<Number> ast) override;

    void visit(std::shared_ptr<Boolean> ast) override;

    void visit(std::shared_ptr<String> ast) override;

    void visit(std::shared_ptr<Variable> ast) override;

    void visit(std::shared_ptr<AddOperator> ast) override;

    void visit(std::shared_ptr<SubtractOperator> ast) override;

    void visit(std::shared_ptr<MultiplyOperator> ast) override;

    void visit(std::shared_ptr<DivideOperator> ast) override;

    void visit(std::shared_ptr<GreaterOperator> ast) override;

    void visit(std::shared_ptr<LessOperator> ast) override;

    void visit(std::shared_ptr<EqualOperator> ast) override;

    void visit(std::shared_ptr<NotEqualOperator> ast) override;

    void visit(std::shared_ptr<GreaterEqualOperator> ast) override;

    void visit(std::shared_ptr<LessEqualOperator> ast) override;

    void visit(std::shared_ptr<InOperator> ast) override;

    void visit(std::shared_ptr<AndOperator> ast) override;

    void visit(std::shared_ptr<OrOperator> ast) override;

    void visit(std::shared_ptr<UnaryOperator> ast) override;

    void visit(std::shared_ptr<NotOperator> ast) override;

    void visit(std::shared_ptr<NegateOperator> ast) override;

    std::shared_ptr<Ast> result() const;

    template<typename T>
        boost::optional<std::pair<T,T>> getValues(const std::shared_ptr<BinaryOperator> &ast);

private:
    std::shared_ptr<Ast> m_result;
};

    template<>
        inline boost::optional<std::pair<int64_t, int64_t>> EvalVisitor::getValues(const std::shared_ptr<BinaryOperator> &ast) {
        visit(As<Ast>(ast->left()));
        if(m_result->type() == Ast::Type::number) {
            const auto left = As<Number>(m_result)->value();
            visit(As<Ast>(ast->right()));
            if (m_result->type() != Ast::Type::number) {
                throw std::runtime_error("Right operand is not a number!");
            }
            const auto right = As<Number>(m_result)->value();
            return std::make_pair(left, right);
        }
        return boost::none;
    }

    template<>
    inline boost::optional<std::pair<std::string, std::string>> EvalVisitor::getValues(const std::shared_ptr<BinaryOperator> &ast) {
        visit(As<Ast>(ast->left()));
        if(m_result->type() == Ast::Type::string) {
            const auto left = As<String>(m_result)->value();
            visit(As<Ast>(ast->right()));
            if (m_result->type() != Ast::Type::string) {
                throw std::runtime_error("Right operand is not a string!");
            }
            const auto right = As<String>(m_result)->value();
            return std::make_pair(left, right);
        }
        return boost::none;
    }

    template<>
    inline boost::optional<std::pair<bool, bool>> EvalVisitor::getValues(const std::shared_ptr<BinaryOperator> &ast) {
        visit(As<Ast>(ast->left()));
        if(m_result->type() == Ast::Type::boolean) {
            const auto left = As<Boolean>(m_result)->value();
            visit(As<Ast>(ast->right()));
            if (m_result->type() != Ast::Type::boolean) {
                throw std::runtime_error("Right operand is not a boolean!");
            }
            const auto right = As<Boolean>(m_result)->value();
            return std::make_pair(left, right);
        }
        return boost::none;
    }
} // mw

#endif //EVALVISITOR_H
