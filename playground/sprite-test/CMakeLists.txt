cmake_minimum_required(VERSION 3.16)
project(sprite-test)

add_executable(sprite-test src/sprite-test.cpp)
target_link_libraries(sprite-test 
    PRIVATE
        project_options project_warnings
        CONAN_PKG::sfml CONAN_PKG::spdlog CONAN_PKG::entt
)