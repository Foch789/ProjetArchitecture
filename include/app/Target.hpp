#ifndef TARGET_HPP
#define TARGET_HPP

#include <SuperOpenGL/Vector.hpp>
#include <SuperOpenGL/Face.hpp>

#include <vector>

typedef struct                // Definition d'un point du terrain
{
        //float s, t; // Coordonnees de texture
        //  GLfloat nx, ny, nz;   // Coordonnees de la normale associ�e � ce point
        SuperOpenGL::Vector position;       // Coordonnees dans le plan xz
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
