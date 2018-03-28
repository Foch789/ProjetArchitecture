#include <app/Projectile.hpp>
#include <GL/freeglut.h>

Projectile::Projectile() : speed(0),size(0)
{
}

Projectile::~Projectile()
{
}

void Projectile::displayProjectile()
{
        //glTranslatef();
        glutSolidSphere(size,180,180);
}
