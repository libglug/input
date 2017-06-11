# enable c++11, set Linux rpath
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")

  set(CMAKE_CXX_FLAGS "-std=c++11")

elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")

  set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")

  set(CMAKE_CXX_FLAGS "-std=c++11")
  set(CMAKE_INSTALL_RPATH ".")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

endif()
