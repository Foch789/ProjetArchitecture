#ifndef GAME_HPP
#define GAME_HPP

#include "View.hpp"
#include "Target.hpp"
#include "Projectile.hpp"

class Game
{

private:

View camera;
Target target;
Projectile *projectiles;

public:

Game();
~Game();

void displayMain()
void update();

void fire();
void collision();

};

#endif
