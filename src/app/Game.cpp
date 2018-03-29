#include <app/Game.hpp>
#include <GL/freeglut.h>

Game::Game()
{

        target.zoneT(500.0,22.5);
        camera.eye = {0, 0, 500};
        camera.center = {0, 0, 0};
        camera.up = {0, 1, 0};

}

void Game::display()
{
        camera.use();
        target.display();

        for (Projectile &p : _projectiles)
                p.display();
}

void Game::resize(size_t width, size_t height)
{
        camera.windowWidth = width;
        camera.windowHeight = height;
}

void Game::update(float elapsedTime)
{
        target.update(elapsedTime);
        for (Projectile &p : _projectiles)
                p.update(elapsedTime);
}

void Game::fire(int x, int y)
{
        GLint viewport[4];
        GLdouble modelview[16];
        GLdouble projection[16];
        GLfloat winX, winY, winZ;
        GLdouble posX, posY, posZ;

        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);
        glGetIntegerv(GL_VIEWPORT, viewport);

        winX = float(x);
        winY = float(viewport[3]) - float(y);
        glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

        gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
        std::cout << winX << ' ' << winY << ' ' << winZ << std::endl;
        //std::cout << posX << ' ' << posY << ' ' << posZ << std::endl;
        _projectiles.push_back(Projectile(camera.eye, SuperOpenGL::Vector {float(posX), float(posY), -1} -camera.eye));
}

void Game::collision()
{

}
