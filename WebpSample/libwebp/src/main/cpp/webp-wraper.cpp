//
// Created by Billy Phan on 6/16/2018.
//

#include "jni.h"
#include "webp/animation.h"
#include "webp/bitmap.h"

extern "C" JNIEXPORT JNICALL
jboolean Java_vn_com_billyphan_libwebp_Webp_buildAnimation(JNIEnv *env, jclass type,
                                                              jobjectArray pathOfImages,
                                                              jintArray durationOfImages,
                                                              jstring pathOutput) {
    Annimation annimation = Annimation();
    int count = env->GetArrayLength(pathOfImages);
    const char *output = env->GetStringUTFChars(pathOutput, 0);
    jint *durations = env->GetIntArrayElements(durationOfImages, 0);

    for (int i = 0; i < count; i++) {
        jstring path = (jstring) env->GetObjectArrayElement(pathOfImages, i);
        jint duration = durations[i];
        const char *pathChars = env->GetStringUTFChars(path, 0);
        annimation.addFrame(pathChars, duration);
        env->ReleaseStringUTFChars(path, pathChars);
    }
    bool res = annimation.saveToFile(output);
    env->ReleaseStringUTFChars(pathOutput, output);
    env->ReleaseIntArrayElements(durationOfImages, durations, 0);
    return (jboolean) res;
}

extern "C" JNIEXPORT JNICALL
jbyteArray Java_vn_com_billyphan_libwebp_Webp_convertToWebp(JNIEnv *env, jclass type,
                                                               jobject bitmap) {
    Bitmap bitmapWraper = Bitmap(env, bitmap);
    return bitmapWraper.toWebp();
}



