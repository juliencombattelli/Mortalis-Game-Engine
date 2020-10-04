cmake_minimum_required(VERSION 3.16)
project(sprite-test)

add_executable(sprite-test src/sprite-test.cpp)
target_link_libraries(sprite-test
    PRIVATE
        sfml-graphics sfml-window sfml-system spdlog::spdlog EnTT::EnTT
)