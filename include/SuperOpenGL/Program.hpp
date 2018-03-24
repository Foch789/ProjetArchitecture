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
    void use();
    std::string info();

private:
    GLuint _id;
};

}

#endif
