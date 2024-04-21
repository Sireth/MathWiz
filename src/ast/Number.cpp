/**
 * @file Number.cpp
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "../../include/ast/Number.h"

namespace mw {
    Number::Number(const int value) :
        Ast(Type::number), m_value(value) {
    }

    int Number::value() const {
        return m_value;
    }
} // namespace mw
