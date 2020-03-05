function (enable_precompiled_headers target_name)
    if (ENABLE_PCH)
        target_precompile_headers(${target_name} INTERFACE 
            <vector> <string> <map> <utility>
        )
    endif()
endfunction()