/**
 * @file Boolean.cpp
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "../../include/ast/Boolean.h"

namespace mw {
    Boolean::Boolean(const bool value) :
        Ast(Type::boolean) {
        m_value = value;
    }

    bool Boolean::value() const {
        return m_value;
    }
} // mw
