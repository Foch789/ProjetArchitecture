#include <app/Target.hpp>
#include <SuperOpenGL/Object.hpp>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

Target::Target() : speed(0)
{
        std::ifstream file("assets/models/100x100pointsUV.off");
        SuperOpenGL::Object object = SuperOpenGL::Object::readOFF(file, true);

        vertices.reserve(object.vertices().size());
        for (size_t i = 0; i < object.vertices().size(); ++i) {
                Vertex v;
                v.position = object.vertices()[i];
                v.text = object.textureCoordinates()[i];
                vertices.push_back(v);
        }

        faces.reserve(object.faces().size());
        for (size_t i = 0; i < object.faces().size(); ++i) {
                faces.push_back(object.faces()[i]);
        }

        texture.loadJPEG("assets/texture/texture.jpg");
}

Target::~Target()
{
}

void Target::display()
{
        glEnable(GL_TEXTURE_2D);

        texture.use();
        glPushMatrix();
            glRotatef(180.f, 0.f, 0.f, 1.f);
            glInterleavedArrays(GL_T2F_V3F,0,vertices.data());
            glDrawElements(GL_TRIANGLES,faces.size()*3,GL_UNSIGNED_INT, faces.data());
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
}
