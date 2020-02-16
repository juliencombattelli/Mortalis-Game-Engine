cmake_minimum_required(VERSION 3.16)
project(mge-framework)

option(WITH_CLANG_TIDY "Enablr clang-tidy static analysis builds" OFF)

if(WITH_CLANG_TIDY)
    include(cmake/Scripts/ClangTidy.cmake)
endif()

add_subdirectory(gametest)