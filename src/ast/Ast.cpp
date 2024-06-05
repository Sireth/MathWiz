/**
 * @file Ast.cpp
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "Ast.h"

namespace mw {
    Ast::Ast(const Type type) :
        m_type(type) {
    }

    Ast::Type Ast::type() const {
        return m_type;
    }
} // mw
