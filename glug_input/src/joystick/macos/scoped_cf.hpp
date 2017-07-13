#ifndef GLUG_SCOPED_CF_HPP
#define GLUG_SCOPED_CF_HPP

namespace glug
{

template <typename cf_ref>
class scoped_cf
{
public:
  scoped_cf(cf_ref cf):
    cf(cf)
  {}
  virtual ~scoped_cf() { if (cf) CFRelease(cf); }

  bool operator !() { return cf == nullptr; }
  operator bool() { return !operator!(); }
  operator cf_ref() { return cf; }
  cf_ref *operator &() { return &cf; }

protected:
  void operator =(const scoped_cf &) = delete;
  cf_ref cf;
};

} // namespace glug

#endif // GLUG_SCOPED_CF_HPP
