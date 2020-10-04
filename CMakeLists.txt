cmake_minimum_required(VERSION 3.16)
project(mge-framework)

set(CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/cmake/Scripts
    ${PROJECT_SOURCE_DIR}/cmake/Modules
    ${CMAKE_MODULE_PATH}
)

include(Conan)
include(Doxygen)
include(InterproceduralOptimization)
include(PrecompiledHeaders)
include(Sanitizers)
include(StaticAnalyzers)
include(Testing)
include(Warnings)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest 1.10 REQUIRED)
find_package(spdlog 1.8 REQUIRED)
find_package(EnTT 3.5 REQUIRED)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_subdirectory(mge)
add_subdirectory(playground/entt-test)
add_subdirectory(playground/sprite-test)
