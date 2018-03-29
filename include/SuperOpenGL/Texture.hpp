#ifndef SUPEROPENGL_TEXTURE_HPP
#define SUPEROPENGL_TEXTURE_HPP

#include <GL/glew.h>
#include <string>

namespace SuperOpenGL {

class Texture {
public:
    Texture();

    void loadJPEG(const std::string &fileName);

    void enable();
    void disable();

    void setFilter(GLint min, GLint mag);

    void setWrap(GLint s, GLint t);

    void setBlending(GLint m);

private:
    GLuint _id;
    size_t _width, _height;
    //std::unique_ptr<stbi_uc[]> img;
};

}

#endif
