package com.example.shallybanh.whatsthewifi;

/**
 * Created by shallybanh on 2018-09-15.
 */

import android.content.UriMatcher;
import android.net.Uri;
import android.os.Bundle;

public class DeepLinkHandler {

    private static final String KEY_LINK = "link";
    private static final String KEY_ID = "id";
    private static final String AUTHORITY = "*";
    private static final String PATH_ID = "/*";

    private final UriMatcher mUriMatcher;

    public DeepLinkHandler() {
        mUriMatcher = new UriMatcher(UriMatcher.NO_MATCH);

    }

    public Bundle buildBundle(Uri uri) {
        int code = mUriMatcher.match(uri);

        Bundle bundle = new Bundle();
        bundle.putInt(KEY_LINK, code);

        return bundle;
    }
}
