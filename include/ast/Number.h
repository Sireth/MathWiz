/**
 * @file Number.h
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef NUMBER_H
#define NUMBER_H
#include "Ast.h"

namespace mw {
    class Number : public Ast {
    public:
        explicit Number(int value);

        int value() const;

    protected:
        int m_value;
    };
} // namespace mw

#endif  // NUMBER_H
