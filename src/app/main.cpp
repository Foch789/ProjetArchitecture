#include <app/MainWindow.hpp>

static void InitializeGL();

int main()
{

        glutInit(&argc, argv);

        MainWindow window;
        window.resize(600,600);

        GLenum res = glewInit();

        if (res != GLEW_OK) {
                cerr << "Error: " << glewGetErrorString(res) << endl;
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
