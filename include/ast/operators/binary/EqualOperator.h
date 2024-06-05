/**
 * @file EqualOperator.h
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#ifndef EQUALOPERATOR_H
#define EQUALOPERATOR_H
#include "BinaryOperator.h"

namespace mw {
    class EqualOperator : public BinaryOperator {
    public:
        explicit EqualOperator(std::shared_ptr<Ast> left, std::shared_ptr<Ast> right);
    };
} // mw

#endif //EQUALOPERATOR_H
