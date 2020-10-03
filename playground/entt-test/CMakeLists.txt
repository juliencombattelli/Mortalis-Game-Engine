cmake_minimum_required(VERSION 3.16)
project(entt-test)

add_executable(entt-test src/entt-test.cpp)
target_link_libraries(entt-test
    PRIVATE
        project_options project_warnings
        CONAN_PKG::sfml CONAN_PKG::spdlog CONAN_PKG::entt
)

install(TARGETS entt-test)