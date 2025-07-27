# List test source files explicitly
set(TEST_SOURCES
        test_dynamic_array.cpp
        test_singly_linked_list.cpp
        test_doubly_linked_list.cpp
        test_stack_with_array.cpp
        test_stack_with_array_stl.cpp
        test_stack_with_linked_list.cpp
        test_stack_with_linked_list_stl.cpp
        test_queue_with_array.cpp
        test_queue_with_array_stl.cpp
        test_queue_with_linked_list.cpp
        test_queue_with_linked_list_stl.cpp
        test_circular_array.cpp
        test_deque_with_array.cpp
        test_deque_with_linked_list.cpp
        test_deque_with_linked_list_stl.cpp
)

# Helper function: convert snake_case to PascalCase
function(to_pascal_case out_var input)
        string(REPLACE "_" ";" words ${input})
        set(result "")
        foreach(word IN LISTS words)
                string(SUBSTRING ${word} 0 1 first)
                string(SUBSTRING ${word} 1 -1 rest)
                string(TOUPPER ${first} first)
                string(TOLOWER ${rest} rest)
                set(result "${result}${first}${rest}")
        endforeach()
        set(${out_var} "${result}" PARENT_SCOPE)
endfunction()

foreach(test_src IN LISTS TEST_SOURCES)
        get_filename_component(test_name_raw ${test_src} NAME_WE)
        to_pascal_case(test_name ${test_name_raw})

        add_executable(${test_name})
        target_sources(${test_name} PRIVATE ${test_src})
        target_link_libraries(${test_name} PRIVATE DataStructures)
        target_include_directories(${test_name} 
                PRIVATE 
                        ${PROJECT_SOURCE_DIR}/include
        )

        add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
