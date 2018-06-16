//
// Created by Billy Phan on 6/16/2018.
//

#ifndef WEBPSAMPLE_BITMAP_H_H
#define WEBPSAMPLE_BITMAP_H_H

#include <jni.h>
#include <android/bitmap.h>

class Bitmap {
private:
    uint8_t* mPixels;
    AndroidBitmapInfo mInfo;
    jobject mJavaBitmap;
    JNIEnv *mEnv;

    bool open();
    void close();

public:
    Bitmap(JNIEnv* env,jobject bitmap);

    jbyteArray toWebp();
};

#endif //WEBPSAMPLE_BITMAP_H_H
