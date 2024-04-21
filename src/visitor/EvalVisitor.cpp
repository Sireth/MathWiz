/**
 * @file EvalVisitor.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */
 
#include "EvalVisitor.h"

#include "OrOperator.h"
#include "AndOperator.h"
#include "InOperator.h"
#include "LessEqualOperator.h"
#include "GreaterEqualOperator.h"
#include "NotEqualOperator.h"
#include "EqualOperator.h"
#include "LessOperator.h"
#include "GreaterOperator.h"
#include "DivideOperator.h"
#include "MultiplyOperator.h"
#include "SubtractOperator.h"
#include "AddOperator.h"
#include "AstUtils.h"

namespace mw {

    void EvalVisitor::visit(const std::shared_ptr<Ast> ast) {
        switch (ast->type()) {
            case Ast::Type::number: {
                visit(As<Number>(ast));
                break;
            }
            case Ast::Type::string: {
                visit(As<String>(ast));
                break;
            }
            case Ast::Type::binary_operator: {
                visit(As<BinaryOperator>(ast));
                break;
            }
            default:
                throw std::runtime_error("Ast is broken!");;
        }
    }

    void EvalVisitor::visit(const std::shared_ptr<BinaryOperator> ast) {
        switch (ast->op()) {
            case BinaryOperator::add: {
                visit(As<AddOperator>(ast));
                break;
            }
            case BinaryOperator::sub: {
                visit(As<SubtractOperator>(ast));
                break;
            }
            case BinaryOperator::mul: {
                visit(As<MultiplyOperator>(ast));
                break;
            }
            case BinaryOperator::div: {
                visit(As<DivideOperator>(ast));
                break;
            }
            case BinaryOperator::gr: {
                visit(As<GreaterOperator>(ast));
                break;
            }
            case BinaryOperator::le: {
                visit(As<LessOperator>(ast));
                break;
            }
            case BinaryOperator::eq: {
                visit(As<EqualOperator>(ast));
                break;
            }
            case BinaryOperator::n_eq: {
                visit(As<NotEqualOperator>(ast));
                break;
            }
            case BinaryOperator::gr_eq: {
                visit(As<GreaterEqualOperator>(ast));
                break;
            }
            case BinaryOperator::le_eq: {
                visit(As<LessEqualOperator>(ast));
                break;
            }
            case BinaryOperator::in: {
                visit(As<InOperator>(ast));
                break;
            }
            case BinaryOperator::_and: {
                visit(As<AndOperator>(ast));
                break;
            }
            case BinaryOperator::_or: {
                visit(As<OrOperator>(ast));
                break;
            }
            default:
                throw std::runtime_error("Ast is broken!");
        }
    }

    void EvalVisitor::visit(const std::shared_ptr<Boolean> ast) {
        m_result = As<Ast>(ast);
    }

    void EvalVisitor::visit(const std::shared_ptr<String> ast) {
        m_result = As<Ast>(ast);
    }

    void EvalVisitor::visit(std::shared_ptr<AddOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            m_result = std::make_shared<Number>(nums.value().first + nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        m_result = std::make_shared<String>(strings.value().first + strings.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<SubtractOperator> ast) {
        auto res = getValues<int>(ast);
        if (res == boost::none) {
            throw std::runtime_error("Operands are not a numbers!");
        }
        m_result = std::make_shared<Number>(res.value().first - res.value().second);
        std::string a, b;
    }

    void EvalVisitor::visit(const std::shared_ptr<MultiplyOperator> ast) {
        auto res = getValues<int>(ast);
        if (res == boost::none) {
            throw std::runtime_error("Operands are not a numbers!");
        }
        m_result = std::make_shared<Number>(res.value().first * res.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<DivideOperator> ast) {
        auto res = getValues<int>(ast);
        if (res == boost::none) {
            throw std::runtime_error("Operands are not a numbers!");
        }
        m_result = std::make_shared<Number>(res.value().first / res.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<GreaterOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            m_result = std::make_shared<Boolean>(nums.value().first > nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            m_result = std::make_shared<Boolean>(strings.value().first > strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        m_result = std::make_shared<Boolean>(bools.value().first > bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<LessOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            m_result = std::make_shared<Boolean>(nums.value().first < nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            m_result = std::make_shared<Boolean>(strings.value().first < strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        m_result = std::make_shared<Boolean>(bools.value().first < bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<EqualOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            m_result = std::make_shared<Boolean>(nums.value().first == nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            m_result = std::make_shared<Boolean>(strings.value().first == strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        m_result = std::make_shared<Boolean>(bools.value().first == bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<NotEqualOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            m_result = std::make_shared<Boolean>(nums.value().first != nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            m_result = std::make_shared<Boolean>(strings.value().first != strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        m_result = std::make_shared<Boolean>(bools.value().first != bools.value().second);
    }

    void EvalVisitor::visit(std::shared_ptr<GreaterEqualOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            m_result = std::make_shared<Boolean>(nums.value().first >= nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            m_result = std::make_shared<Boolean>(strings.value().first >= strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        m_result = std::make_shared<Boolean>(bools.value().first >= bools.value().second);
    }

    void EvalVisitor::visit(std::shared_ptr<LessEqualOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            m_result = std::make_shared<Boolean>(nums.value().first <= nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            m_result = std::make_shared<Boolean>(strings.value().first <= strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        m_result = std::make_shared<Boolean>(bools.value().first <= bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<InOperator> ast) {
        auto strings = getValues<std::string>(ast);
        if (strings == boost::none) {
            throw std::runtime_error("Operands are not a strings!");
        }
        m_result = std::make_shared<Boolean>(strings.value().second.find(strings.value().first) != std::string::npos);
    }

    void EvalVisitor::visit(const std::shared_ptr<AndOperator> ast) {
        /// TODO: убрать преобразование правой части, если левая и так false
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not booleans!");
        }
        m_result = std::make_shared<Boolean>(bools.value().first && bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<OrOperator> ast) {
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not booleans!");
        }
        m_result = std::make_shared<Boolean>(bools.value().first || bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<Number> ast) {
        m_result = As<Ast>(ast);
    }

    std::shared_ptr<Ast> EvalVisitor::result() const {
        return m_result;
    }
} // mw