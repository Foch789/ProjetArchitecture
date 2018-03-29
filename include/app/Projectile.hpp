#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SuperOpenGL/Vector.hpp>

class Projectile
{
public:
    constexpr static const float speed = 0.1;
    constexpr static const float size = 5;

    Projectile(SuperOpenGL::Vector position, SuperOpenGL::Vector direction);

    void display();
    void update(float elapsedTime);
    SuperOpenGL::Vector position() const { return _position; }

private:
    SuperOpenGL::Vector _direction;
    SuperOpenGL::Vector _position;
};

#endif
