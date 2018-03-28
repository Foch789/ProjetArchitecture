#ifndef TARGET_HPP
#define TARGET_HPP

#include <SuperOpenGL/Vector.hpp>
#include <SuperOpenGL/Face.hpp>
#include <SuperOpenGL/TextureCoordinates.hpp>

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

//Texture texture
Target();
~Target();

void display();

};

#endif
