#include <SuperOpenGL/Shader.hpp>

#include <sstream>
#include <fstream>

namespace SuperOpenGL {

Shader::Shader(const GLenum type)
{
    _id = glCreateShader(type);
}

void Shader::readSource(const std::string &fileName)
{
    std::ifstream file(fileName);
    if (file.is_open())
        setSource(file);
    else
        throw std::runtime_error("Error trying read file.");
}

void Shader::setSource(const std::istream &src)
{
    std::stringstream buff;
    buff << src.rdbuf();
    setSource(buff.str());
}

void Shader::setSource(const std::string &src)
{
    const GLchar *str[1] = {src.c_str()};
    glShaderSource(_id, 1, str, NULL);
}

bool Shader::compile()
{
    glCompileShader(_id);
    GLint r;
    glGetShaderiv(_id, GL_COMPILE_STATUS, &r);
    return r == GL_TRUE ? true : false;
}

std::string Shader::info()
{
    int length = 0;
    int charsWritten  = 0;
    std::string info;

    glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &length);
    info.reserve(length);

    if (length > 0)
        glGetShaderInfoLog(_id, length, &charsWritten, &info[0]);

    return info;
}

}
