project(examples)
include(${PROJECT_SOURCE_DIR}/../cmake/macros/add_example.cmake)

set(GLUG_TARGET_NAME ${CMAKE_PROJECT_NAME}_test)
set(GLUG_TARGET_NAME++ ${CMAKE_PROJECT_NAME}_test++)

add_example(
    TARGET_NAME ${GLUG_TARGET_NAME}
    SRCS main.c
)

add_example(
    TARGET_NAME ${GLUG_TARGET_NAME++}
    SRCS main.cpp
)

install(
    TARGETS ${GLUG_TARGET_NAME}
    DESTINATION ${GLUG_DIST_XMPL_DIR}
)

install(
    TARGETS ${GLUG_TARGET_NAME++}
    DESTINATION ${GLUG_DIST_XMPL_DIR}
)

# copy the glug lib to the example build dir
find_package(glug_input REQUIRED)
add_custom_command(
    TARGET
        ${GLUG_TARGET_NAME} POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:glug_input> ${CMAKE_CURRENT_BINARY_DIR}
)
