#include "ast.h"

namespace sql {
    Ast::Ast(AstType type) :
        type(type) {
    }


    String::String(const std::string &value) :
        Ast(AstType::string) {
        this->value = value;
    }

    Number::Number(int value) :
        Ast(AstType::number)
        , value(value) {
    }

    Boolean::Boolean(bool value) :
        Ast(AstType::boolean) {
        this->value = value;
    }


    BinaryOperator::BinaryOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right, Type op) :
        Ast(AstType::binary_operator) {
        this->left = std::move(left);
        this->right = std::move(right);
        this->op = op;
    }

    AddOperator::AddOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), add) {
    }

    SubtractOperator::SubtractOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), sub) {
    }

    MultiplyOperator::MultiplyOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), mul) {
    }

    DivideOperator::DivideOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), div) {
    }

    GreaterOperator::GreaterOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), gr) {
    }

    LessOperator::LessOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), le) {
    }

    EqualOperator::EqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), eq) {
    }

    NotEqualOperator::NotEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), n_eq) {
    }

    GreaterEqualOperator::GreaterEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), gr_eq) {
    }

    LessEqualOperator::LessEqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), le_eq) {
    }

    InOperator::InOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), in) {
    }

    AndOperator::AndOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), _and) {
    }

    OrOperator::OrOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) :
        BinaryOperator(std::move(left), std::move(right), _or) {
    }


    void EvalVisitor::visit(std::shared_ptr<Ast> ast) {
        switch (ast->type) {
            case AstType::number: {
                visit(As<Number>(ast));
                break;
            }
            case AstType::string: {
                visit(As<String>(ast));
                break;
            }
            case AstType::binary_operator: {
                visit(As<BinaryOperator>(ast));
                break;
            }
            default:
                throw std::runtime_error("Ast is broken!");;
        }
    }

    void EvalVisitor::visit(std::shared_ptr<BinaryOperator> ast) {
        switch (ast->op) {
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

    void EvalVisitor::visit(std::shared_ptr<Boolean> ast) {
        result = As<Ast>(ast);
    }

    void EvalVisitor::visit(std::shared_ptr<String> ast) {
        result = As<Ast>(ast);
    }

    void EvalVisitor::visit(const std::shared_ptr<AddOperator> &ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            result = std::make_shared<Number>(nums.value().first + nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        result = std::make_shared<String>(strings.value().first + strings.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<SubtractOperator> ast) {
        auto res = getValues<int>(ast);
        if (res == boost::none) {
            throw std::runtime_error("Operands are not a numbers!");
        }
        result = std::make_shared<Number>(res.value().first - res.value().second);
        std::string a, b;
    }

    void EvalVisitor::visit(const std::shared_ptr<MultiplyOperator> ast) {
        auto res = getValues<int>(ast);
        if (res == boost::none) {
            throw std::runtime_error("Operands are not a numbers!");
        }
        result = std::make_shared<Number>(res.value().first * res.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<DivideOperator> ast) {
        auto res = getValues<int>(ast);
        if (res == boost::none) {
            throw std::runtime_error("Operands are not a numbers!");
        }
        result = std::make_shared<Number>(res.value().first / res.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<GreaterOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            result = std::make_shared<Boolean>(nums.value().first > nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            result = std::make_shared<Boolean>(strings.value().first > strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        result = std::make_shared<Boolean>(bools.value().first > bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<LessOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            result = std::make_shared<Boolean>(nums.value().first < nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            result = std::make_shared<Boolean>(strings.value().first < strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        result = std::make_shared<Boolean>(bools.value().first < bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<EqualOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            result = std::make_shared<Boolean>(nums.value().first == nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            result = std::make_shared<Boolean>(strings.value().first == strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        result = std::make_shared<Boolean>(bools.value().first == bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<NotEqualOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            result = std::make_shared<Boolean>(nums.value().first != nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            result = std::make_shared<Boolean>(strings.value().first != strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        result = std::make_shared<Boolean>(bools.value().first != bools.value().second);
    }

    void EvalVisitor::visit(std::shared_ptr<GreaterEqualOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            result = std::make_shared<Boolean>(nums.value().first >= nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            result = std::make_shared<Boolean>(strings.value().first >= strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        result = std::make_shared<Boolean>(bools.value().first >= bools.value().second);
    }

    void EvalVisitor::visit(std::shared_ptr<LessEqualOperator> ast) {
        auto nums = getValues<int>(ast);
        if (nums != boost::none) {
            result = std::make_shared<Boolean>(nums.value().first <= nums.value().second);
            return;
        }
        auto strings = getValues<std::string>(ast);
        if (strings != boost::none) {
            result = std::make_shared<Boolean>(strings.value().first <= strings.value().second);
            return;
        }
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not supported!");
        }
        result = std::make_shared<Boolean>(bools.value().first <= bools.value().second);
    }

    void EvalVisitor::visit(const std::shared_ptr<InOperator> ast) {
        auto strings = getValues<std::string>(ast);
        if (strings == boost::none) {
            throw std::runtime_error("Operands are not a strings!");
        }
        result = std::make_shared<Boolean>(strings.value().second.find(strings.value().first) != std::string::npos);
    }

    void EvalVisitor::visit(const std::shared_ptr<AndOperator> ast) {
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not booleans!");
        }
        result = std::make_shared<Boolean>(bools.value().first && bools.value().second);
    }

    void EvalVisitor::visit(std::shared_ptr<OrOperator> ast) {
        auto bools = getValues<bool>(ast);
        if (bools == boost::none) {
            throw std::runtime_error("Operands are not booleans!");
        }
        result = std::make_shared<Boolean>(bools.value().first || bools.value().second);
    }

    void EvalVisitor::visit(std::shared_ptr<Number> ast) {
        result = As<Ast>(ast);
    }

    std::shared_ptr<Ast> new_string(const std::string &value) {
        return std::make_shared<String>(value);
    }

    std::shared_ptr<Ast> new_number(int value) {
        return std::make_shared<Number>(value);
    }

    std::shared_ptr<Ast> new_add_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<AddOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_subtract_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<SubtractOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_multiply_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<MultiplyOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_divide_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<DivideOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_greater_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<GreaterOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_less_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<LessOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<EqualOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_not_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<NotEqualOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_greater_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<GreaterEqualOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_less_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<LessEqualOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_in_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<InOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_and_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<AndOperator>(std::move(left), std::move(right));
    }

    std::shared_ptr<Ast> new_or_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right) {
        return std::make_shared<OrOperator>(std::move(left), std::move(right));
    }
} // namespace sql
