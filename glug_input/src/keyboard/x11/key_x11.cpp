#include "../key_util.hpp"
#include "key_defs.hpp"
#include <glug_input/keyboard/keys.hpp>

namespace glug
{

int key_util::code_from_key(keys key)
{
  switch (key)
  {
  case keys::shift_l:      return XK_Shift_L;
  case keys::shift_r:      return XK_Shift_R;
  case keys::alt_l:        return XK_Alt_L;
  case keys::alt_r:        return XK_Alt_R;
  case keys::ctrl_l:       return XK_Control_L;
  case keys::ctrl_r:       return XK_Control_R;
  case keys::super_l:      return XK_Super_L;
  case keys::super_r:      return XK_Super_R;
  case keys::escape:       return XK_Escape;
  case keys::insert:       return XK_Insert;
  case keys::home:         return XK_Home;
  case keys::end:          return XK_End;
  case keys::pageup:       return XK_Page_Up;
  case keys::pagedown:     return XK_Page_Down;
  case keys::print:        return XK_Print;
  case keys::pause:        return XK_Pause;
  case keys::backspace:    return XK_BackSpace;
  case keys::del:          return XK_Delete;
  case keys::tab:          return XK_Tab;
  case keys::enter:        return XK_Return;
  case keys::menu:         return XK_Menu;
  case keys::space:        return XK_space;
  case keys::up:           return XK_Up;
  case keys::down:         return XK_Down;
  case keys::left:         return XK_Left;
  case keys::right:        return XK_Right;
  case keys::f1:           return XK_F1;
  case keys::f2:           return XK_F2;
  case keys::f3:           return XK_F3;
  case keys::f4:           return XK_F4;
  case keys::f5:           return XK_F5;
  case keys::f6:           return XK_F6;
  case keys::f7:           return XK_F7;
  case keys::f8:           return XK_F8;
  case keys::f9:           return XK_F9;
  case keys::f10:          return XK_F10;
  case keys::f11:          return XK_F11;
  case keys::f12:          return XK_F12;
  case keys::tilde:        return XK_grave;
  case keys::one:          return XK_1;
  case keys::two:          return XK_2;
  case keys::three:        return XK_3;
  case keys::four:         return XK_4;
  case keys::five:         return XK_5;
  case keys::six:          return XK_6;
  case keys::seven:        return XK_7;
  case keys::eight:        return XK_8;
  case keys::nine:         return XK_9;
  case keys::zero:         return XK_0;
  case keys::minus:        return XK_minus;
  case keys::equal:        return XK_equal;
  case keys::a:            return XK_a;
  case keys::b:            return XK_b;
  case keys::c:            return XK_c;
  case keys::d:            return XK_d;
  case keys::e:            return XK_e;
  case keys::f:            return XK_f;
  case keys::g:            return XK_g;
  case keys::h:            return XK_h;
  case keys::i:            return XK_i;
  case keys::j:            return XK_j;
  case keys::k:            return XK_k;
  case keys::l:            return XK_l;
  case keys::m:            return XK_m;
  case keys::n:            return XK_n;
  case keys::o:            return XK_o;
  case keys::p:            return XK_p;
  case keys::q:            return XK_q;
  case keys::r:            return XK_r;
  case keys::s:            return XK_s;
  case keys::t:            return XK_t;
  case keys::u:            return XK_u;
  case keys::v:            return XK_v;
  case keys::w:            return XK_w;
  case keys::x:            return XK_x;
  case keys::y:            return XK_y;
  case keys::z:            return XK_z;
  case keys::bracket_l:    return XK_bracketleft;
  case keys::bracket_r:    return XK_bracketright;
  case keys::backslash:    return XK_backslash;
  case keys::semicolon:    return XK_semicolon;
  case keys::quote:        return XK_quoteright;
  case keys::comma:        return XK_comma;
  case keys::period:       return XK_period;
  case keys::slash:        return XK_slash;
  case keys::num_zero:     return XK_KP_Insert;
  case keys::num_one:      return XK_KP_End;
  case keys::num_two:      return XK_KP_Down;
  case keys::num_three:    return XK_KP_Page_Down;
  case keys::num_four:     return XK_KP_Left;
  case keys::num_five:     return XK_KP_Begin;
  case keys::num_six:      return XK_KP_Right;
  case keys::num_seven:    return XK_KP_Home;
  case keys::num_eight:    return XK_KP_Up;
  case keys::num_nine:     return XK_KP_Page_Up;
  case keys::num_add:      return XK_KP_Add;
  case keys::num_minus:    return XK_KP_Subtract;
  case keys::num_mult:     return XK_KP_Multiply;
  case keys::num_div:      return XK_KP_Divide;
  case keys::num_dec:      return XK_KP_Decimal;
  case keys::none:         //fall-through
  case keys::unknown:      break;
  }

  return 0;
}

keys key_util::key_from_code(int key_code)
{
  switch (key_code)
  {
  case XK_Shift_L:        return keys::shift_l;
  case XK_Shift_R:        return keys::shift_r;
  case XK_Alt_L:          return keys::alt_l;
  case XK_Alt_R:          return keys::alt_r;
  case XK_Control_L:      return keys::ctrl_l;
  case XK_Control_R:      return keys::ctrl_r;
  case XK_Super_L:        return keys::super_l;
  case XK_Super_R:        return keys::super_r;
  case XK_Escape:         return keys::escape;
  case XK_Insert:         return keys::insert;
  case XK_Home:           return keys::home;
  case XK_End:            return keys::end;
  case XK_Page_Up:        return keys::pageup;
  case XK_Page_Down:      return keys::pagedown;
  case XK_Print:          return keys::print;
  case XK_Pause:          return keys::pause;
  case XK_BackSpace:      return keys::backspace;
  case XK_Delete:         return keys::del;
  case XK_Tab:            return keys::tab;
  case XK_Return:         return keys::enter;
  case XK_Menu:           return keys::menu;
  case XK_space:          return keys::space;
  case XK_Up:             return keys::up;
  case XK_Down:           return keys::down;
  case XK_Left:           return keys::left;
  case XK_Right:          return keys::right;
  case XK_F1:             return keys::f1;
  case XK_F2:             return keys::f2;
  case XK_F3:             return keys::f3;
  case XK_F4:             return keys::f4;
  case XK_F5:             return keys::f5;
  case XK_F6:             return keys::f6;
  case XK_F7:             return keys::f7;
  case XK_F8:             return keys::f8;
  case XK_F9:             return keys::f9;
  case XK_F10:            return keys::f10;
  case XK_F11:            return keys::f11;
  case XK_F12:            return keys::f12;
  case XK_grave:          return keys::tilde;
  case XK_1:              return keys::one;
  case XK_2:              return keys::two;
  case XK_3:              return keys::three;
  case XK_4:              return keys::four;
  case XK_5:              return keys::five;
  case XK_6:              return keys::six;
  case XK_7:              return keys::seven;
  case XK_8:              return keys::eight;
  case XK_9:              return keys::nine;
  case XK_0:              return keys::zero;
  case XK_minus:          return keys::minus;
  case XK_equal:          return keys::equal;
  case XK_a:              return keys::a;
  case XK_b:              return keys::b;
  case XK_c:              return keys::c;
  case XK_d:              return keys::d;
  case XK_e:              return keys::e;
  case XK_f:              return keys::f;
  case XK_g:              return keys::g;
  case XK_h:              return keys::h;
  case XK_i:              return keys::i;
  case XK_j:              return keys::j;
  case XK_k:              return keys::k;
  case XK_l:              return keys::l;
  case XK_m:              return keys::m;
  case XK_n:              return keys::n;
  case XK_o:              return keys::o;
  case XK_p:              return keys::p;
  case XK_q:              return keys::q;
  case XK_r:              return keys::r;
  case XK_s:              return keys::s;
  case XK_t:              return keys::t;
  case XK_u:              return keys::u;
  case XK_v:              return keys::v;
  case XK_w:              return keys::w;
  case XK_x:              return keys::x;
  case XK_y:              return keys::y;
  case XK_z:              return keys::z;
  case XK_bracketleft:    return keys::bracket_l;
  case XK_bracketright:   return keys::bracket_r;
  case XK_backslash:      return keys::backslash;
  case XK_semicolon:      return keys::semicolon;
  case XK_quoteright:     return keys::quote;
  case XK_comma:          return keys::comma;
  case XK_period:         return keys::period;
  case XK_slash:          return keys::slash;
  case XK_KP_Insert:      return keys::num_zero;
  case XK_KP_End:         return keys::num_one;
  case XK_KP_Down:        return keys::num_two;
  case XK_KP_Page_Down:   return keys::num_three;
  case XK_KP_Left:        return keys::num_four;
  case XK_KP_Begin:       return keys::num_five;
  case XK_KP_Right:       return keys::num_six;
  case XK_KP_Home:        return keys::num_seven;
  case XK_KP_Up:          return keys::num_eight;
  case XK_KP_Page_Up:     return keys::num_nine;
  case XK_KP_Add:         return keys::num_add;
  case XK_KP_Subtract:    return keys::num_minus;
  case XK_KP_Multiply:    return keys::num_mult;
  case XK_KP_Divide:      return keys::num_div;
  case XK_KP_Delete:      return keys::num_dec;
  default:                return keys::none;
  }
}


} // namespace glug
