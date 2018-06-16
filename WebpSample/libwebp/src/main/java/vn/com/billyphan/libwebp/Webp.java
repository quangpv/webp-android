package vn.com.billyphan.libwebp;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Billy Phan on 6/16/2018.
 */

public class Webp {
    static {
        System.loadLibrary("lib-webp");
    }

    private static native boolean buildAnimation(String[] paths, int[] durations, String output);

    private static native byte[] convertToWebp(Bitmap bitmap);

    private Bitmap mBitmap;

    private Webp(Bitmap bitmap) {
        mBitmap = bitmap;
    }

    public static Webp from(Bitmap bitmap) {
        return new Webp(bitmap);
    }

    public static Webp from(String path) {
        BitmapFactory.Options options = new BitmapFactory.Options();
        options.inPreferredConfig = Bitmap.Config.ARGB_8888;
        return new Webp(BitmapFactory.decodeFile(path, options));
    }

    public void saveTo(String path) {
        byte[] bytes = convertToWebp(mBitmap);
        writeToFile(bytes, path);
    }

    private void writeToFile(byte[] bytes, String path) {
        try {
            FileOutputStream fileOutputStream = new FileOutputStream(path);
            fileOutputStream.write(bytes);
            fileOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static Animation newAnimation() {
        return new Animation();
    }

    public static class Animation {

        private List<String> mPaths;
        private List<Integer> mDurations;

        public Animation() {
            mPaths = new ArrayList<>();
            mDurations = new ArrayList<>();
        }

        public Animation frame(String path, int duration) {
            String webpPath = path.replace(getFileExtension(path), "webp");
            from(path).saveTo(webpPath);
            mPaths.add(webpPath);
            mDurations.add(duration);
            return this;
        }

        public boolean saveTo(String path) {
            int[] durations = new int[mDurations.size()];
            for (int i = 0; i < mDurations.size(); i++) {
                durations[i] = mDurations.get(i);
            }
            boolean res = buildAnimation(mPaths.toArray(new String[mPaths.size()]), durations, path);
            if (res) removeAllTmpFiles();
            return res;
        }

        private void removeAllTmpFiles() {
            for (String path : mPaths) {
                removeFile(path);
            }
        }

        private void removeFile(String path) {
            File file = new File(path);
            if (file.exists()) file.delete();
        }

        private static String getFileExtension(String fileName) {
            int lastIndexOfDotted = fileName.lastIndexOf(".");
            if (lastIndexOfDotted > 0)
                return fileName.substring(lastIndexOfDotted + 1);
            else return "";
        }
    }
}
