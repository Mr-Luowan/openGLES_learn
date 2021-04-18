package com.example.opengldemo.render;

import android.opengl.GLSurfaceView;
import android.util.Log;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * @author: pengfei
 * Date: 2021/4/17
 * Time: 16:32
 * Description: 渲染器
 */
public class MyGLRender implements GLSurfaceView.Renderer {
    private static final String TAG = "MyGLRender";
    private MyNativeRender mNativeRender;

    public MyGLRender(MyNativeRender nativeRender) {
        mNativeRender = nativeRender;
    }

    public void init() {
        mNativeRender.native_OnInit();
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        Log.d(TAG, "onSurfaceCreated() called with: gl = [" + gl + "], config = [" + config + "])");
        mNativeRender.native_OnSurfaceCreated();

    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        Log.d(TAG, "onSurfaceChanged(): called with: gl = [" + gl + "]" + "width ==>:" + width + " height  ==> " + height);
        mNativeRender.native_OnSurfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        mNativeRender.native_OnDrawFrame();
    }
}
