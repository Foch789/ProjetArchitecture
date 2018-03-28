#ifndef SUPEROPENGL_OBJECT_HPP
#define SUPEROPENGL_OBJECT_HPP

#include <deque>
#include <iostream>

#include "Face.hpp"
#include "Vector.hpp"
#include "Vertex.hpp"
#include "TextureCoordinates.hpp"

namespace SuperOpenGL {

class Object // représente un maillage 3d
{
public:
Object() = default;
Object(const Object&) = default;
~Object() = default;

inline const std::deque<Vertex>& vertices() const {
        return _vertices;
}
inline const std::deque<Face>& faces() const {
        return _faces;
}
inline const std::deque<TextureCoordinates>& textureCoordinates() const {
        return _textureCoordinates;
}

inline const Vertex& min() const {
        return _min;
}
inline const Vertex& max() const {
        return _max;
}
inline const Vertex& centroid() const {
        return _centroid;
}

static Object randGen(const size_t nbVertices, const size_t nbFaces);

static Object readOFF(std::istream&, const bool hasUV = false);
void writeOFF(std::ostream&) const;

void writeOBJ(std::ostream&, const std::deque<Vector>& vertexNormal) const;

private:
std::deque<Vertex> _vertices;
std::deque<Face> _faces;
std::deque<TextureCoordinates> _textureCoordinates;

Vertex _min;
Vertex _max;
Vertex _centroid;
};

}

#endif
