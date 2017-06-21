project (glug_input)
cmake_minimum_required(VERSION 2.8)

# project version
set(IPP_VERSION_MAJOR 1)
set(IPP_VERSION_MINOR 0)
set(IPP_VERSION_PATCH 0)

include(cmake/os.cmake)

set(GLUG_INPUT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/glug_input)
set(IPP_INCLUDE_ROOT ${GLUG_INPUT_ROOT}/include)
include_directories(${IPP_INCLUDE_ROOT})

set(LIB_DIR ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LIB_DIR})

add_subdirectory(glug_input/src)
add_subdirectory(example)
