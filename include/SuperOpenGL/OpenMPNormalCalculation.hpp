#ifndef SUPEROPENGL_OPENMPNORMALCALCULATION_HPP
#define SUPEROPENGL_OPENMPNORMALCALCULATION_HPP

#include "NormalCalculation.hpp"

namespace SuperOpenGL {

class OpenMPNormalCalculation : public NormalCalculation
{
public:
  OpenMPNormalCalculation(const Object& object);
  OpenMPNormalCalculation(const Object& object, const size_t threadsAmount);

  void calculate();
};

}

#endif
