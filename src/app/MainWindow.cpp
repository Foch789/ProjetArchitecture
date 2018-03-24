#include <app/MainWindow.hpp>

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

        game->display();

}

void MainWindow::keyPressed(unsigned char key, int x, int y)
{

}

void MainWindow::specialKeyPressed(int key, int x, int y)
{

}

void MainWindow::mouseClicked(int button, int state, int x, int y)
{

}

void MainWindow::update(const float elaspedTime)
{

        game->update(elaspedTime);

}
