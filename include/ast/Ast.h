/**
 * @file Ast.h
 *
 * @date 20.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef AST_H
#define AST_H
#include <memory>

namespace mw {
    class Ast {
    public:
        enum class Type {
            name,
            string,
            number,
            boolean,
            variable,
            binary_operator,
        };

        explicit Ast(Type type);

        virtual ~Ast() = default;

        Type type() const;

    protected:
        Type m_type;
    };
} // namespace mw

#endif  // AST_H
