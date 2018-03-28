#include <app/MainWindow.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

static void InitializeGL();

int main(int argc, char **argv)
{

        glutInit(&argc, argv);

        MainWindow window;
        window.resize(600,600);

        GLenum res = glewInit();

        if (res != GLEW_OK) {
                std::cerr << "Error: " << glewGetErrorString(res) << std::endl;
                return (EXIT_FAILURE);
        }

        InitializeGL();
        window.init();

        glutMainLoop();

        return (EXIT_SUCCESS);
}


static void InitializeGL()
{

        glShadeModel(GL_SMOOTH);

        glEnable(GL_DEPTH_TEST);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}
