cmake_minimum_required(VERSION 3.5)
project("MathWiz" VERSION 0.0.1)

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test)
    add_subdirectory(test)
endif ()

if(EXISTS /usr/bin/gcc-9)
    set(CMAKE_C_COMPILER /usr/bin/gcc-9)
endif ()

if(EXISTS /usr/bin/g++-9)
    set(CMAKE_CXX_COMPILER /usr/bin/g++-9)
endif ()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Flex/Bison configuration
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

if (WIN32)
    set (ADDITIONAL_FLEX_FLAGS "--wincompat")
else()
    set (ADDITIONAL_FLEX_FLAGS "")
endif()
FLEX_TARGET(LEXER src/scanner.l
        ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/scanner.hpp COMPILE_FLAGS ${ADDITIONAL_FLEX_FLAGS})
BISON_TARGET(PARSER src/parser.y
        ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp COMPILE_FLAGS "-d -v")
ADD_FLEX_BISON_DEPENDENCY(LEXER PARSER)

set(MATH_WIZ_INCLUDE_DIRS
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ast
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ast/operators
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ast/operators/binary
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ast/operators/unary
        ${CMAKE_CURRENT_SOURCE_DIR}/include/visitor
)

set(MATH_WIZ_HEADERS
        include/Driver.h
        include/Scanner.h

        include/ast/Ast.h
        include/ast/AstUtils.h
        include/ast/String.h
        include/ast/Number.h
        include/ast/Boolean.h

        include/ast/operators/binary/BinaryOperator.h
        include/ast/operators/binary/AddOperator.h
        include/ast/operators/binary/SubtractOperator.h
        include/ast/operators/binary/MultiplyOperator.h
        include/ast/operators/binary/DivideOperator.h
        include/ast/operators/binary/GreaterOperator.h
        include/ast/operators/binary/LessOperator.h
        include/ast/operators/binary/EqualOperator.h
        include/ast/operators/binary/NotEqualOperator.h
        include/ast/operators/binary/GreaterEqualOperator.h
        include/ast/operators/binary/LessEqualOperator.h

        include/ast/operators/binary/InOperator.h

        include/ast/operators/binary/AndOperator.h
        include/ast/operators/binary/OrOperator.h

        include/ast/operators/unary/UnaryOperator.h
        include/ast/operators/unary/NotOperator.h
        include/ast/operators/unary/NegateOperator.h

        include/visitor/AstVisitor.h
        include/visitor/EvalVisitor.h
        include/VariableTable.h
        include/ast/Variable.h
)

set(MATH_WIZ_SOURCES
        src/Driver.cpp
        src/Scanner.cpp

        src/ast/Ast.cpp
        src/ast/AstUtils.cpp
        src/ast/String.cpp
        src/ast/Number.cpp
        src/ast/Boolean.cpp

        src/ast/operators/binary/BinaryOperator.cpp
        src/ast/operators/binary/AddOperator.cpp
        src/ast/operators/binary/SubtractOperator.cpp
        src/ast/operators/binary/MultiplyOperator.cpp
        src/ast/operators/binary/DivideOperator.cpp
        src/ast/operators/binary/GreaterOperator.cpp
        src/ast/operators/binary/LessOperator.cpp
        src/ast/operators/binary/EqualOperator.cpp
        src/ast/operators/binary/NotEqualOperator.cpp
        src/ast/operators/binary/GreaterEqualOperator.cpp
        src/ast/operators/binary/LessEqualOperator.cpp

        src/ast/operators/binary/InOperator.cpp

        src/ast/operators/binary/AndOperator.cpp
        src/ast/operators/binary/OrOperator.cpp

        src/ast/operators/unary/UnaryOperator.cpp
        src/ast/operators/unary/NotOperator.cpp
        src/ast/operators/unary/NegateOperator.cpp

        src/visitor/AstVisitor.cpp
        src/visitor/EvalVisitor.cpp
        src/VariableTable.cpp
        src/ast/Variable.cpp
)

set(PROJECT_SOURCES
        ${MATH_WIZ_HEADERS}
        ${MATH_WIZ_SOURCES}
        ${BISON_PARSER_OUTPUTS}
        ${FLEX_LEXER_OUTPUTS}
)

add_library(math_wiz ${PROJECT_SOURCES})

target_include_directories(math_wiz PUBLIC ${MATH_WIZ_INCLUDE_DIRS})


if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test)
    cmake_policy(SET CMP0079 NEW)
    cmake_policy(SET CMP0076 NEW)
    target_link_libraries(test PRIVATE math_wiz)
endif ()
