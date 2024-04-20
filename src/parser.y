%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include "ast.h"

    using namespace sql;

    class Scanner;
    class Driver;
}

// %param { std::shared_ptr<Ast>& result }

%define parse.trace
%define parse.error verbose

%code {
    #include "Scanner.h"
    #include "Driver.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

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
// %token <std::string> STR "string"

// Uncomment this after complete

%nterm <std::shared_ptr<Ast>> expr
%nterm <std::shared_ptr<Ast>> factor
%nterm <std::shared_ptr<Ast>> and_expr
%nterm <std::shared_ptr<Ast>> comp_expr
%nterm <std::shared_ptr<Ast>> add_expr
%nterm <std::shared_ptr<Ast>> mul_expr


// %nterm <std::shared_ptr<Ast>> query
// %nterm <std::shared_ptr<Ast>> select_query
// %nterm <std::shared_ptr<Ast>> insert_query
// %nterm <std::shared_ptr<Ast>> index_name
// %nterm <std::shared_ptr<Where>> where_clause
// %nterm <std::optional<std::string>> match_expr
// %nterm <std::shared_ptr<List>> namelist
// %nterm <int> limit

// %printer { yyo << $$; } <*>;

// HINT: Use $$->SetLocation(@$);

%%

%start calc;

calc:
    expr { driver.result = $1; }
    ;

expr:
    and_expr
    | expr "||" and_expr { $$ = new_or_operator($1, $3); }
    ;

and_expr:
    comp_expr
    | and_expr "&&" comp_expr { $$ = new_and_operator($1, $3); }
    ;

comp_expr:
    add_expr
    | comp_expr "<" add_expr { $$ = new_less_operator($1, $3); }
    | comp_expr "<=" add_expr { $$ = new_less_equal_operator($1, $3); }
    | comp_expr ">" add_expr { $$ = new_greater_operator($1, $3); }
    | comp_expr ">=" add_expr { $$ = new_greater_equal_operator($1, $3); }
    | comp_expr "==" add_expr { $$ = new_equal_operator($1, $3); }
    | comp_expr "!=" add_expr { $$ = new_not_equal_operator($1, $3); }
    ;

add_expr:
    mul_expr
    | add_expr "+" mul_expr { $$ = new_add_operator($1, $3); }
    | add_expr "-" mul_expr { $$ = new_subtract_operator($1, $3); }
    ;

mul_expr:
    factor
    | mul_expr "*" factor { $$ = new_multiply_operator($1, $3); }
    | mul_expr "/" factor { $$ = new_divide_operator($1, $3); }
    ;

factor:
    NUM { $$ = new_number($1); }
    | "(" expr ")" { $$ = $2; }
    ;


%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
