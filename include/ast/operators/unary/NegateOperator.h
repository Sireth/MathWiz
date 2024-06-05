/**
 * @file NegateOperator.h
 *
 * @date 05.06.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef NEGATEOPERATOR_H
#define NEGATEOPERATOR_H

#include "UnaryOperator.h"

namespace mw {
    class NegateOperator final : public UnaryOperator {
    public:
        explicit NegateOperator(std::shared_ptr<Ast> left);
    };
} // mw

#endif //NEGATEOPERATOR_H
