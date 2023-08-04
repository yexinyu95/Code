package com.bwf.day05;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.alibaba.fastjson.serializer.SerializerFeature;
import org.apache.http.NameValuePair;
import org.apache.http.message.BasicNameValuePair;
import org.testng.annotations.Test;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class SelectHouseTest {

    @Test
    public void testHouseQuery() throws IOException {
        String path = "/baseconfig/House?currentPage=1&pageSize=20&sort=desc&sidx=";
        List<NameValuePair> headers = new ArrayList<>();
        headers.add(new BasicNameValuePair("Authorization", "Bearer " + Login.getToken()));
        String responseText = HttpUtils.doGet(path, headers);

        JSONObject json = JSONObject.parseObject(responseText);
        String s = JSON.toJSONString(json, SerializerFeature.PrettyFormat);

        System.out.println(s);

    }
}
