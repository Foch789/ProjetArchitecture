#ifndef TARGET_HPP
#define TARGET_HPP

#include <SuperOpenGL/Vector.hpp>
#include <SuperOpenGL/Vertex.hpp>
#include <SuperOpenGL/Face.hpp>
#include <SuperOpenGL/TextureCoordinates.hpp>
#include <SuperOpenGL/Texture.hpp>
#include <SuperOpenGL/VertexShader.hpp>
#include <SuperOpenGL/FragmentShader.hpp>
#include <SuperOpenGL/Program.hpp>
#include <GL/glew.h>
#include <vector>
#include <list>
#include <glm/vec3.hpp>

typedef struct
{
        SuperOpenGL::TextureCoordinates text;
        SuperOpenGL::Vector position;
} Vertex;


class Target
{

public:

GLint loc;
SuperOpenGL::Vector position;
SuperOpenGL::Vector direction;
SuperOpenGL::Texture texture;

std::vector<Vertex> vertices;
std::vector<SuperOpenGL::Face> faces;

GLint _centre;
GLint _vecteur;
GLint _rayon;
GLint _t;
std::vector<glm::vec3> centre;
std::vector<glm::vec3> def;
std::vector<float> rayon;
bool touche;
float t;
int nbr;
bool p;

SuperOpenGL::VertexShader vs;
SuperOpenGL::FragmentShader fs;
SuperOpenGL::Program prog;

SuperOpenGL::Vector zone[4];

float timeT;
float width;
SuperOpenGL::Vertex max;
SuperOpenGL::Vertex min;

Target();
~Target();

void display();

void update(float time);

void zoneT(float distance,float angle);

void sendDeform(SuperOpenGL::Vector _center,SuperOpenGL::Vector _vector,float _rayon);
void boundingBox(SuperOpenGL::Vector &topLeft, SuperOpenGL::Vector &bottomRight);
void pause();

};

#endif
