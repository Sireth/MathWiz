/**
 * @file NotOperator.h
 *
 * @date 05.06.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef NOTOPERATOR_H
#define NOTOPERATOR_H
#include "UnaryOperator.h"

namespace mw {
    class NotOperator final : public UnaryOperator {
    public:
        explicit NotOperator(std::shared_ptr<Ast> left);
    };
} // mw

#endif //NOTOPERATOR_H
