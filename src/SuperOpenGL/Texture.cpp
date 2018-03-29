#include <SuperOpenGL/Texture.hpp>
#include <SuperOpenGL/ColorImage.hpp>

namespace SuperOpenGL {

Texture::Texture()
    : _id(0)
    , _width(0)
    , _height(0)
{
    glGenTextures(1, &_id);
    setFilter(GL_NEAREST, GL_NEAREST);
    setWrap(GL_REPEAT, GL_REPEAT);
    setBlending(GL_DECAL);
}

void Texture::loadJPEG(const std::string &fileName)
{
    std::unique_ptr<ColorImage> image(ColorImage::readJPEG(fileName));
    _width = image->width();
    _height = image->height();
    enable();
    glTexImage2D(GL_TEXTURE_2D, 0, 3, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, &image->pixel(0, 0));
}

void Texture::enable() {
    glBindTexture(GL_TEXTURE_2D, _id);
}

void Texture::disable() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::setFilter(GLint min, GLint mag) {
    enable();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag);
}

void Texture::setWrap(GLint s, GLint t) {
    enable();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, t);
}

void Texture::setBlending(GLint m) {
    enable();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, m);
}


}
