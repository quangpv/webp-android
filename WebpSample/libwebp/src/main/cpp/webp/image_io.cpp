//
// Created by Billy Phan on 6/16/2018.
//

#include <android/log.h>
#include <stdio.h>

#define fprintf(a, ...) __android_log_print(ANDROID_LOG_DEBUG, "DEBUG", __VA_ARGS__)

#include "image_dec.c"
#include "imageio_util.c"
#include "metadata.c"
#include "pnmdec.c"
#include "webpdec.c"
#include "image_enc.c"
#include "jpegdec.c"
#include "pngdec.c"
#include "tiffdec.c"
#include "wicdec.c"

