package com.example.opengldemo.render;

/**
 * @author: pengfei
 * Date: 2021/4/17
 * Time: 16:33
 * Description:
 */
public class MyNativeRender {
    static {
        System.loadLibrary("native-lib");
    }
    public native void native_OnInit();
    public native void native_OnUnInit();
    public native void native_SetImageData(int format, int width, int height, byte[] bytes);
    public native void native_OnSurfaceCreated();
    public native void native_OnSurfaceChanged(int width, int height);
    public native void native_OnDrawFrame() ;
}
