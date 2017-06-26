#include "button_util.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <glug_input/util/significant_bit.hpp>

namespace glug
{

static const size_t button_count = significant_bit<static_cast<size_t>(buttons::unknown) - 1>::value;
const std::array<buttons, button_count> button_util::button_list =
{{
  buttons::left,
  buttons::mid,
  buttons::right,
  buttons::ex1,
  buttons::ex2,
}};

} // namespace glug
