/**
 * @file MultiplyOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef MULTIPLYOPERATOR_H
#define MULTIPLYOPERATOR_H
#include "BinaryOperator.h"


namespace mw {
    class MultiplyOperator : public BinaryOperator {
    public:
        explicit MultiplyOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //MULTIPLYOPERATOR_H
