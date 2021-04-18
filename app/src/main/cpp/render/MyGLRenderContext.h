//
// Created by Mr_Lee on 2021/4/17.
//

#ifndef OPENGLDEMO_MYGLRENDERCONTEXT_H
#define OPENGLDEMO_MYGLRENDERCONTEXT_H
#include <GLES3/gl3.h>
#include <TriangleSample.h>

class MyGLRenderContext {
    MyGLRenderContext();
    ~MyGLRenderContext();

public:
    void SetImageData(int format, int width, int height, uint8_t *pData);
    void OnSurfaceCreated();
    void OnSurfaceChanged(int width, int height);
    void OnDrawFrame();
    static MyGLRenderContext *GetInstance();
    static void DestroyInstance();

private:
    static MyGLRenderContext *m_pContext;
    TriangleSample *mSample;
};


#endif //OPENGLDEMO_MYGLRENDERCONTEXT_H
