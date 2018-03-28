#ifndef SUPEROPENGL_VERTEX_HPP
#define SUPEROPENGL_VERTEX_HPP

#include <iostream>

namespace SuperOpenGL {

class Vector;

class Vertex
{
public:
float x;
float y;
float z;

Vertex();
Vertex(const float x, const float y, const float z);
Vertex(const Vertex&);
Vertex(const Vector&);
~Vertex();

bool operator==(const Vertex&) const;

Vertex& operator=(const Vertex&);
Vertex& operator=(const Vector&);

Vertex operator+(const Vertex&) const;
Vertex operator+(const Vector&) const;
Vertex& operator+=(const Vector&);

Vertex operator-(const Vertex&) const;

Vertex operator*(const Vertex&) const;
Vertex& operator*=(const Vertex&);

Vertex operator*(const float) const;
Vertex& operator*=(const float);

Vertex operator/(const float) const;
Vertex& operator/=(const float);

Vertex operator/(const Vertex&) const;
Vertex& operator/=(const Vertex&);

friend std::ostream& operator<<(std::ostream&, const Vertex&);
friend std::istream& operator>>(std::istream&, Vertex&);
};

}

#endif
