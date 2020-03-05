cmake_minimum_required(VERSION 3.16)
project(gametest)

add_executable(gametest src/gametest.cpp)
target_link_libraries(gametest
    PRIVATE
        project_options # project_warnings
        CONAN_PKG::sfml CONAN_PKG::spdlog CONAN_PKG::entt
)

install(TARGETS gametest)