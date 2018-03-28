#ifndef SUPEROPENGL_FACE_HPP
#define SUPEROPENGL_FACE_HPP

#include <iostream>

namespace SuperOpenGL {

// faire un template pour size_t et Vertex
class Face
{
public:
unsigned int v0, v1, v2;

Face();
Face(const Face&);
Face(const unsigned int v0, const unsigned int v1, const unsigned int v2);
~Face() = default;

Face& operator=(const Face&);

friend std::ostream& operator<<(std::ostream&, const Face&);
friend std::istream& operator>>(std::istream&, Face&);
};

}

#endif
