# First version providing a full documentation of FindDoxygen module
cmake_minimum_required(VERSION 3.9)

option(ENABLE_DOXYGEN "Enable sources documentations generation with doxygen" OFF)
if(ENABLE_DOXYGEN)
    set(DOXYGEN_CALLER_GRAPH ON)
    set(DOXYGEN_CALL_GRAPH ON)
    set(DOXYGEN_EXTRACT_ALL ON)
    find_package(Doxygen REQUIRED dot)
    doxygen_add_docs(doxygen-docs ${PROJECT_SOURCE_DIR})
endif()