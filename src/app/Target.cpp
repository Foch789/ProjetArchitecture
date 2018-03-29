#include <app/Target.hpp>
#include <SuperOpenGL/Object.hpp>
#include <fstream>
#include <iostream>
#include <cmath>
#include <GL/freeglut.h>
#include <random>


Target::Target() : speed(0)
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
        //glEnable(GL_TEXTURE_2D);

        glColor3f(0.5, 0.5, 0.5);

        prog.use();

        glInterleavedArrays(GL_T2F_V3F,0,vertices.data());
        glDrawElements(GL_TRIANGLES,faces.size()*3,GL_UNSIGNED_INT, faces.data());



        //glDisable(GL_TEXTURE_2D);
}

void Target::update(float time)
{

        timeT+=time;
        if (timeT > 10000) {

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_real_distribution<> dis(-1, 1);
                direction.x = dis(gen);
                direction.y = dis(gen);
                direction.z = dis(gen);
                direction *= 2;
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

        //std::cout << position << std::endl;


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
        zone[2].z = -distance;

        zone[3].x = -point+width;
        zone[3].y = 0;
        zone[3].z = -distance;

}

void sendDeform(SuperOpenGL::Vector _center,SuperOpenGL::Vector _vector,float _rayon)
{


}
