if(ENABLE_STRICT_FLAGS AND MSVC)
    add_compile_options(
        /W4              # Enable high warning level (4)
        /WX              # Treat all warnings as errors
        /permissive-     # Enforce standard C++ (disallow MSVC extensions)
        /sdl             # Enable additional security warnings and checks
        /Zc:__cplusplus  # Use correct __cplusplus value for standards detection
        /w44265          # Warn if a virtual function hides a base class function
        /w44726          # Warn if an overriding function is missing 'override'
        /w4702           # Warn about unreachable code
        /external:W0     # Suppress warnings from system headers (e.g., STL)
    )
endif()
