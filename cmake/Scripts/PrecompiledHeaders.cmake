cmake_minimum_required(VERSION 3.16)

option(ENABLE_PCH "Enable Precompiled Headers" OFF)
function (target_enable_precompiled_headers TARGET_NAME)
    if (ENABLE_PCH)
        target_precompile_headers(${TARGET_NAME} INTERFACE 
            <vector> <string> <map> <utility>
        )
    endif()
endfunction()