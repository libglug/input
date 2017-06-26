#include "lock_util.hpp"
#include <glug_input/keyboard/locks.hpp>

#include <glug_input/util/significant_bit.hpp>

namespace glug
{

static const size_t lock_count = significant_bit<static_cast<size_t>(locks::unknown) - 1>::value;
const std::array<locks, lock_count> lock_util::lock_list =
{{
  locks::caps,
  locks::num,
  locks::scroll,
}};

} // namespace glug
