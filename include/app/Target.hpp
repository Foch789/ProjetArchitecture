#ifndef TARGET_HPP
#define TARGET_HPP

#include <SuperOpenGL/Vector.hpp>
#include <SuperOpenGL/Face.hpp>
#include <SuperOpenGL/TextureCoordinates.hpp>
#include <SuperOpenGL/Texture.hpp>
#include <SuperOpenGL/VertexShader.hpp>
#include <SuperOpenGL/FragmentShader.hpp>
#include <SuperOpenGL/Program.hpp>
#include <GL/glew.h>
#include <vector>

typedef struct
{
        //  GLfloat nx, ny, nz;   // Coordonnees de la normale associ�e � ce point
        SuperOpenGL::TextureCoordinates text;
        SuperOpenGL::Vector position;
} Vertex;

typedef struct
{
        SuperOpenGL::Program prog;
        GLint _centre;
        GLint _vecteur;
        GLint _rayon;
        SuperOpenGL::Vector center;
        SuperOpenGL::Vector vector;
        float rayon;

} Deform;

class Target
{

public:

SuperOpenGL::Vector position;
SuperOpenGL::Vector direction;
SuperOpenGL::Texture texture;

std::vector<Vertex> vertices;
std::vector<SuperOpenGL::Face> faces;
std::vector<Deform> deform;

SuperOpenGL::VertexShader vs;
SuperOpenGL::FragmentShader fs;
SuperOpenGL::Program prog;

SuperOpenGL::Vector zone[4];

float timeT;
GLint loc;
float width;

Target();
~Target();

void display();

void update(float time);

void zoneT(float distance,float angle);

void sendDeform(SuperOpenGL::Vector _center,SuperOpenGL::Vector _vector,float _rayon);

};

#endif
