cmake_minimum_required(VERSION 3.16)
project(sprite-test)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(sprite-test src/sprite-test.cpp)
target_link_libraries(sprite-test sfml-graphics spdlog::spdlog EnTT)