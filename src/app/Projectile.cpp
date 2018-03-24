#include <app/Projectile.hpp>

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
