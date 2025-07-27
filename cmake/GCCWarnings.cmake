if(ENABLE_STRICT_FLAGS AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(
        -Wall                 # Common warnings
        -Wextra               # Extra warnings
        -Wpedantic            # Non-standard code
        -Wshadow              # Variable shadowing
        -Wold-style-cast      # C-style casts
        -Wunused              # Unused entities
        -Woverloaded-virtual  # Hidden virtuals
        -Wconversion          # Implicit conversions
        -Wsign-conversion     # Signed/unsigned conversions
        -Wsuggest-override    # Suggest 'override'
        -Wduplicated-cond     # Duplicate conditions
        -Wlogical-op          # Suspicious logic ops
        -Wnull-dereference    # Null dereference
    )
endif()
