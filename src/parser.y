%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <sstream>
    #include <string>
    #include "Ast.h"
    #include "AstUtils.h"

    namespace mw {
        class Scanner;
        class Driver;
    }
}

// %param { std::shared_ptr<Ast>& result }

%define parse.trace
%define parse.error verbose

%code {
    #include "Scanner.h"
    #include "Driver.h"

    static yy::parser::symbol_type yylex(mw::Scanner &scanner, mw::Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { mw::Scanner &scanner }
%lex-param { mw::Driver &driver }
%parse-param { mw::Scanner &scanner }
%parse-param { mw::Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0       "end of file"

    // help
    LPAREN      "("
    RPAREN      ")"
    MULT        "*"
    DIV         "/"
    PLUS        "+"
    MINUS       "-"
    
    GR          ">"
    LE          "<"
    EQ          "=="
    GR_EQ       ">="
    LE_EQ       "<="
    N_EQ        "!="
    IN          "in"

    AND         "&&"
    OR          "||"
    NOT         "!"
;

%token <int> NUM "number"
%token <bool> BOOL "boolean"
%token <std::string> STR "string"
%token <std::shared_ptr<mw::Ast>> ID "var"

// Uncomment this after complete

%nterm <std::shared_ptr<mw::Ast>> expr
%nterm <std::shared_ptr<mw::Ast>> factor
%nterm <std::shared_ptr<mw::Ast>> and_expr
%nterm <std::shared_ptr<mw::Ast>> comp_expr
%nterm <std::shared_ptr<mw::Ast>> add_expr
%nterm <std::shared_ptr<mw::Ast>> mul_expr


// %nterm <std::shared_ptr<mw::Ast>> query
// %nterm <std::shared_ptr<mw::Ast>> select_query
// %nterm <std::shared_ptr<mw::Ast>> insert_query
// %nterm <std::shared_ptr<mw::Ast>> index_name
// %nterm <std::shared_ptr<Where>> where_clause
// %nterm <std::optional<std::string>> match_expr
// %nterm <std::shared_ptr<List>> namelist
// %nterm <int> limit

// %printer { yyo << $$; } <*>;

// HINT: Use $$->SetLocation(@$);

%%

%start calc;

calc:
    expr { driver.setResult($1); }
    ;

expr:
    and_expr
    | expr "||" and_expr { $$ = mw::new_or_operator($1, $3); }
    ;

and_expr:
    comp_expr
    | and_expr "&&" comp_expr { $$ = mw::new_and_operator($1, $3); }
    ;

comp_expr:
    add_expr
    | comp_expr "<" add_expr { $$ = mw::new_less_operator($1, $3); }
    | comp_expr "<=" add_expr { $$ = mw::new_less_equal_operator($1, $3); }
    | comp_expr ">" add_expr { $$ = mw::new_greater_operator($1, $3); }
    | comp_expr ">=" add_expr { $$ = mw::new_greater_equal_operator($1, $3); }
    | comp_expr "==" add_expr { $$ = mw::new_equal_operator($1, $3); }
    | comp_expr "!=" add_expr { $$ = mw::new_not_equal_operator($1, $3); }
    | comp_expr "in" add_expr { $$ = mw::new_in_operator($1, $3); }
    ;

add_expr:
    mul_expr
    | add_expr "+" mul_expr { $$ = mw::new_add_operator($1, $3); }
    | add_expr "-" mul_expr { $$ = mw::new_subtract_operator($1, $3); }
    ;

mul_expr:
    factor
    | mul_expr "*" factor { $$ = mw::new_multiply_operator($1, $3); }
    | mul_expr "/" factor { $$ = mw::new_divide_operator($1, $3); }
    ;

factor:
    NUM { $$ = mw::new_number($1); }
    | BOOL { $$ = mw::new_boolean($1); }
    | ID { $$ = $1; }
    | STR { $$ = mw::new_string($1); }
    | "(" expr ")" { $$ = $2; }
    ;


%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::stringstream ss;
  ss << l << ": " << m << '\n';
  throw std::runtime_error(ss.str());
}
