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
)

set(MATH_WIZ_HEADERS
        include/ast.h
        include/eval.h
        include/Driver.h
        include/Scanner.h
)

set(MATH_WIZ_SOURCES
        src/Driver.cpp
        src/eval.cpp
        src/ast.cpp
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
