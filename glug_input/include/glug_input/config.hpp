#ifndef GLUG_CONFIG_HPP
#define GLUG_CONFIG_HPP

#if defined (WIN32) || defined (_WIN32) || defined (WIN64) || defined (_WIN64)

  #define GLUG_OS_WIN32

#elif defined (__linux__)

  #define GLUG_OS_LINUX

#elif defined (__APPLE__) && defined (__MACH__)
  #include <TargetConditionals.h>

  #if TARGET_OS_MAC == 1

    #define GLUG_OS_MACOS

  #endif

#endif

#if defined (GLUG_OS_WIN32)

  #define GLUG_LIB_IMPORT __declspec (dllimport)
  #define GLUG_LIB_EXPORT __declspec (dllexport)
  #define GLUG_LIB_LOCAL

#elif defined (GLUG_OS_LINUX) || defined (GLUG_OS_MACOS)

  #define GLUG_LIB_IMPORT __attribute__ ((visibility ("default")))
  #define GLUG_LIB_EXPORT __attribute__ ((visibility ("default")))
  #define GLUG_LIB_LOCAL  __attribute__ ((visibility ("hidden")))

#endif

#endif // GLUG_CONFIG_HPP
