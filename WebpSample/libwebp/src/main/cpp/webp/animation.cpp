//
// Created by Billy Phan on 6/16/2018.
//
#include "animation.h"
#include "example_util.c"
#include "webpmux.c"

#define NUM_OF_ARGUMENT 3

Annimation::Annimation() {

}

void Annimation::addFrame(const char *path, int duration) {
    mPaths.push_back(string(path));
    mDurations.push_back(duration);
}

/**
 * webpmux -frame pic1.jpg +300 -frame pic2.jpg +300 -o file.webp
 * @return save success or not
 */
bool Annimation::saveToFile(const char *path) {
    int numOfFrame = (int) mPaths.size();
    int size = numOfFrame * NUM_OF_ARGUMENT + 2;
    const char **args = new const char *[size];
    int j = 0;
    for (int i = 0; i < numOfFrame; i++) {
        args[j++] = "-frame";
        args[j++] = mPaths[i].c_str();
        log(args[j-1]);
        string duration = string("+") + to_string(mDurations[i]);
        args[j++] = duration.c_str();
    }
    args[j++] = "-o";
    args[j] = path;
    log(args[j]);

    WebPMuxConfig config;
    int ok = InitializeConfig(size, args, &config);
    if (ok) {
        ok = Process(&config);
    } else {
        log("Error initial config");
    }
    DeleteConfig(&config);
    return ok != 0;
}

