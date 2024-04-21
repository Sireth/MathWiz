/**
 * @file String.cpp
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "String.h"

namespace mw {
    String::String(const std::string &value) :
        Ast(Type::string), m_isPointer(false) {
        m_value = value;
    }

    String::String(const std::string *value) :
        Ast(Type::string), m_isPointer(true) {
        m_pValue = value;
    }

    String::~String() {
        if (!m_isPointer) {
            m_value.~basic_string();
        }
    }

    const std::string &String::value() const {
        return m_value;
    }
} // mw
