cmake_minimum_required(VERSION 3.16)
project(entt-test)

add_executable(entt-test src/entt-test.cpp)
target_link_libraries(entt-test
    PRIVATE
        sfml-graphics sfml-window sfml-system spdlog::spdlog EnTT::EnTT
)

install(TARGETS entt-test)