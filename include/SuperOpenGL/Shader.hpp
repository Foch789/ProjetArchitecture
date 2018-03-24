#ifndef SUPEROPENGL_SHADER_HPP
#define SUPEROPENGL_SHADER_HPP

#include <GL/glew.h>
#include <string>
#include <istream>

namespace SuperOpenGL {

class Shader {
public:
    Shader(const GLenum type);

    void readSource(const std::string &fileName);
    void setSource(const std::istream &src);
    void setSource(const std::string &src);
    bool compile();

private:
    GLuint _id;
};

}

#endif
