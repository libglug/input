cmake_minimum_required(VERSION 3.0)

set(VER_MAJOR 1)
set(VER_MINOR 0)
set(VER_PATCH 0)
project(glug_input VERSION ${VER_MAJOR}.${VER_MINOR}.${VER_PATCH})
include(cmake/add_gluglib.cmake)

option(BUILD_STATIC "Build as a static library instead of shared" "OFF")

set(SRC_ROOT src)
set(INC_ROOT include/glug)

list(
    APPEND
    COMMON_SOURCE
    ${INC_ROOT}/input.h
    ${INC_ROOT}/input/keyboard.h
    ${INC_ROOT}/input/keyboard/keyboard.h
    ${INC_ROOT}/input/keyboard/keys.h
    ${INC_ROOT}/input/keyboard/locks.h
    ${INC_ROOT}/input/keyboard/mods.h
    ${INC_ROOT}/input/mouse.h
    ${INC_ROOT}/input/mouse/mouse.h
    ${INC_ROOT}/input/mouse/buttons.h
    ${INC_ROOT}/input/mouse/point_t.h
    ${SRC_ROOT}/keyboard/keyboard_plat.h
    ${SRC_ROOT}/keyboard/key_util.h
    ${SRC_ROOT}/keyboard/lock_util.h
    ${SRC_ROOT}/keyboard/mod_util.h
    ${SRC_ROOT}/mouse/mouse_plat.h
    ${SRC_ROOT}/mouse/button_util.h
    ${SRC_ROOT}/keyboard/keyboard.c
    ${SRC_ROOT}/keyboard/key_util.c
    ${SRC_ROOT}/mouse/mouse.c
)

# Windows sources
set(WIN32_KEY_ROOT ${SRC_ROOT}/keyboard/win32)
set(WIN32_MOUSE_ROOT ${SRC_ROOT}/mouse/win32)
list(
    APPEND
    WIN32_SOURCE
    ${COMMON_SOURCE}
    ${WIN32_KEY_ROOT}/keyboard_win32.c
    ${WIN32_KEY_ROOT}/key_defs.h
    ${WIN32_KEY_ROOT}/key_win32.c
    ${WIN32_KEY_ROOT}/lock_win32.c
    ${WIN32_KEY_ROOT}/mod_win32.c
    ${WIN32_MOUSE_ROOT}/mouse_win32.c
    ${WIN32_MOUSE_ROOT}/button_win32.c
)

# Mac OS sources
set(MACOS_KEY_ROOT ${SRC_ROOT}/keyboard/macos)
set(MACOS_MOUSE_ROOT ${SRC_ROOT}/mouse/macos)
list(
    APPEND
    MACOS_SOURCE
    ${COMMON_SOURCE}
    ${MACOS_KEY_ROOT}/keyboard_macos.c
    ${MACOS_KEY_ROOT}/key_defs.h
    ${MACOS_KEY_ROOT}/key_macos.c
    ${MACOS_KEY_ROOT}/lock_defs.h
    ${MACOS_KEY_ROOT}/lock_macos.c
    ${MACOS_KEY_ROOT}/mod_macos.c
    ${MACOS_MOUSE_ROOT}/mouse_macos.c
    ${MACOS_MOUSE_ROOT}/button_macos.c
)

# x11 sources
set(X11_KEY_ROOT ${SRC_ROOT}/keyboard/x11)
set(X11_MOUSE_ROOT ${SRC_ROOT}/mouse/x11)
list(
    APPEND
    LINUX_SOURCE
    ${COMMON_SOURCE}
    ${X11_KEY_ROOT}/keyboard_x11.c
    ${X11_KEY_ROOT}/key_x11.c
    ${X11_KEY_ROOT}/lock_x11.c
    ${X11_KEY_ROOT}/mod_x11.c
    ${X11_MOUSE_ROOT}/mouse_x11.c
    ${X11_MOUSE_ROOT}/button_x11.c
)

add_gluglib(
    TARGET_NAME ${CMAKE_PROJECT_NAME}
    STATIC_BUILD ${BUILD_STATIC}
    WIN32_SOURCE ${WIN32_SOURCE}
    MACOS_SOURCE ${MACOS_SOURCE}
    LINUX_SOURCE ${LINUX_SOURCE}
    WIN32_LIBS
    MACOS_LIBS AppKit
    LINUX_LIBS X11 Xi
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/common_headers/include>
    INTERFACE
        $<INSTALL_INTERFACE:include>    
    PRIVATE
        "/System/Library/Frameworks/Carbon.framework/Frameworks"
)

# install the library
install(
    TARGETS
        ${CMAKE_PROJECT_NAME}
    EXPORT
        Find${CMAKE_PROJECT_NAME}
    DESTINATION
        lib
)

#install the lib's headers
install(
    DIRECTORY
        include/
    DESTINATION
        include
)

# install the common_headers
install(
    DIRECTORY
        common_headers/include/
    DESTINATION
        include
    FILES_MATCHING PATTERN
        "*.h"
)

# export the package to be included in other projects
export(PACKAGE ${CMAKE_PROJECT_NAME})
export(
    TARGETS
        ${CMAKE_PROJECT_NAME}
    FILE
        ${CMAKE_PROJECT_NAME}-config.cmake
)

# install export file
install(
    EXPORT
        Find${CMAKE_PROJECT_NAME}
    DESTINATION
        cmake
)
