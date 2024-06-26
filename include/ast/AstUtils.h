/**
 * @file AstUtils.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef ASTUTILS_H
#define ASTUTILS_H

#include <memory>

#include "BinaryOperator.h"
#include "UnaryOperator.h"

namespace mw {
    std::shared_ptr<Ast> new_name(std::string value);

    std::shared_ptr<Ast> new_string(const std::string &value);
    std::shared_ptr<Ast> new_string(const std::string *value);

    std::shared_ptr<Ast> new_number(int64_t value);
    std::shared_ptr<Ast> new_number(const int64_t *value);

    std::shared_ptr<Ast> new_boolean(bool value);
    std::shared_ptr<Ast> new_boolean(const bool *value);

    std::shared_ptr<Ast> new_binary_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right,
                                             BinaryOperator::Type type);

    std::shared_ptr<Ast> new_add_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_subtract_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_multiply_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_divide_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_greater_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_less_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_not_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_greater_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_less_equal_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_in_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_and_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_or_operator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);

    std::shared_ptr<Ast> new_variable(const std::string &name, std::shared_ptr<Ast> value);

    std::shared_ptr<Ast> new_unary_operator(std::shared_ptr<Ast> left, UnaryOperator::Type type);

    std::shared_ptr<Ast> new_not_operator(std::shared_ptr<Ast> left);

    std::shared_ptr<Ast> new_negate_operator(std::shared_ptr<Ast> left);

    template<class AstClass>
    std::shared_ptr<AstClass> As(const std::shared_ptr<Ast> ast) {
        return std::dynamic_pointer_cast<AstClass>(ast);
    }
} // mw

#endif //ASTUTILS_H
