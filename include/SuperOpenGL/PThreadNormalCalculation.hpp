#ifndef SUPEROPENGL_PTHREADNORMALCALCULATION_HPP
#define SUPEROPENGL_PTHREADNORMALCALCULATION_HPP

#include "NormalCalculation.hpp"

namespace SuperOpenGL {

class PThreadNormalCalculation : public NormalCalculation
{
public:
  PThreadNormalCalculation(const Object& object);
  PThreadNormalCalculation(const Object& object, const size_t threadsAmount);

  void calculate();

private:
  const size_t _threadsAmount;
};

} // namespace lib

#endif
