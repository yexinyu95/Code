package com.bwf.day05;

import com.alibaba.fastjson.JSONPath;

import java.io.IOException;

public class Login {
    public static void main(String[] args) throws IOException {
        System.out.println(getToken());
    }

    public static String getUUID() throws IOException {
        String path = "/captchaImage";
        String responseText = HttpUtils.doGet(path);
        String uuid = JSONPath.eval(responseText, "$.uuid").toString();

        return uuid;

    }


    public static String getToken() throws IOException {
        String path = "/login";
        String payload = "{\"username\":\"admin\",\"password\":\"admin123\",\"code\":\"51testing\",\"uuid\":\"" +
                getUUID() +
                "\"}";

        String responseText = HttpUtils.doPost(path, payload);
        String token = JSONPath.eval(responseText, "$.token").toString();

        return token;


    }


}
