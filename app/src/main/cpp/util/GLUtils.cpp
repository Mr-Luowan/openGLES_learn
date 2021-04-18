//
// Created by Mr_Lee on 2021/4/18.
//

#include "GLUtils.h"

GLuint GLUtils::loadShader(GLenum shaderType, const char *pSource) {
    GLuint shader = 0;
    shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char *buf = (char *) malloc((size_t) infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    LOG_D("GLUtils::LoadShader Could not compile shader %d:\n%s\n", shaderType, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint GLUtils::createProgram(const char *pVertexShaderSource, const char *pFragShaderSource,
                              GLuint &vertexShaderHandle, GLuint &fragShaderHandle) {
    GLuint program = 0;
    vertexShaderHandle = loadShader(GL_VERTEX_SHADER, pVertexShaderSource);
    if (!vertexShaderHandle) {
        return program;
    }
    fragShaderHandle = loadShader(GL_FRAGMENT_SHADER, pFragShaderSource);
    if (!fragShaderHandle) {
        return program;
    }
    program = glCreateProgram();
    if (!program) {
        return program;
    }
    glAttachShader(program, vertexShaderHandle);
    checkGLError("glAttachShader");
    glAttachShader(program, fragShaderHandle);
    checkGLError("glAttachShader");
    glLinkProgram(program);
    GLint  linkStatus = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

    glDetachShader(program, vertexShaderHandle);
    glDeleteShader(vertexShaderHandle);
    vertexShaderHandle = 0;
    glDetachShader(program, fragShaderHandle);
    glDeleteShader(fragShaderHandle);
    fragShaderHandle = 0;
    if (linkStatus != GL_TRUE) {
        //todo link程序出错 删除程序
    }
    LOG_D("连接程序成功 程序ID%d", program);
    return program;
}

GLuint GLUtils::createProgram(const char *pVertexShaderSource, const char *pFragShaderSource) {
    GLuint vertexShaderHandle, fragShaderHandle;
    return createProgram(pVertexShaderSource, pFragShaderSource, vertexShaderHandle, fragShaderHandle);
}

GLuint
GLUtils::createProgramWithFeedBack(const char *pVertexShaderSource, const char *pFragShaderSource,
                                   GLuint &vertexShaderHandle, GLuint &fragShaderHandle,
                                   GLchar **varying, int varyingCount) {
    return 0;
}

void GLUtils::deleteProgram(GLuint &program) {
    if (program) {
        glUseProgram(0);
        glDeleteProgram(program);
        program = 0;
    }
}

void GLUtils::checkGLError(const char *pGLOperation) {
    for (GLint error = glGetError(); error; error = glGetError()) {
        LOG_D("GLUtils::CheckGLError GL Operation %s() glError (0x%x)\n", pGLOperation, error);
    }
}

