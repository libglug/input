# enable c++11, set Linux rpath
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")

    set(GLUG_OS_WIN32 1)

    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
    else()
        set(CMAKE_CXX_FLAGS "-std=c++11")
    endif()

elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")

    set(GLUG_OS_MACOS 1)

    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")

    set(GLUG_OS_LINUX 1)

    set(CMAKE_CXX_FLAGS "-std=c++11")
    set(CMAKE_INSTALL_RPATH ".")
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

endif()
