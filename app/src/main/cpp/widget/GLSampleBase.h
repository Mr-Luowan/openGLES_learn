//
// Created by Mr_Lee on 2021/4/18.
//

#ifndef OPENGLDEMO_GLSAMPLEBASE_H
#define OPENGLDEMO_GLSAMPLEBASE_H
#include <GLES3/gl3.h>
#include "../LogUtils.h"
class GLSampleBase {
public:
    GLSampleBase() {
        m_ProgramObj = 0;
        m_VertexShader = 0;
        m_FragmentShader = 0;

        m_SurfaceWidth = 0;
        m_SurfaceHeight = 0;
    }
    virtual ~GLSampleBase() {}


protected:
    GLuint m_ProgramObj;
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    int m_SurfaceWidth;
    int m_SurfaceHeight;
};
#endif //OPENGLDEMO_GLSAMPLEBASE_H
