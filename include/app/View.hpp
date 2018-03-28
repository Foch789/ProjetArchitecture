#ifndef VIEW_HPP
#define VIEW_HPP

#include <SuperOpenGL/Vector.hpp>

class View
{

public:
size_t windowWidth, windowHeight;
SuperOpenGL::Vector eye, center, up;

View();

void use();

};

#endif
