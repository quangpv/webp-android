cmake_minimum_required(VERSION 3.4.1)

add_definitions( # Define Flags Here
                 -Wall -DANDROID -DHAVE_MALLOC_H
                 -DHAVE_PTHREAD -DWEBP_USE_THREAD
                 -fvisibility=hidden
                 -finline-functions -ffast-math
                 -ffunction-sections -fdata-sections )

include_directories( # Define Include Dirs
                     ${ANDROID_NDK}/sources/android/cpufeatures
                     cpp cpp/src cpp/examples cpp/imageio )

####################################################################################################
# Group all file .c to package
file( GLOB dec_srcs
      "cpp/src/dec/alpha_dec.c"
      "cpp/src/dec/buffer_dec.c"
      "cpp/src/dec/frame_dec.c"
      "cpp/src/dec/idec_dec.c"
      "cpp/src/dec/io_dec.c"
      "cpp/src/dec/quant_dec.c"
      "cpp/src/dec/tree_dec.c"
      "cpp/src/dec/vp8_dec.c"
      "cpp/src/dec/vp8l_dec.c"
      "cpp/src/dec/webp_dec.c" )

file( GLOB demux_srcs
      "cpp/src/demux/anim_decode.c"
      "cpp/src/demux/demux.c" )

file( GLOB dsp_dec_srcs
      "cpp/src/dsp/alpha_processing.c"
      "cpp/src/dsp/alpha_processing_mips_dsp_r2.c"
      "cpp/src/dsp/alpha_processing_neon.c"
      "cpp/src/dsp/alpha_processing_sse2.c"
      "cpp/src/dsp/alpha_processing_sse41.c"
      "cpp/src/dsp/argb.c"
      "cpp/src/dsp/argb_mips_dsp_r2.c"
      "cpp/src/dsp/argb_sse2.c"
      "cpp/src/dsp/cpu.c"
      "cpp/src/dsp/dec.c"
      "cpp/src/dsp/dec_clip_tables.c"
      "cpp/src/dsp/dec_mips32.c"
      "cpp/src/dsp/dec_mips_dsp_r2.c"
      "cpp/src/dsp/dec_msa.c"
      "cpp/src/dsp/dec_neon.c"
      "cpp/src/dsp/dec_sse2.c"
      "cpp/src/dsp/dec_sse41.c"
      "cpp/src/dsp/filters.c"
      "cpp/src/dsp/filters_mips_dsp_r2.c"
      "cpp/src/dsp/filters_msa.c"
      "cpp/src/dsp/filters_neon.c"
      "cpp/src/dsp/filters_sse2.c"
      "cpp/src/dsp/lossless.c"
      "cpp/src/dsp/lossless_mips_dsp_r2.c"
      "cpp/src/dsp/lossless_msa.c"
      "cpp/src/dsp/lossless_neon.c"
      "cpp/src/dsp/lossless_sse2.c"
      "cpp/src/dsp/rescaler.c"
      "cpp/src/dsp/rescaler_mips32.c"
      "cpp/src/dsp/rescaler_mips_dsp_r2.c"
      "cpp/src/dsp/rescaler_msa.c"
      "cpp/src/dsp/rescaler_neon.c"
      "cpp/src/dsp/rescaler_sse2.c"
      "cpp/src/dsp/upsampling.c"
      "cpp/src/dsp/upsampling_mips_dsp_r2.c"
      "cpp/src/dsp/upsampling_msa.c"
      "cpp/src/dsp/upsampling_neon.c"
      "cpp/src/dsp/upsampling_sse2.c"
      "cpp/src/dsp/yuv.c"
      "cpp/src/dsp/yuv_mips32.c"
      "cpp/src/dsp/yuv_mips_dsp_r2.c"
      "cpp/src/dsp/yuv_neon.c"
      "cpp/src/dsp/yuv_sse2.c" )

