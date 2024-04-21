#pragma once

#if !defined(yyFlexLexerOnce)
#	include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL yy::parser::symbol_type mw::Scanner::ScanToken() /*mw::Scanner::ScanToken() definition*/

#include "parser.hpp"

namespace mw {
    class Driver;

    class Scanner : public yyFlexLexer {
    public:
        explicit Scanner(Driver &driver);

        virtual yy::parser::symbol_type ScanToken();

        ~Scanner() override;

        Driver &driver() const;

    protected:
        Driver &m_driver;
    };
}
