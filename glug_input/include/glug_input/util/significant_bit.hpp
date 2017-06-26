#ifndef GLUG_SIGNIFICANT_BIT_HPP
#define GLUG_SIGNIFICANT_BIT_HPP

namespace glug
{

template <size_t n>
struct significant_bit
{
  enum { value = 1 + significant_bit<n/2>::value };
};

template <>
struct significant_bit<0>
{
  enum { value = 0 };
};

} // namespace glug

#endif // GLUG_SIGNIFICANT_BIT_HPP
