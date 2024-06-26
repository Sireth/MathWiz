/**
 * @file VariableTable.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */
 
#include "VariableTable.h"

namespace mw {
    VariableTable::VariableTable() = default;

    std::shared_ptr<Variable> VariableTable::getVariable(const std::string &name) const {
        const auto it = m_variables.find(name);
        if(it == m_variables.end()) {
            return nullptr;
        }
        return it->second;
    }

    void VariableTable::setVariable(const std::shared_ptr<Variable>& variable) {
        auto name = variable->name();
        const auto it = m_variables.insert({name, variable});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }
} // mw