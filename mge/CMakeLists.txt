cmake_minimum_required(VERSION 3.16)
project(mge)

add_library(mge-ecs INTERFACE)
target_include_directories(mge-ecs INTERFACE include)
target_compile_features(mge-ecs INTERFACE cxx_std_17)

if (ENABLE_TESTING)
    add_executable(mge-ecs-test 
        test/ComponentPoolTest.cpp
        test/EntityIdTest.cpp
    )
    target_link_libraries(mge-ecs-test mge-ecs CONAN_PKG::gtest)
    gtest_discover_tests(mge-ecs-test)
endif()