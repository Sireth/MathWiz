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
%option yyclass="Scanner"

%{

  yy::parser::symbol_type make_NUM(
    const std::string &s,
    const yy::parser::location_type& loc
  );

%}


int   [0-9]+
blank [ \t\r]


%{
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{

  yy::location& loc = driver.location;
  // Code run each time yylex is called.
  loc.step();

%}


{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"("        return yy::parser::make_LPAREN   (loc);
")"        return yy::parser::make_RPAREN   (loc);
"*"        return yy::parser::make_MULT     (loc);
"/"        return yy::parser::make_DIV      (loc);
"+"        return yy::parser::make_PLUS     (loc);
"-"        return yy::parser::make_MINUS    (loc);
">"        return yy::parser::make_GR       (loc);
"<"        return yy::parser::make_LE       (loc);
"=="       return yy::parser::make_EQ       (loc);
">="       return yy::parser::make_GR_EQ    (loc);
"<="       return yy::parser::make_LE_EQ    (loc);
"!="       return yy::parser::make_N_EQ     (loc);
"!"        return yy::parser::make_NOT      (loc);
"in"       return yy::parser::make_IN       (loc);


{int}      return make_NUM (yytext, loc);


.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }

<<EOF>>    return yy::parser::make_END (loc);

%%

yy::parser::symbol_type make_NUM(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  return yy::parser::make_NUM(std::stoll(s), loc);
}
