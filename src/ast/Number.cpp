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
        Ast(Type::number), m_isPointer(false), m_value(value) {
    }

    Number::Number(const int *value) :
        Ast(Type::number), m_isPointer(true), m_pValue(value) {
    }

    int Number::value() const {
        if(!m_isPointer) {
            return m_value;
        }
        return *m_pValue;
    }
} // namespace mw
