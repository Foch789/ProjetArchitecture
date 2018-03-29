#include <app/Target.hpp>
#include <SuperOpenGL/Object.hpp>
#include <fstream>
#include <iostream>
#include <cmath>
#include <GL/freeglut.h>
#include <random>


Target::Target()
{
        std::ifstream file("assets/models/100x100pointsUV.off");
        SuperOpenGL::Object object = SuperOpenGL::Object::readOFF(file, true);

        width = (object.max().x-object.min().x)+20;

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

        vs.readSource("assets/shaders/target.vert");
        vs.compile();

        fs.readSource("assets/shaders/target.frag");
        fs.compile();

        prog.attach(vs);
        prog.link();

        //std::cout << vs.info() << std::endl;
        //std::cout << prog.info() << std::endl;

        loc = glGetUniformLocation(prog.id(),"pos");

        position.x = 0;
        position.y = 0;
        position.z = 0;
        timeT = 10000;

        std::cout << object.max().x << " " << object.min().x << std::endl;
}

Target::~Target()
{
}

void Target::display()
{
        prog.enable();
        glEnable(GL_TEXTURE_2D);
        texture.enable();
        glPushMatrix();
        glRotatef(180.f, 0.f, 0.f, 1.f);
        glInterleavedArrays(GL_T2F_V3F,0,vertices.data());
        glDrawElements(GL_TRIANGLES,faces.size()*3,GL_UNSIGNED_INT, faces.data());
        glPopMatrix();
        texture.disable();
        glDisable(GL_TEXTURE_2D);
        prog.disable();
}

void Target::update(float time)
{
        prog.enable();
        timeT+=time;
        if (timeT > 10000) {

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_real_distribution<> dis(-1, 1);
                direction.x = dis(gen);
                direction.y = dis(gen);
                direction.z = dis(gen);
                direction *= 4;
                timeT -= 10000;
        }

        glUniform3fv(loc, 1, reinterpret_cast<GLfloat*>(&position));
        //glUniform3fv(loc, 1, &position.x);

        if ((position.x + direction.x) >= zone[0].x)
        {
                direction.x = -(direction.x);
        }

        if ((position.x + direction.x) <= zone[1].x)
        {
                direction.x = -(direction.x);
        }

        if ((position.z + direction.z) >= zone[0].z) {
                direction.z = -(direction.z);
        }

        if ((position.z + direction.z) <= zone[2].z) {
                direction.z = -(direction.z);
        }

        if((position.y + direction.y) >= zone[0].x)
        {
                direction.y = -(direction.y);
        }

        if ((position.y + direction.y) <= 0) {
                direction.y = -(direction.y);
        }

        position+=direction.normalize(1.0);

        prog.disable();

}

void Target::zoneT(float distance,float angle)
{

        float hypo = distance/cos(angle);

        float point = sqrt(pow(hypo,2)-pow(distance,2));

        //std::cout << point<< std::endl;
        //std::cout << distance << std::endl;

        zone[0].x = point-width;
        zone[0].y = 0;
        zone[0].z = 0;

        zone[1].x = -point+width;
        zone[1].y = 0;
        zone[1].z = 0;

        zone[2].x = point-width;
        zone[2].y = 0;
        zone[2].z = -(distance/2.0);

        zone[3].x = -point+width;
        zone[3].y = 0;
        zone[3].z = -(distance/2.0);

}

void sendDeform(SuperOpenGL::Vector _center,SuperOpenGL::Vector _vector,float _rayon)
{


}
