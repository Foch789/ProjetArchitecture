#include <app/Projectile.hpp>
#include <GL/freeglut.h>

#include <iostream>

Projectile::Projectile(SuperOpenGL::Vector position, SuperOpenGL::Vector direction)
    : _direction(direction)
    , _position(position)
{}

void Projectile::display()
{
    glTranslatef(_position.x, _position.y, _position.z);
    glutSolidSphere(_size, 180, 180);
}

void Projectile::update(float elapsedTime)
{
    _position += _direction * _speed * elapsedTime;
    std::cout << _position << std::endl;
}
