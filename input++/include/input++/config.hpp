#ifndef IPP_CONFIG_HPP
#define IPP_CONFIG_HPP

#if defined (WIN32) || defined (_WIN32) || defined (WIN64) || defined (_WIN64)

    #define IPP_OS_WINDOWS

#elif defined (__linux__)

    #define IPP_OS_LINUX

#elif defined (__APPLE__) && defined (__MACH__)
    #include <TargetConditionals.h>

    #if TARGET_OS_MAC == 1

        #define IPP_OS_MACOS

    #endif

#endif

#if defined (IPP_OS_WINDOWS)

    #define IPP_LIB_IMPORT __declspec (dllimport)
    #define IPP_LIB_EXPORT __declspec (dllexport)
    #define IPP_LIB_LOCAL

#elif defined (IPP_OS_LINUX) || defined (IPP_OS_MACOS)

    #define IPP_LIB_IMPORT __attribute__ ((visibility ("default")))
    #define IPP_LIB_EXPORT __attribute__ ((visibility ("default")))
    #define IPP_LIB_LOCAL  __attribute__ ((visibility ("hidden")))

#endif

#endif // IPP_CONFIG_HPP
