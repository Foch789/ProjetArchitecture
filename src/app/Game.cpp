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
        //projectiles
}

void Game::update(float time)
{

}

void Game::fire(int x,int y)
{

}

void Game::collision()
{

}
