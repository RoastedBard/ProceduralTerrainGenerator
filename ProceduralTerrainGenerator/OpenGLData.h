#pragma once
#include <GL\glew.h>

struct OGLData
{
    GLuint vertexArrayObject;
    GLuint vertexBufferObject;
    GLuint elementBufferObject;
    GLuint colorBufferObject;
    GLuint shaderProgramId;
    GLuint mvpId;
};