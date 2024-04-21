%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "parser.hpp"
    #include "Driver.h"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="mw::Scanner"

%{

  yy::parser::symbol_type make_NUM(
    const std::string &s,
    const yy::parser::location_type& loc
  );

  yy::parser::symbol_type make_QUOTED(
      const std::string &s,
      const yy::parser::location_type& loc
  );

  yy::parser::symbol_type make_ID(
      const std::string &s,
      const mw::Driver& driver,
      const yy::parser::location_type& loc
  );

  yy::parser::symbol_type make_BOOL(
      const std::string &s,
      const yy::parser::location_type& loc
  );

%}


int             [0-9]+
boolean         true|false
blank           [ \t\r]
id              [A-Za-z_][A-Za-z0-9_]*
quoted_string   \"[^\"]*\"


%{
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{

  yy::location& loc = driver().location();
  // Code run each time yylex is called.
  loc.step();

%}


{blank}+        loc.step ();
\n+             loc.lines (yyleng); loc.step ();

"("             return yy::parser::make_LPAREN   (loc);
")"             return yy::parser::make_RPAREN   (loc);
"*"             return yy::parser::make_MULT     (loc);
"/"             return yy::parser::make_DIV      (loc);
"+"             return yy::parser::make_PLUS     (loc);
"-"             return yy::parser::make_MINUS    (loc);
">"             return yy::parser::make_GR       (loc);
"<"             return yy::parser::make_LE       (loc);
"=="            return yy::parser::make_EQ       (loc);
">="            return yy::parser::make_GR_EQ    (loc);
"<="            return yy::parser::make_LE_EQ    (loc);
"!="            return yy::parser::make_N_EQ     (loc);
"!"             return yy::parser::make_NOT      (loc);
"&&"            return yy::parser::make_AND      (loc);
"||"            return yy::parser::make_OR       (loc);
"in"            return yy::parser::make_IN       (loc);

{boolean}       return make_BOOL         (yytext, loc);

{id}            return make_ID (yytext, driver(), loc);


{int}           return make_NUM          (yytext, loc);
{quoted_string} return make_QUOTED       (yytext, loc);


.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }

<<EOF>>    return yy::parser::make_END (loc);

%%

yy::parser::symbol_type make_NUM(const std::string &s, const yy::parser::location_type& loc) {
    return yy::parser::make_NUM(std::stoll(s), loc);
};

yy::parser::symbol_type make_QUOTED(const std::string &s, const yy::parser::location_type& loc) {
    return yy::parser::make_STR(s.substr(1, s.length() - 2).c_str(), loc);
};

yy::parser::symbol_type make_BOOL(const std::string &s, const yy::parser::location_type& loc) {
    if(s=="true"){
        return yy::parser::make_BOOL(true, loc);
    }
    return yy::parser::make_BOOL(false, loc);
};

yy::parser::symbol_type make_ID(const std::string &s, const mw::Driver& driver, const yy::parser::location_type& loc) {
    auto variable = driver.variableTable().getVariable(s);
    if(variable){
        return yy::parser::make_ID(variable, loc);
    }
    throw yy::parser::syntax_error(loc, "undefined variable: " + s);
};

