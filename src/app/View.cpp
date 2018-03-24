#include <app/View.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>

View::View() : width(0),height(0),depth(0)
{

}

View::~View()
{
}


View::useView()
{

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glOrtho((width/2.0),(width/2.0),(height/2.0),(height/2.0),0,depth);

}