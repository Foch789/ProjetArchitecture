#include <app/Target.hpp>
#include <SuperOpenGL/Object.hpp>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>

Target::Target() : speed(0)
{
        std::ifstream file("assets/models/100x100points.off");
        SuperOpenGL::Object object;

        object.readOFF(file);

        vertices.reserve(object.vertices().size());
        for (size_t i = 0; i < object.vertices().size(); ++i) {
                Vertex v;
                v.position = object.vertices()[i];
                vertices.push_back(v);
        }

        faces.reserve(object.faces().size());
        for (size_t i = 0; i < object.faces().size(); ++i) {
                faces.push_back(object.faces()[i]);
        }



}

Target::~Target()
{
}

void Target::display()
{
        //glEnable(GL_TEXTURE_2D);

        glInterleavedArrays(GL_V3F,0,&vertices);
        glDrawElements(GL_TRIANGLES,faces.size(),GL_UNSIGNED_INT,&faces);

        //glDisable(GL_TEXTURE_2D);
}
