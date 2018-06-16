package au.com.fccapital.webpsample;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import vn.com.billyphan.libwebp.Webp;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        Webp.from(Environment.getExternalStorageDirectory().getPath() + "/test.png")
//                .saveTo(Environment.getExternalStorageDirectory().getPath() + "/test.webp");
        Webp.newAnimation()
                .frame(getPathOfFile("bird-1.jpg"), 300)
                .frame(getPathOfFile("cat-2.jpg"), 300)
                .frame(getPathOfFile("chicken-3.jpg"), 300)
                .frame(getPathOfFile("cow-4.jpg"), 300)
                .saveTo(getPathOfFile("animal.webp"));
    }

    public String getPathOfFile(String fileName) {
        return Environment.getExternalStorageDirectory().getPath() + "/" + fileName;
    }
}