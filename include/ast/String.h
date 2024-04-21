/**
 * @file String.h
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef STRING_H
#define STRING_H

#include <string>

#include "Ast.h"

namespace mw {
    class String final : public Ast {
    public:
        explicit String(const std::string &value);

        const std::string &value() const;

    protected:
        std::string m_value;
    };
} // mw

#endif //STRING_H
