#include <app/MainWindow.hpp>
#include <GL/freeglut.h>

MainWindow::MainWindow()
        : Window("Projet architecture")
{
}


void MainWindow::init()
{
        game = std::make_unique<Game>();
}


void MainWindow::display()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        game->display();

        glutSwapBuffers();
}

void MainWindow::reshaped(size_t width, size_t height)
{
        glViewport(0, 0, width, height);
        game->resize(width, height);
}

void MainWindow::keyPressed(unsigned char key, int x, int y)
{

        switch (key) {
        case 'p':
                game->pause();
                break;
        }

}

void MainWindow::specialKeyPressed(int key, int x, int y)
{

}

void MainWindow::mouseClicked(int button, int state, int x, int y)
{
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
                game->fire(x, y);
}

void MainWindow::update(const float elaspedTime)
{
        game->update(elaspedTime);
}
