#pragma once

#include <sstream>

#include "parser.hpp"
#include "Scanner.h"

namespace mw {
    class Driver {
    public:
        Driver();

        std::shared_ptr<Ast> Parse(const std::string &f);

        void ScanBegin(const std::string &f);

        void ScanEnd();

        const std::shared_ptr<Ast> & result() const;

        void setResult(std::shared_ptr<Ast> result);

        yy::location & location();

        void setLocation(yy::location location);


        friend class Scanner;

    private:
        bool trace_parsing;
        bool trace_scanning;


        Scanner scanner;
        yy::parser parser;

        std::stringstream input;

        std::shared_ptr<Ast> m_result;
        yy::location m_location;
    };
}
