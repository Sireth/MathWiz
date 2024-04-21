/**
 * @file Variable.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef VARIABLE_H
#define VARIABLE_H

#include "Ast.h"

namespace mw {
    class Variable : public Ast {
    public:
        explicit Variable(std::string name, const std::shared_ptr<Ast> &value);

        const std::string &name() const;

        const std::shared_ptr<Ast> &value() const;

    protected:
        std::string m_name;
        std::shared_ptr<Ast> m_value;
    };
} // mw

#endif //VARIABLE_H
