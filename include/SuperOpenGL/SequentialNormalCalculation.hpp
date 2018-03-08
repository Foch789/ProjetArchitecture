#ifndef SUPEROPENGL_SEQUENTIALNORMALCALCULATION_HPP
#define SUPEROPENGL_SEQUENTIALNORMALCALCULATION_HPP

#include "NormalCalculation.hpp"

namespace SuperOpenGL {

class SequentialNormalCalculation : public NormalCalculation
{
public:
  SequentialNormalCalculation(const Object& object);

  void calculate();
};

}

#endif
