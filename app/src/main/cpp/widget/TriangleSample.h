//
// Created by Mr_Lee on 2021/4/18.
//

#ifndef OPENGLDEMO_TRIANGLESAMPLE_H
#define OPENGLDEMO_TRIANGLESAMPLE_H


#include <GLES3/gl3.h>

class TriangleSample {
public:
    TriangleSample();
    ~TriangleSample();
    void init();
    void draw();
protected:
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    GLuint m_ProgramObj;
    int m_SurfaceWidth;
    int m_SurfaceHeight;
};


#endif //OPENGLDEMO_TRIANGLESAMPLE_H
