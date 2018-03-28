#include <SuperOpenGL/TextureCoordinates.hpp>

namespace SuperOpenGL {

TextureCoordinates::TextureCoordinates()
    : u(0), v(0)
{}

TextureCoordinates::TextureCoordinates(const float u, const float v)
    : u(u), v(v)
{}

std::ostream &operator<<(std::ostream &os, const TextureCoordinates &tc)
{
    return os << tc.u << ' ' << tc.v;
}

std::istream &operator>>(std::istream &is, TextureCoordinates &tc)
{
    return is >> tc.u >> tc.v;
}

}
