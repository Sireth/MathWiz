/**
 * @file VariableTable.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef VARIABLETABLE_H
#define VARIABLETABLE_H

#include <unordered_map>
#include <memory>

#include "AstUtils.h"
#include "Variable.h"

namespace mw {
    class Variable;

    class VariableTable {
    public:
        VariableTable();

        std::shared_ptr<Variable> getVariable(const std::string &name) const;

        template<typename T>
        void setVariable(const std::string &name, const T &value);

        template<typename T>
        void setVariable(const std::string &name, const T *value);

        template<typename T>
        void setVariable(const std::string &name, T *value);

    protected:
        std::unordered_map<std::string, std::shared_ptr<Variable> > m_variables;
    };

    template<>
    inline void VariableTable::setVariable(const std::string &name, const int *value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_number(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }

    template<>
    inline void VariableTable::setVariable(const std::string &name, int *value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_number(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }

    template<>
    inline void VariableTable::setVariable(const std::string &name, const int &value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_number(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }
    template<>
    inline void VariableTable::setVariable(const std::string &name, const bool *value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_boolean(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }

    template<>
    inline void VariableTable::setVariable(const std::string &name, bool *value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_boolean(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }

    template<>
    inline void VariableTable::setVariable(const std::string &name, const bool &value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_boolean(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }
    template<>
    inline void VariableTable::setVariable(const std::string &name, const std::string *value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_string(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }

    template<>
    inline void VariableTable::setVariable(const std::string &name, std::string *value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_string(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }

    template<>
    inline void VariableTable::setVariable(const std::string &name, const std::string &value) {
        const auto it = m_variables.insert({name, std::make_shared<Variable>(name, new_string(value))});
        if (!it.second) {
            throw std::runtime_error("Variable '" + name + "' already exists");
        }
    }
} // mw

#endif //VARIABLETABLE_H
