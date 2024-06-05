/**
 * @file Boolean.h
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "Ast.h"

namespace mw {
    class Boolean final : public Ast {
    public:
        explicit Boolean(bool value);
        explicit Boolean(const bool *value);

        bool value() const;

    protected:
        bool m_isPointer;
        union {
            bool m_value;
            const bool *m_pValue;
        };
    };
} // mw

#endif //BOOLEAN_H
