project (input++)
cmake_minimum_required(VERSION 2.8)

# project version
set(IPP_VERSION_MAJOR 1)
set(IPP_VERSION_MINOR 0)
set(IPP_VERSION_PATCH 0)

include(cmake/os.cmake)

set(IPP_INCLUDE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/input++/include)
include_directories(${IPP_INCLUDE_ROOT})
