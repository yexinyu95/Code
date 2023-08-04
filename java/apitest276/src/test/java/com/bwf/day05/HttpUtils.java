package com.bwf.day05;

import org.apache.http.NameValuePair;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

import java.io.IOException;
import java.util.List;

public class HttpUtils {
    static String host = "http://172.31.15.79:9023/prod-api";

    public static String doGet(String path, List<NameValuePair> headers) throws IOException {
        CloseableHttpClient client = HttpClients.createDefault();
        String uri = host + path;
        HttpGet get = new HttpGet(uri);

        if (headers != null) {
            for (NameValuePair header : headers) {
                get.setHeader(header.getName(), header.getValue());
            }
        }

        CloseableHttpResponse response = client.execute(get);

        String responseText = EntityUtils.toString(response.getEntity());

        return responseText;
    }

    public static String doGet(String path) throws IOException {
        CloseableHttpClient client = HttpClients.createDefault();
        String uri = host + path;
        HttpGet get = new HttpGet(uri);

        CloseableHttpResponse response = client.execute(get);

        return EntityUtils.toString(response.getEntity());
    }

/*
    //代码较复杂时, 也可以写为以下形式, 但是应注意null值可能导致空指针错误
    //需要在遍历List前先进行非空判断
    public static String doGet(String path) throws IOException {
        return doGet(path, null);
    }
*/


    public static String doPost(String path, List<NameValuePair> headers, String payload) throws IOException {
        CloseableHttpClient client = HttpClients.createDefault();
        String uri = host + path;
        HttpPost post = new HttpPost(uri);

        post.setHeader("Content-Type", "application/json;charset=utf-8");
        if (headers != null) {
            for (NameValuePair header : headers) {
                post.setHeader(header.getName(), header.getValue());
            }
        }

        StringEntity entity = new StringEntity(payload, "UTF-8");
        post.setEntity(entity);

        CloseableHttpResponse response = client.execute(post);

        String responseText = EntityUtils.toString(response.getEntity());

        return responseText;
    }

    public static String doPost(String path, String payload) throws IOException {
        return doPost(path, null, payload);
    }

}
