/**
 * @file Variable.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "Variable.h"

#include <utility>

namespace mw {
    Variable::Variable(std::string name, const std::shared_ptr<Ast> &value) :
        Ast(Type::variable){
        m_name = std::move(name);
        m_value = value;
    }

    const std::string & Variable::name() const {
        return m_name;
    }

    const std::shared_ptr<Ast> & Variable::value() const {
        return m_value;
    }
} // mw
