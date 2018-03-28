#ifndef TARGET_HPP
#define TARGET_HPP

#include <SuperOpenGL/Vector.hpp>
#include <SuperOpenGL/Face.hpp>
#include <SuperOpenGL/TextureCoordinates.hpp>
#include <SuperOpenGL/VertexShader>
#include <SuperOpenGL/Program>

#include <vector>

typedef struct
{
        //  GLfloat nx, ny, nz;   // Coordonnees de la normale associ�e � ce point
        SuperOpenGL::TextureCoordinates text;
        SuperOpenGL::Vector position;
} Vertex;

class Target
{

public:

float speed;
SuperOpenGL::Vector position;
SuperOpenGL::Vector direction;

std::vector<Vertex> vertices;
std::vector<SuperOpenGL::Face> faces;

SuperOpenGL::VertexShader vs;
SuperOpenGL::Program prog;

std::vector<SuperOpenGL::Vector> zone;

Target();
~Target();

void display();

void update(float time);

void zone(float distance,float angle);

};

#endif
