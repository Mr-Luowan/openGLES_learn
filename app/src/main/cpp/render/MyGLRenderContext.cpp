//
// Created by Mr_Lee on 2021/4/17.
//

#include "MyGLRenderContext.h"
#include "../LogUtils.h"

MyGLRenderContext *MyGLRenderContext::m_pContext = nullptr;

MyGLRenderContext::MyGLRenderContext() {
    LOG_D("构造方法");
    mSample = new TriangleSample();
}

MyGLRenderContext::~MyGLRenderContext() {
    LOG_D("析构方法");
    if (mSample) {
        mSample = nullptr;
    }
}


MyGLRenderContext *MyGLRenderContext::GetInstance() {
    if (m_pContext == nullptr)
        m_pContext = new MyGLRenderContext();
    return m_pContext;
}

void MyGLRenderContext::DestroyInstance() {
    if (m_pContext) {
        delete m_pContext;
        m_pContext = nullptr;
    }
}

void MyGLRenderContext::OnSurfaceCreated() {
    LOG_D("设置背景颜色红色");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    LOG_D("设置背景颜色红色  完成");
}

void MyGLRenderContext::OnSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void MyGLRenderContext::OnDrawFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (!mSample) {
        mSample = new TriangleSample();
    }
    mSample->draw();
}

void MyGLRenderContext::SetImageData(int format, int width, int height, uint8_t *pData) {
    LOG_D("接收java层传递过来的数据");
}
