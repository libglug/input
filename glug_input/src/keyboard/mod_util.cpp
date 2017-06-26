#include "mod_util.hpp"
#include <glug_input/keyboard/mods.hpp>

#include <glug_input/util/significant_bit.hpp>

namespace glug
{

static const size_t mod_count = significant_bit<static_cast<size_t>(mods::unknown) - 1>::value;
const std::array<mods, mod_count> mod_util::mod_list =
{{
  mods::shift,
  mods::alt,
  mods::ctrl,
  mods::super,
}};

} // namespace glug
