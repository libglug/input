include(${PROJECT_SOURCE_DIR}/cmake/macros/add_gluglib.cmake)

set(SRC_ROOT src)
set(INC_ROOT include/glug_input)

list(
    APPEND
    COMMON_SOURCE
    ${INC_ROOT}/keyboard.h
    ${INC_ROOT}/keyboard/keyboard.h
    ${INC_ROOT}/keyboard/keys.h
    ${INC_ROOT}/keyboard/locks.h
    ${INC_ROOT}/keyboard/mods.h
    ${INC_ROOT}/mouse.h
    ${INC_ROOT}/mouse/mouse.h
    ${INC_ROOT}/mouse/buttons.h
    ${INC_ROOT}/mouse/point_t.h
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

# find dependencies
find_library(APPLE_APPKIT AppKit)

set(GLUG_TARGET_NAME ${CMAKE_PROJECT_NAME})
add_gluglib(
    TARGET_NAME ${GLUG_TARGET_NAME}
    WIN32_SOURCE ${WIN32_SOURCE}
    MACOS_SOURCE ${MACOS_SOURCE}
    LINUX_SOURCE ${LINUX_SOURCE}
    WIN32_LIBS
    MACOS_LIBS ${APPLE_APPKIT}
    LINUX_LIBS X11 Xi
)
target_include_directories(
    ${GLUG_TARGET_NAME}
    PRIVATE "/System/Library/Frameworks/Carbon.framework/Frameworks")

# install the library
install(
    TARGETS ${GLUG_TARGET_NAME}
    DESTINATION ${GLUG_DIST_LIBR_DIR}
)

install(
    TARGETS ${GLUG_TARGET_NAME}
    DESTINATION ${GLUG_DIST_XMPL_DIR}
)
