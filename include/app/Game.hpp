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
std::vector<Projectile> _projectiles;

public:

Game();
//~Game();

void display();
void resize(size_t width, size_t height);
void update(float elapsedTime);

void fire(int x,int y);
void collision();

};

#endif
