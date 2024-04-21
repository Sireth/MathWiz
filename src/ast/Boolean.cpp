/**
 * @file Boolean.cpp
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "Boolean.h"

namespace mw {
    Boolean::Boolean(const bool value) :
        Ast(Type::boolean), m_isPointer(false), m_value(value) {
    }

    Boolean::Boolean(const bool *value) :
        Ast(Type::boolean), m_isPointer(true), m_pValue(value) {
    }

    bool Boolean::value() const {
        if (!m_isPointer) {
            return m_value;
        }
        return *m_pValue;
    }
} // mw
