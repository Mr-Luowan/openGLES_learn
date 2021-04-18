package com.example.opengldemo.widget;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import com.example.opengldemo.render.MyGLRender;
import com.example.opengldemo.render.MyNativeRender;

/**
 * @author: pengfei
 * Date: 2021/4/17
 * Time: 16:31
 * Description: GLSurfaceView
 */
public class MyGLSurfaceView extends GLSurfaceView {

    public MyGLSurfaceView(Context context) {
        this(context, null);
    }

    public MyGLSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        setEGLContextClientVersion(3);
        MyNativeRender nativeRender = new MyNativeRender();
        MyGLRender GLRender = new MyGLRender(nativeRender);
        setRenderer(GLRender);
        setRenderMode(RENDERMODE_CONTINUOUSLY);
    }
}
