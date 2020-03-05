
function(enable_sanitizers target_name)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(SANITIZERS "")

        if(ENABLE_SANITIZER_ADDRESS)
            list(APPEND SANITIZERS "address")
        endif()

        if(ENABLE_SANITIZER_MEMORY)
            list(APPEND SANITIZERS "memory")
        endif()

        if(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR)
            list(APPEND SANITIZERS "undefined")
        endif()

        if(ENABLE_SANITIZER_THREAD)
            list(APPEND SANITIZERS "thread")
        endif()

        list(JOIN SANITIZERS "," LIST_OF_SANITIZERS)
    endif()

    if(LIST_OF_SANITIZERS)
        if(NOT "${LIST_OF_SANITIZERS}" STREQUAL "")
            target_compile_options(${target_name} INTERFACE -fsanitize=${LIST_OF_SANITIZERS})
            target_link_libraries(${target_name} INTERFACE -fsanitize=${LIST_OF_SANITIZERS})
        endif()
    endif()
endfunction()