#include <app/Game.hpp>

Game::Game()
{
        camera.width = 300;
        camera.height = 300;
        camera.depth = 300;
}

Game::~Game()
{

}

void Game::display()
{
        camera.useView();
        target.display();

        for (Projectile &p : _projectiles)
            p.display();
}

void Game::update(float elapsedTime)
{
//    for (Projectile &p : _projectiles)
//        p.update(elapsedTime);
}

void Game::fire(int x,int y)
{
    _projectiles.push_back(Projectile({0.5, 0.5, 0}, {1, 0, 0}));
}

void Game::collision()
{

}
