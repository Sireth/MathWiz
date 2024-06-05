/**
 * @file Scanner.cpp
 *
 * @date 21.04.2024
 * @author d.usov\@kpda.ru
 *
 * (c) 2024, SWD Embedded Systems Limited, http://www.kpda.ru
 */

#include "Scanner.h"

namespace mw {
    Scanner::Scanner(Driver &driver) :
        m_driver(driver) {
    }

    Scanner::~Scanner() = default;

    Driver &Scanner::driver() const {
        return m_driver;
    }
}
