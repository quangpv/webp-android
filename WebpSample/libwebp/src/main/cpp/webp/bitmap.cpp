//
// Created by Billy Phan on 6/16/2018.
//

#include <android/bitmap.h>
#include <src/webp/encode.h>
#include "bitmap.h"

#define QUALITY_FACTOR 80

Bitmap::Bitmap(JNIEnv *env, jobject bitmap) {
    this->mEnv = env;
    this->mJavaBitmap = bitmap;
}

bool Bitmap::open() {
    if (AndroidBitmap_getInfo(mEnv, mJavaBitmap, &mInfo) < 0)
        return false;
    if (mInfo.format != ANDROID_BITMAP_FORMAT_RGBA_8888
        && mInfo.format != ANDROID_BITMAP_FORMAT_RGB_565)
        return false;
    return AndroidBitmap_lockPixels(mEnv, mJavaBitmap, (void **) &mPixels) >= 0;
}

void Bitmap::close() {
    AndroidBitmap_unlockPixels(mEnv, mJavaBitmap);
}

jbyteArray Bitmap::toWebp() {
    if (!open())return 0;
    int stride;
    size_t size;
    uint8_t *output = 0;

    if (mInfo.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
        stride = 4 * mInfo.width * sizeof(uint8_t);
        size = WebPEncodeRGBA(mPixels,
                              mInfo.width,
                              mInfo.height,
                              stride, QUALITY_FACTOR, &output);
    } else {
        stride = 2 * mInfo.width * sizeof(uint8_t);
        size = WebPEncodeRGB(mPixels,
                              mInfo.width,
                              mInfo.height,
                              stride, QUALITY_FACTOR, &output);
    }
    jbyteArray byteOfWebp = mEnv->NewByteArray((jsize) size);
    mEnv->SetByteArrayRegion(byteOfWebp, 0, (jsize) size, (const jbyte *) output);
    close();
    return byteOfWebp;
}



