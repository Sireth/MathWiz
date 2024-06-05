#include "Driver.h"

#include "parser.hpp"

namespace mw {
    std::shared_ptr<Ast> Driver::result() {
        return m_result;
    }

    void Driver::setResult(std::shared_ptr<Ast> result) {
        this->m_result = std::move(result);
    }

    yy::location &Driver::location() {
        return m_location;
    }

    void Driver::setLocation(yy::location location) {
        this->m_location = location;
    }

    VariableTable &Driver::variableTable() {
        return m_variableTable;
    }

    const VariableTable & Driver::variableTable() const {
        return m_variableTable;
    }

    void Driver::setVariableTable(VariableTable variables) {
        m_variableTable = std::move(variables);
    }

    Driver::Driver() :
        trace_parsing(false)
        , trace_scanning(false)
        , scanner(*this)
        , parser(scanner, *this) {
    }

    std::shared_ptr<Ast> Driver::Parse(const std::string &f) {
        m_location.initialize(&f);

        ScanBegin(f);

        parser.set_debug_level(trace_parsing);
        parser();
        ScanEnd();

        return m_result;
    }

    void Driver::ScanBegin(const std::string &f) {
        scanner.set_debug(trace_scanning);

        input = std::stringstream(f);
        scanner.yyrestart(&input);
    }

    void Driver::ScanEnd() {
    }
}
