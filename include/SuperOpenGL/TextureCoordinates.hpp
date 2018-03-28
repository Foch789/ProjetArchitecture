#ifndef SUPEROPENGL_TEXTURECOORDINATES_HPP
#define SUPEROPENGL_TEXTURECOORDINATES_HPP

#include <iostream>

namespace SuperOpenGL {

class TextureCoordinates
{
public:
  float u, v;

  TextureCoordinates();
  TextureCoordinates(const float u, const float v);

  friend std::ostream& operator<<(std::ostream&, const TextureCoordinates&);
  friend std::istream& operator>>(std::istream&, TextureCoordinates&);
};

}

#endif
