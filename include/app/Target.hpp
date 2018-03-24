#ifndef TARGET_HPP
#define TARGET_HPP

#include <SuperOpenGL/Vector.hpp>

class Target
{

public:

float speed;
SuperOpenGL::Vector position;
SuperOpenGL::Vector direction;
//Texture texture
//charger objet

Target();
~Target();

void displayTarget();

};

#endif
