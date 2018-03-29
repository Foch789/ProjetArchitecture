#include <SuperOpenGL/Program.hpp>

namespace SuperOpenGL {

GLuint Program::_emptyId = 0;

Program::Program()
{
    if (_emptyId == 0) {
        _emptyId = glCreateProgram();
        glLinkProgram(_emptyId);
    }
    _id = glCreateProgram();
}

void Program::attach(const Shader &shader)
{
    glAttachShader(_id, shader._id);
}

void Program::detach(const Shader &shader)
{
    glDetachShader(_id, shader._id);
}

void Program::link()
{
    glLinkProgram(_id);
}

void Program::enable()
{
    glUseProgram(_id);
}

void Program::disable()
{
    glUseProgram(_emptyId);
}

std::string Program::info()
{
    int length = 0;
    int charsWritten  = 0;
    std::string info;

    glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &length);
    info.reserve(length);

    if (length > 0)
        glGetProgramInfoLog(_id, length, &charsWritten, &info[0]);

    return info;
}

}
