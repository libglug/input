project(example)
set(GLUG_LIB_TARGET glug_input)
include(cmake/add_example.cmake)

find_package(${GLUG_LIB_TARGET} REQUIRED)
set(GLUG_TARGET_NAME ${GLUG_LIB_TARGET}_test)
set(GLUG_TARGET_NAME++ ${GLUG_LIB_TARGET}_test++)

set(INSTALL_PATH example)

add_example(
    TARGET_NAME
        ${GLUG_TARGET_NAME}
    SRCS
        main.c
    LINK_LIB
        ${GLUG_LIB_TARGET}
)

add_example(
    TARGET_NAME
        ${GLUG_TARGET_NAME++}
    SRCS
        main.cpp
    LINK_LIB
        ${GLUG_LIB_TARGET}
)

install(
    TARGETS
        ${GLUG_TARGET_NAME}
    DESTINATION
        ${INSTALL_PATH}
)

install(
    TARGETS
        ${GLUG_TARGET_NAME++}
    DESTINATION
        ${INSTALL_PATH}
)
