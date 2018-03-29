#ifndef SUPEROPENGL_PROGRAM_HPP
#define SUPEROPENGL_PROGRAM_HPP

#include <SuperOpenGL/Shader.hpp>

namespace SuperOpenGL {

class Program {
public:
Program();

void attach(const Shader &shader);
void detach(const Shader &shader);
void link();
void enable();
void disable();
inline GLuint id() const {
        return _id;
}
std::string info();

private:
static GLuint _emptyId;
GLuint _id;
};

}

#endif
