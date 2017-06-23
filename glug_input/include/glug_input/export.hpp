#ifndef GLUG_INPUT_EXPORT_HPP
#define GLUG_INPUT_EXPORT_HPP

#include <glug_input/config.hpp>

#ifdef GLUG_INPUT_EXPORT

  #define INPUT_LIB_API GLUG_LIB_EXPORT

#else

  #define INPUT_LIB_API GLUG_LIB_IMPORT

#endif

#endif // GLUG_INPUT_EXPORT_HPP
