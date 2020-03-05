if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD 
        "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake"
    )
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_add_remote(
    NAME bincrafters 
    URL https://api.bintray.com/conan/bincrafters/public-conan
)

conan_cmake_run(
    REQUIRES
        fmt/6.1.2
        spdlog/1.5.0
        gtest/1.10.0
        entt/3.3.1
        sfml/2.5.1@bincrafters/stable
    BASIC_SETUP 
    CMAKE_TARGETS
    BUILD missing
)
