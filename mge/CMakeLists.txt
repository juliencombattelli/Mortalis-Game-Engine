cmake_minimum_required(VERSION 3.16)
project(mge)

add_library(mge-ecs INTERFACE)
target_include_directories(mge-ecs INTERFACE include)
target_compile_features(mge-ecs INTERFACE cxx_std_17)

add_executable(mge-ecs-test 
    test/ComponentPoolTest.cpp
    test/EntityIdTest.cpp
)
target_link_libraries(mge-ecs-test mge-ecs gtest gtest_main)
set_target_properties(mge-ecs-test PROPERTIES CXX_CLANG_TIDY "")
add_test(NAME mge-ecs-test COMMAND mge-ecs-test)
