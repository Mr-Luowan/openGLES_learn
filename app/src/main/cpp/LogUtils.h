//
// Created by Mr_Lee on 2021/4/17.
//

#ifndef OPENGLDEMO_LOGUTILS_H
#define OPENGLDEMO_LOGUTILS_H

#include <android/log.h>
#define  LOG_TAG "C layer TAG ==>"
#define  LOG_D(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

#endif //OPENGLDEMO_LOGUTILS_H
