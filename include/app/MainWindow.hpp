#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <memory>

#include <SuperOpenGL/Window.hpp>
#include <app/Game.hpp>

class MainWindow : public SuperOpenGL::Window {

private:

std::unique_ptr<Game> game;

protected:

virtual void display();
virtual void keyPressed(unsigned char key, int x, int y);
virtual void specialKeyPressed(int key, int x, int y);
virtual void mouseClicked(int button, int state, int x, int y);
virtual void update(const float elaspedTime);

public:

MainWindow();
void init();


};

#endif
