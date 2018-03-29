#include <app/Game.hpp>
#include <GL/freeglut.h>
#include <algorithm>

Game::Game()
{
    camera.eye = {0, 0, 300};
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
    for (Projectile &p : _projectiles)
        p.update(elapsedTime);
    collision();
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

    glClear(GL_DEPTH_BUFFER_BIT);
    camera.use();
    GLfloat vertices[] = {-1000, -1000, 0, // bottom left corner
                          -1000,  1000, 0, // top left corner
                           1000,  1000, 0, // top right corner
                           1000, -1000, 0}; // bottom right corner

    GLubyte indices[] = {0,1,2, // first triangle (bottom left - top left - top right)
                         0,2,3}; // second triangle (bottom left - top right - bottom right)

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
    _projectiles.push_back(Projectile(camera.eye, SuperOpenGL::Vector{float(posX), float(posY), -1} - camera.eye));
}

void Game::collision()
{
    _projectiles.erase(std::remove_if(_projectiles.begin(), _projectiles.end(), [](const Projectile &p){
        return p.position().z < -100;
    }), _projectiles.end());
}
