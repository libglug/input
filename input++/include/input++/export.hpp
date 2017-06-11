#ifndef IPP_EXPORT_HPP
#define IPP_EXPORT_HPP

#include <input++/config.hpp>

#ifdef IPP_INPUT_EXPORT

    #define IPP_LIB_API IPP_LIB_EXPORT

#else

    #define IPP_LIB_API IPP_LIB_IMPORT

#endif

#endif // IPP_EXPORT_HPP
