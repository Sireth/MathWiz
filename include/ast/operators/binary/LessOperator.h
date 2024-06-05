/**
 * @file LessOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef LESSOPERATOR_H
#define LESSOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class LessOperator : public BinaryOperator {
    public:
        explicit LessOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //LESSOPERATOR_H
