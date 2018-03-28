#include <app/Game.hpp>

Game::Game() : mytime(0)
{

        target.zone()
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
