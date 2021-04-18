//
// Created by Mr_Lee on 2021/4/18.
//

#include "TriangleSample.h"
#include "GLUtils.h"

TriangleSample::TriangleSample() {
    init();
}

TriangleSample::~TriangleSample() {
    if (m_ProgramObj) {
        glDeleteProgram(m_ProgramObj);
    }
}


void TriangleSample::init() {
    char vShaderStr[] =
            "#version 300 es                            \n"
            "layout(location = 0) in vec4 vPosition;    \n"
            "void main()                                \n"
            "{                                          \n"
            "   gl_Position = vPosition;                \n"
            "}                                          \n";

    char fShaderStr[] =
            "#version 300 es                           \n"
            "precision mediump float;                  \n"
            "out vec4 fragColor;                       \n"
            "void main()                               \n"
            "{                                         \n"
            "    fragColor = vec4(1.0,0.0,0.0,1.0);    \n"
            " }                                        \n";
    m_ProgramObj = GLUtils::createProgram(vShaderStr, fShaderStr);
}

void TriangleSample::draw() {
    GLfloat vVertices[] = {
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f
    };

    if (m_ProgramObj == 0) {
        LOG_D("程序%d初始化失败", m_ProgramObj);
        return;
    }
    LOG_D("使用程序%d成功", m_ProgramObj);
    glUseProgram(m_ProgramObj);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
