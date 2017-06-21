set(GLUG_EXAMPLE_SRC main.cpp)

add_executable(input_test ${GLUG_EXAMPLE_SRC})

target_link_libraries(input_test glug_input)
