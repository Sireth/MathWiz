/**
 * @file AstUtils.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */
 
#include "AstUtils.h"

#include "AddOperator.h"
#include "AndOperator.h"
#include "Boolean.h"
#include "DivideOperator.h"
#include "EqualOperator.h"
#include "GreaterEqualOperator.h"
#include "GreaterOperator.h"
#include "InOperator.h"
#include "LessEqualOperator.h"
#include "LessOperator.h"
#include "MultiplyOperator.h"
#include "NotEqualOperator.h"
#include "Number.h"
#include "OrOperator.h"
#include "String.h"
#include "SubtractOperator.h"
#include "Variable.h"

namespace mw {

    std::shared_ptr<Ast> new_string(const std::string &value) {
        return std::make_shared<String>(value);
    }

    std::shared_ptr<Ast> new_string(const std::string *value) {
        return std::make_shared<String>(value);
    }

    std::shared_ptr<Ast> new_number(int64_t value) {
        return std::make_shared<Number>(value);
    }

    std::shared_ptr<Ast> new_number(const int64_t *value) {
        return std::make_shared<Number>(value);
    }

    std::shared_ptr<Ast> new_boolean(bool value) {
        return std::make_shared<Boolean>(value);
    }

    std::shared_ptr<Ast> new_boolean(const bool *value) {
        return std::make_shared<Boolean>(value);
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

    std::shared_ptr<Ast> new_variable(const std::string &name, std::shared_ptr<Ast> value) {
        return std::make_shared<Variable>(name, std::move(value));
    }
} // mw