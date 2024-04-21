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
        explicit Number(const int *value);

        int value() const;

    protected:
        bool m_isPointer;
        union {
            int m_value;
            const int *m_pValue;
        };
    };
} // namespace mw

#endif  // NUMBER_H
