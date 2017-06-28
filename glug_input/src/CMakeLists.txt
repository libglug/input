set(GLUG_PROJ_NAME glug_input)

set(INPUT_SRC_ROOT ${GLUG_INPUT_ROOT}/src)
set(INPUT_INC_ROOT ${IPP_INCLUDE_ROOT}/glug_input)

set(UTIL_HEADERS
    ${INPUT_INC_ROOT}/config.hpp
    ${INPUT_INC_ROOT}/export.hpp
    ${INPUT_INC_ROOT}/util/significant_bit.hpp
)

set(INPUT_HEADERS
    ${INPUT_INC_ROOT}/keyboard.hpp
    ${INPUT_INC_ROOT}/keyboard/keyboard.hpp
    ${INPUT_INC_ROOT}/keyboard/keys.hpp
    ${INPUT_INC_ROOT}/keyboard/locks.hpp
    ${INPUT_INC_ROOT}/keyboard/mods.hpp
    ${INPUT_INC_ROOT}/mouse.hpp
    ${INPUT_INC_ROOT}/mouse/mouse.hpp
    ${INPUT_INC_ROOT}/mouse/buttons.hpp
    ${INPUT_INC_ROOT}/mouse/point.hpp
)

set(INPUT_SOURCES
    ${INPUT_SRC_ROOT}/keyboard/keyboard.cpp
    ${INPUT_SRC_ROOT}/keyboard/key_util.cpp
    ${INPUT_SRC_ROOT}/keyboard/lock_util.cpp
    ${INPUT_SRC_ROOT}/keyboard/mod_util.cpp
    ${INPUT_SRC_ROOT}/keyboard/locks.cpp
    ${INPUT_SRC_ROOT}/keyboard/mods.cpp
    ${INPUT_SRC_ROOT}/mouse/mouse.cpp
    ${INPUT_SRC_ROOT}/mouse/buttons.cpp
    ${INPUT_SRC_ROOT}/mouse/button_util.cpp
)

set(INPUT_PLATFORM_HEADERS
    ${INPUT_SRC_ROOT}/keyboard/keyboard_plat.hpp
    ${INPUT_SRC_ROOT}/keyboard/key_util.hpp
    ${INPUT_SRC_ROOT}/keyboard/lock_util.hpp
    ${INPUT_SRC_ROOT}/keyboard/mod_util.hpp
    ${INPUT_SRC_ROOT}/mouse/mouse_plat.hpp
    ${INPUT_SRC_ROOT}/mouse/button_util.hpp
)

set(INPUT_EVENT_HEADERS
    ${INPUT_INC_ROOT}/event/event_queue.hpp
    ${INPUT_INC_ROOT}/event/event_type.hpp
    ${INPUT_INC_ROOT}/event/event.hpp
    ${INPUT_INC_ROOT}/event/key_event.hpp
)

set(INPUT_EVENT_SOURCES
    ${INPUT_SRC_ROOT}/event/event_queue.cpp
    ${INPUT_SRC_ROOT}/event/event_type.cpp
)

if(${GLUG_OS_WIN32})
    set(WIN32_KEY_ROOT ${INPUT_SRC_ROOT}/keyboard/win32)
    set(WIN32_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/win32)

    set(INPUT_PLATFORM_SOURCES
        ${WIN32_KEY_ROOT}/keyboard_win32.cpp
        ${WIN32_KEY_ROOT}/key_defs.hpp
        ${WIN32_KEY_ROOT}/key_win32.cpp
        ${WIN32_KEY_ROOT}/lock_win32.cpp
        ${WIN32_KEY_ROOT}/mod_win32.cpp
        ${WIN32_MOUSE_ROOT}/mouse_win32.cpp
        ${WIN32_MOUSE_ROOT}/button_win32.cpp
    )

    set(EXT_LIBS User32)

elseif(${GLUG_OS_MACOS})
    set(MACOS_KEY_ROOT ${INPUT_SRC_ROOT}/keyboard/macos)
    set(MACOS_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/macos)

    set(INPUT_PLATFORM_SOURCES
      ${MACOS_KEY_ROOT}/keyboard_macos.cpp
      ${MACOS_KEY_ROOT}/key_defs.hpp
      ${MACOS_KEY_ROOT}/key_macos.cpp
      ${MACOS_KEY_ROOT}/lock_macos.cpp
      ${MACOS_KEY_ROOT}/mod_macos.cpp
      ${MACOS_MOUSE_ROOT}/mouse_macos.cpp
      ${MACOS_MOUSE_ROOT}/button_macos.cpp
    )

    include_directories("/System/Library/Frameworks/Carbon.framework/Frameworks")
    find_library(APPLE_APPKIT AppKit)
    set(EXT_LIBS ${APPLE_APPKIT})

elseif(${GLUG_OS_LINUX})
    set(X11_KEY_ROOT ${INPUT_SRC_ROOT}/keyboard/x11)
    set(X11_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/x11)

    set(INPUT_PLATFORM_SOURCES
        ${X11_KEY_ROOT}/keyboard_x11.cpp
        ${X11_KEY_ROOT}/key_defs.hpp
        ${X11_KEY_ROOT}/key_x11.cpp
        ${X11_KEY_ROOT}/lock_x11.cpp
        ${X11_KEY_ROOT}/mod_x11.cpp
        ${X11_MOUSE_ROOT}/mouse_x11.cpp
        ${X11_MOUSE_ROOT}/button_x11.cpp
    )

    set(EXT_LIBS X11 Xi)

endif()

add_definitions(-DGLUG_INPUT_EXPORT)

add_library(
    ${GLUG_PROJ_NAME}
    SHARED
    ${UTIL_HEADERS}
    ${INPUT_HEADERS}
    ${INPUT_SOURCES}
    ${INPUT_PLATFORM_HEADERS}
    ${INPUT_PLATFORM_SOURCES}
    ${INPUT_EVENT_HEADERS}
    ${INPUT_EVENT_SOURCES}
)

target_link_libraries(${GLUG_PROJ_NAME} ${EXT_LIBS})
