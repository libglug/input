#ifndef GLUG_EVENT_QUEUE_HPP
#define GLUG_EVENT_QUEUE_HPP

#include <glug_input/export.hpp>
#include <type_traits>

namespace glug
{

struct event;

class event_queue
{
public:
  template <typename t,
            typename std::enable_if<
              std::is_convertible<t, event>::value,
            bool>::type = 0>
  static bool wait_for_event(t &type)
  {
    return true;
  }
};

} // namespace glug

#endif // GLUG_EVENT_QUEUE_HPP