file( GLOB dsp_enc_srcs
      "cpp/src/dsp/cost.c"
      "cpp/src/dsp/cost_mips32.c"
      "cpp/src/dsp/cost_mips_dsp_r2.c"
      "cpp/src/dsp/cost_sse2.c"
      "cpp/src/dsp/enc.c"
      "cpp/src/dsp/enc_avx2.c"
      "cpp/src/dsp/enc_mips32.c"
      "cpp/src/dsp/enc_mips_dsp_r2.c"
      "cpp/src/dsp/enc_msa.c"
      "cpp/src/dsp/enc_neon.c"
      "cpp/src/dsp/enc_sse2.c"
      "cpp/src/dsp/enc_sse41.c"
      "cpp/src/dsp/lossless_enc.c"
      "cpp/src/dsp/lossless_enc_mips32.c"
      "cpp/src/dsp/lossless_enc_mips_dsp_r2.c"
      "cpp/src/dsp/lossless_enc_msa.c"
      "cpp/src/dsp/lossless_enc_neon.c"
      "cpp/src/dsp/lossless_enc_sse2.c"
      "cpp/src/dsp/lossless_enc_sse41.c"
      "cpp/src/dsp/ssim.c"
      "cpp/src/dsp/ssim_sse2.c" )

file( GLOB enc_srcs
      "cpp/src/enc/alpha_enc.c"
      "cpp/src/enc/analysis_enc.c"
      "cpp/src/enc/backward_references_enc.c"
      "cpp/src/enc/config_enc.c"
      "cpp/src/enc/cost_enc.c"
      "cpp/src/enc/delta_palettization_enc.c"
      "cpp/src/enc/filter_enc.c"
      "cpp/src/enc/frame_enc.c"
      "cpp/src/enc/histogram_enc.c"
      "cpp/src/enc/iterator_enc.c"
      "cpp/src/enc/near_lossless_enc.c"
      "cpp/src/enc/picture_enc.c"
      "cpp/src/enc/picture_csp_enc.c"
      "cpp/src/enc/picture_psnr_enc.c"
      "cpp/src/enc/picture_rescale_enc.c"
      "cpp/src/enc/picture_tools_enc.c"
      "cpp/src/enc/predictor_enc.c"
      "cpp/src/enc/quant_enc.c"
      "cpp/src/enc/syntax_enc.c"
      "cpp/src/enc/token_enc.c"
      "cpp/src/enc/tree_enc.c"
      "cpp/src/enc/vp8l_enc.c"
      "cpp/src/enc/webp_enc.c" )

file( GLOB mux_srcs
      "cpp/src/mux/anim_encode.c"
      "cpp/src/mux/muxedit.c"
      "cpp/src/mux/muxinternal.c"
      "cpp/src/mux/muxread.c" )

file( GLOB utils_dec_srcs
      "cpp/src/utils/bit_reader_utils.c"
      "cpp/src/utils/color_cache_utils.c"
      "cpp/src/utils/filters_utils.c"
      "cpp/src/utils/huffman_utils.c"
      "cpp/src/utils/quant_levels_dec_utils.c"
      "cpp/src/utils/random_utils.c"
      "cpp/src/utils/rescaler_utils.c"
      "cpp/src/utils/thread_utils.c"
      "cpp/src/utils/utils.c" )

file( GLOB utils_enc_srcs
      "cpp/src/utils/bit_writer_utils.c"
      "cpp/src/utils/huffman_encode_utils.c"
      "cpp/src/utils/quant_levels_utils.c" )

file( GLOB jni_srcs
	  "cpp/swig/libwebp_java_wrap.c"
      "src/main/cpp/webp/*.cpp"
      "src/main/cpp/*.cpp" )

####################################################################################################

add_library( # Sets the name of the library.
             lib-webp

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             ${dec_srcs} ${dsp_dec_srcs} ${utils_dec_srcs}
             ${dsp_enc_srcs} ${enc_srcs} ${utils_enc_srcs}
             ${mux_srcs}
             ${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c
             ${jni_srcs} )


target_link_libraries( # Specifies the target library.
                       lib-webp

                       # Links the target library to the log library
                       # included in the NDK.
                       log jnigraphics z
                       EGL GLESv2 android )