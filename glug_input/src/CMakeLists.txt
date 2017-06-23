set(INPUT_SRC_ROOT ${GLUG_INPUT_ROOT}/src)
set(INPUT_INC_ROOT ${IPP_INCLUDE_ROOT}/glug_input)

set(CONFIG_HEADERS
    ${INPUT_INC_ROOT}/config.hpp
    ${INPUT_INC_ROOT}/export.hpp
)

set(INPUT_HEADERS
    ${INPUT_INC_ROOT}/mouse.hpp
    ${INPUT_INC_ROOT}/mouse/mouse.hpp
    ${INPUT_INC_ROOT}/mouse/buttons.hpp
    ${INPUT_INC_ROOT}/mouse/point.hpp
)

set(INPUT_SOURCES
    ${INPUT_SRC_ROOT}/mouse/mouse.cpp
    ${INPUT_SRC_ROOT}/mouse/buttons.cpp
)

set(INPUT_PLATFORM_HEADERS
    ${INPUT_SRC_ROOT}/mouse/mouse_plat.hpp
    ${INPUT_SRC_ROOT}/mouse/button_util.hpp
)

if (${GLUG_OS_WIN32})
    set(WIN32_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/win32)

    set(INPUT_PLATFORM_SOURCES
        ${WIN32_MOUSE_ROOT}/mouse_win32.cpp
        ${WIN32_MOUSE_ROOT}/button_win32.cpp
    )

    set(EXT_LIBS User32)

elseif(${GLUG_OS_MACOS})

    include_directories("/System/Library/Frameworks/Carbon.framework/Frameworks")

    set(MACOS_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/macos)

    set(INPUT_PLATFORM_SOURCES
      ${MACOS_MOUSE_ROOT}/mouse_macos.cpp
      ${MACOS_MOUSE_ROOT}/button_macos.cpp
    )

    find_library(APPLE_APPKIT AppKit)
    set(EXT_LIBS ${APPLE_APPKIT})

elseif(${GLUG_OS_LINUX})

    set(X11_MOUSE_ROOT ${INPUT_SRC_ROOT}/mouse/x11)

    set(INPUT_PLATFORM_SOURCES
        ${X11_MOUSE_ROOT}/mouse_x11.cpp
        ${X11_MOUSE_ROOT}/button_x11.cpp
    )

    set(EXT_LIBS X11 Xi)

endif()

add_definitions(-DGLUG_INPUT_EXPORT)

add_library(
    glug_input
    SHARED
    ${CONFIG_HEADERS}
    ${INPUT_HEADERS}
    ${INPUT_SOURCES}
    ${INPUT_PLATFORM_HEADERS}
    ${INPUT_PLATFORM_SOURCES}
)

target_link_libraries(glug_input ${EXT_LIBS})
