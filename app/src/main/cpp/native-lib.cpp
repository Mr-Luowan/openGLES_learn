#include <jni.h>
#include <string>
#include "render/MyGLRenderContext.h"
#include "LogUtils.h"


#define NATIVE_RENDER_CLASS_NAME "com/example/opengldemo/render/MyNativeRender"

#ifdef __cplusplus
extern "C"
#endif

JNIEXPORT void JNICALL native_Init(JNIEnv *env, jobject instance) {
    LOG_D("C层初始化");
    MyGLRenderContext::GetInstance();
}

JNIEXPORT void JNICALL native_OnUnInit(JNIEnv *env, jobject instance) {
    MyGLRenderContext::DestroyInstance();
}

JNIEXPORT void JNICALL native_SetImageData(JNIEnv *env, jobject instance,
        jint format, jint width, jint height, jbyteArray imageData) {
    //获取数组长度
    int len = env->GetArrayLength(imageData);
    uint8_t *buf = new uint8_t[len];
    //拷贝java数组数据
    env->GetByteArrayRegion(imageData,0, len, reinterpret_cast<jbyte*>(buf));
    MyGLRenderContext::GetInstance()->SetImageData(format, width, height, buf);
    delete buf;
    env->DeleteLocalRef(imageData);
}

JNIEXPORT void JNICALL native_OnSurfaceCreated(JNIEnv *env, jobject instance) {
    MyGLRenderContext::GetInstance()->OnSurfaceCreated();
}

JNIEXPORT void JNICALL native_OnSurfaceChanged(JNIEnv *env, jobject instance,
        jint width, jint height) {
    MyGLRenderContext::GetInstance()->OnSurfaceChanged(width, height);
}

JNIEXPORT void JNICALL native_OnDrawFrame(JNIEnv *env, jobject instance) {
    MyGLRenderContext::GetInstance()->OnDrawFrame();
}

static int RegisterNativeMethods(
        JNIEnv *env, const char *className, JNINativeMethod *methods, int methodNum
) {
    jclass clazz = env->FindClass(className);
    if (clazz == NULL)
    {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, methods, methodNum) < 0)
    {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

static JNINativeMethod g_RenderMethods[] = {
        {"native_SetImageData", "(III[B)V", (void *)(native_SetImageData)},
        {"native_OnInit", "()V", (void *)(native_Init)},
        {"native_OnUnInit", "()V", (void *)(native_OnUnInit)},
        {"native_OnSurfaceCreated", "()V", (void *)(native_OnSurfaceCreated)},
        {"native_OnSurfaceChanged", "(II)V", (void *)(native_OnSurfaceChanged)},
        {"native_OnDrawFrame", "()V", (void *)(native_OnDrawFrame)},
};

static void UnregisterNativeMethod(JNIEnv *env, const char *className) {
    jclass clazz = env->FindClass(className);
    if (clazz == NULL) {
        return;
    }
    if (env != NULL) {
        env->UnregisterNatives(clazz);
    }
}

extern "C" jint JNI_OnLoad(JavaVM *jvm, void  *p) {
    jint jniRet = JNI_ERR;
    JNIEnv *env = NULL;
    LOG_D("C层初始化 ==》JNI初始化开始");
    if (jvm->GetEnv((void **)(&env), JNI_VERSION_1_6) != JNI_OK) {
        LOG_D("C层初始化 ==》JNI初始化失败");
        return jniRet;
    }
    LOG_D("C层初始化 ==》JNI初始化成功");
    LOG_D("C层初始化 ==》注册方法开始");
    jint  regRet = RegisterNativeMethods(env, NATIVE_RENDER_CLASS_NAME,
            g_RenderMethods, sizeof(g_RenderMethods)/sizeof(g_RenderMethods[0]));
    LOG_D("C层初始化 ==》注册方法结束");
    if (regRet != JNI_TRUE) {
        LOG_D("C层初始化 ==》注册方法失败");
        return JNI_ERR;
    }
    LOG_D("C层初始化 ==》注册方法成功");
    return JNI_VERSION_1_6;
}

extern "C" void JNI_OnUnload(JavaVM *jvm, void *p) {
    JNIEnv *env = NULL;
    if (jvm->GetEnv((void **)(env), JNI_VERSION_1_6) != JNI_OK) {
        return;
    }
    UnregisterNativeMethod(env, NATIVE_RENDER_CLASS_NAME);
}