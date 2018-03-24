#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SuperOpenGL/Vector.hpp>

class Projectile
{

public:

SuperOpenGL::Vector direction;
float speed;
float size;

Projectile();
~Projectile();


void displayProjectile();

};

#endif
