#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SuperOpenGL/Vector.hpp>

class Projectile
{
public:
    Projectile(SuperOpenGL::Vector position, SuperOpenGL::Vector direction);

    void display();
    void update(float elapsedTime);

private:
    constexpr static const float _speed = 0.1;
    constexpr static const float _size = 5;
    SuperOpenGL::Vector _direction;
    SuperOpenGL::Vector _position;
};

#endif
