#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "View.hpp"
#include "Target.hpp"
#include "Projectile.hpp"

class Game
{

private:

View camera;
Target target;
std::vector<Projectile> projectiles;

public:

Game();
~Game();

void display();
void update(float time);

void fire(int x,int y);
void collision();

};

#endif
