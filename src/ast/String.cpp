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
        Ast(Type::string) {
        m_value = value;
    }

    const std::string &String::value() const {
        return m_value;
    }
} // mw
