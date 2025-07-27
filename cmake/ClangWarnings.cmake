if(ENABLE_STRICT_FLAGS AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(
        -Wall                           # Common warnings
        -Wextra                         # Extra warnings
        -Wpedantic                      # Non-standard code
        -Wshadow                        # Variable shadowing
        -Wold-style-cast                # C-style casts
        -Wunused                        # Unused entities
        -Woverloaded-virtual            # Hidden virtuals
        -Wconversion                    # Implicit conversions
        -Wsign-conversion               # Signed/unsigned conversions
        -Winconsistent-missing-override # Missing 'override'
        -Wnull-dereference              # Null dereference
        -Wunreachable-code              # Dead code
        -Wundefined-func-template       # Undefined template funcs
        -Wheader-hygiene                # Bad header includes
    )
endif()
