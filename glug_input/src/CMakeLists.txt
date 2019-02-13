include(${PROJECT_SOURCE_DIR}/cmake/compile.cmake)
set(GLUG_PROJ_NAME glug_input)

set(INPUT_SRC_ROOT ${GLUG_INPUT_ROOT}/src)
set(INPUT_INC_ROOT ${GLUG_INCLUDE_ROOT}/glug_input)

set(UTIL_HEADERS
    ${INPUT_INC_ROOT}/config.h
    ${INPUT_INC_ROOT}/export.h
)

set(INPUT_HEADERS
    ${INPUT_INC_ROOT}/keyboard.h
    ${INPUT_INC_ROOT}/keyboard/keyboard.h
    ${INPUT_INC_ROOT}/keyboard/keys.h
    ${INPUT_INC_ROOT}/keyboard/locks.h
    ${INPUT_INC_ROOT}/keyboard/mods.h
    ${INPUT_INC_ROOT}/mouse.h
    ${INPUT_INC_ROOT}/mouse/mouse.h
    ${INPUT_INC_ROOT}/mouse/buttons.h
    ${INPUT_INC_ROOT}/mouse/point_t.h
)

set(INPUT_SOURCES
    ${INPUT_SRC_ROOT}/keyboard/keyboard.c
    ${INPUT_SRC_ROOT}/keyboard/key_util.c
    ${INPUT_SRC_ROOT}/mouse/mouse.c
)

set(INPUT_PLATFORM_HEADERS
    ${INPUT_SRC_ROOT}/keyboard/keyboard_plat.h
    ${INPUT_SRC_ROOT}/keyboard/key_util.h
    ${INPUT_SRC_ROOT}/keyboard/lock_util.h
    ${INPUT_SRC_ROOT}/keyboard/mod_util.h
    ${INPUT_SRC_ROOT}/mouse/mouse_plat.h
    ${INPUT_SRC_ROOT}/mouse/button_util.h
)

# Windows sources
set(WIN32_KEY_ROOT ${INPUT_SRC_ROOT}/keyboard/win32)
set(WIN32_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/win32)

set(WIN32_SOURCES
    ${WIN32_KEY_ROOT}/keyboard_win32.c
    ${WIN32_KEY_ROOT}/key_defs.h
    ${WIN32_KEY_ROOT}/key_win32.c
    ${WIN32_KEY_ROOT}/lock_win32.c
    ${WIN32_KEY_ROOT}/mod_win32.c
    ${WIN32_MOUSE_ROOT}/mouse_win32.c
    ${WIN32_MOUSE_ROOT}/button_win32.c
)

# Mac OS sources
set(MACOS_KEY_ROOT ${INPUT_SRC_ROOT}/keyboard/macos)
set(MACOS_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/macos)

set(MACOS_SOURCES
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
set(X11_KEY_ROOT ${INPUT_SRC_ROOT}/keyboard/x11)
set(X11_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/x11)

set(X11_SOURCES
    ${X11_KEY_ROOT}/keyboard_x11.c
    ${X11_KEY_ROOT}/key_x11.c
    ${X11_KEY_ROOT}/lock_x11.c
    ${X11_KEY_ROOT}/mod_x11.c
    ${X11_MOUSE_ROOT}/mouse_x11.c
    ${X11_MOUSE_ROOT}/button_x11.c
)

# Find the libs necessary for the target platform
if(${GLUG_OS_WIN32})

    set(INPUT_PLATFORM_SOURCES ${WIN32_SOURCES})
    set(EXT_LIBS User32)

elseif(${GLUG_OS_MACOS})

    set(INPUT_PLATFORM_SOURCES ${MACOS_SOURCES})
    include_directories("/System/Library/Frameworks/Carbon.framework/Frameworks")
    find_library(APPLE_APPKIT AppKit)
    set(EXT_LIBS ${APPLE_APPKIT})

elseif(${GLUG_OS_LINUX})

    set(INPUT_PLATFORM_SOURCES ${X11_SOURCES})
    set(EXT_LIBS X11 Xi)

endif()

# define GLUG_INPUT_EXPORT to export the library's symbols
add_definitions(-DGLUG_INPUT_EXPORT)

# change compilation rules based on target os
set_compilation_props("${WIN32_SOURCES}" GLUG_OS_WIN32)
set_compilation_props("${MACOS_SOURCES}" GLUG_OS_MACOS)
set_compilation_props("${X11_SOURCES}" GLUG_OS_LINUX)

add_library(
    ${GLUG_PROJ_NAME}
    SHARED
    ${UTIL_HEADERS}
    ${INPUT_HEADERS}
    ${INPUT_SOURCES}
    ${INPUT_PLATFORM_HEADERS}
    ${INPUT_PLATFORM_SOURCES}
    ${WIN32_SOURCES}
    ${MACOS_SOURCES}
    ${X11_SOURCES}
)

target_link_libraries(${GLUG_PROJ_NAME} ${EXT_LIBS})
