cmake_minimum_required(VERSION 3.16)
project(gametest)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(gametest src/gametest.cpp)
target_link_libraries(gametest sfml-graphics spdlog::spdlog EnTT)