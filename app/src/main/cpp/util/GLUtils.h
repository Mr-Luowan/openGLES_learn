//
// Created by Mr_Lee on 2021/4/18.
//

#ifndef OPENGLDEMO_GLUTILS_H
#define OPENGLDEMO_GLUTILS_H

#include <GLES3/gl3.h>
#include <string>
#include "../LogUtils.h"

class GLUtils {
public:
    static GLuint loadShader(GLenum shaderType, const char *pSource);

    static GLuint createProgram(const char *pVertexShaderSource, const char *pFragShaderSource,
                                GLuint &vertexShaderHandle, GLuint &fragShaderHandle);

    static GLuint createProgram(const char *pVertexShaderSource, const char *pFragShaderSource);

    static GLuint
    createProgramWithFeedBack(const char *pVertexShaderSource, const char *pFragShaderSource,
                              GLuint &vertexShaderHandle, GLuint &fragShaderHandle,
                              GLchar **varying, int varyingCount);

    static void deleteProgram(GLuint &program);

    static void checkGLError(const char *pGLOperation);

    static void setBool(GLuint programId, const std::string &name, bool value) {
        glUniform1i(glGetUniformLocation(programId, name.c_str()), (int) value);
    }

    static void setInt(GLuint programId, const std::string &name, int value) {
        glUniform1i(glGetUniformLocation(programId, name.c_str()), value);
    }

    static void setFloat(GLuint programId, const std::string &name, float value) {
        glUniform1f(glGetUniformLocation(programId, name.c_str()), value);
    }

    static void setVec2(GLuint programId, const std::string &name, float x, float y) {
        glUniform2f(glGetUniformLocation(programId, name.c_str()), x, y);
    }

    static void setVec3(GLuint programId, const std::string &name, float x, float y, float z) {
        glUniform3f(glGetUniformLocation(programId, name.c_str()), x, y, z);
    }

    static void setVec4(GLuint programId, const std::string &name, float x, float y, float z, float w) {
        glUniform4f(glGetUniformLocation(programId, name.c_str()), x, y, z, w);
    }

};


#endif //OPENGLDEMO_GLUTILS_H
