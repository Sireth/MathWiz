#pragma once

#include <memory>
#include <sstream>
#include <string>

#include "parser.hpp"
#include "Scanner.h"

namespace sql {
	struct Ast;
}

class Driver {
   public:
	Driver();

	std::shared_ptr<sql::Ast> Parse(const std::string &f);
	void ScanBegin(const std::string &query);
	void ScanEnd();

	friend class Scanner;

	std::shared_ptr<sql::Ast> result;

	yy::location location;

private:
	bool trace_parsing;
	bool trace_scanning;


	Scanner scanner;
	yy::parser parser;

	std::stringstream input;
};
