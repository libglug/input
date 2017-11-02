# enable c++11, set Mac OS/Linux rpath
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")

    set(GLUG_OS_WIN32 TRUE)

    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
    else()
        set(CMAKE_CXX_FLAGS "-std=c++11")
    endif()

elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")

    set(GLUG_OS_MACOS TRUE)

    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
    set(CMAKE_MACOSX_RPATH ".")

elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")

    set(GLUG_OS_LINUX TRUE)

    set(CMAKE_CXX_FLAGS "-std=c++11")
    set(CMAKE_INSTALL_RPATH ".")
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

endif()
