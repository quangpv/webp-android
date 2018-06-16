//
// Created by Billy Phan on 6/16/2018.
//

#ifndef WEBPSAMPLE_TEST_H
#define WEBPSAMPLE_TEST_H

#include <android/bitmap.h>
#include <string>
#include <vector>
#include <android/log.h>

#define log(text) __android_log_write(ANDROID_LOG_ERROR, "ERROR_TAG", text);

using namespace std;

class Annimation {
private:
    vector<string> mPaths;
    vector<int> mDurations;
public:
    Annimation();

    void addFrame(const char *path, int duration);

    bool saveToFile(const char *path);
};

#endif //WEBPSAMPLE_TEST_H
