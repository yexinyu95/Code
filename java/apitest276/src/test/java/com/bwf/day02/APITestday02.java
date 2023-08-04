package com.bwf.day02;

import com.alibaba.fastjson.JSONObject;
import com.alibaba.fastjson.JSONPath;
import org.apache.http.HttpEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.utils.URIBuilder;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.testng.annotations.Test;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

public class APITestday02 {

    @Test
    public void TestDayTwo() throws IOException, URISyntaxException {
        //创建HTTP Client
        CloseableHttpClient client = HttpClients.createDefault();
        //https://api.weixin.qq.com/cgi-bin/get_api_domain_ip?access_token=ACCESS_TOKEN

        String token = AccessToken.getToken();
        HttpGet getTwo = new HttpGet("https://api.weixin.qq.com/cgi-bin/get_api_domain_ip?access_token=" + token);
        CloseableHttpResponse ResponseTwo = client.execute(getTwo);
        HttpEntity entityTwo = ResponseTwo.getEntity();
        String contentTwo = EntityUtils.toString(entityTwo);
        System.out.println(contentTwo);


    }

    @Test
    public static void xzpd() throws IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        String uri = "http://apis.juhe.cn/xzpd/query";

        HttpPost post = new HttpPost(uri);

        post.setHeader("Content-Type", "application/x-www-form-urlencoded");
        //post.setHeader("Content-Type", "application/json");

        String paramA = "men=白羊";
        String paramB = "women=白羊";
        String paramC = "key=123";

        String payload = paramA + "&" + paramB + "&" + paramC;
        //因为urlencode不支持中文,所以需要在构造Entity的时候附加一个字符集参数"UTF-8",
        StringEntity entity = new StringEntity(payload, "UTF-8");

        post.setEntity(entity);

        CloseableHttpResponse response = client.execute(post);

        String reponseText = EntityUtils.toString(response.getEntity());

        System.out.println(reponseText);

    }

    public static String reCAPTCHA() throws IOException {

        CloseableHttpClient client = HttpClients.createDefault();

        String uriRe = "http://172.31.15.79:9023/prod-api/captchaImage";
        HttpGet get = new HttpGet(uriRe);

        CloseableHttpResponse response = client.execute(get);

        String responseText = EntityUtils.toString(response.getEntity());
        //System.out.println(responseText);

        return JSONPath.eval(responseText, "$.uuid").toString();
        //uuid对应的为验证码图片在数据库中的id值,

    }

    @Test
    public static String LoginToken() throws IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        String uri = "http://172.31.15.79:9023/prod-api/login";

        HttpPost post = new HttpPost(uri);

        post.setHeader("Content-Type", "application/json;charset=utf-8");
        //post.setHeader("Content-Type", "application/json");
        String uuid = reCAPTCHA();

        String payload = "{\"username\":\"admin\",\"password\":\"admin123\",\"code\":\"51testing\",\"uuid\":\""
                + uuid
                + "\"}";

        StringEntity entity = new StringEntity(payload);

        post.setEntity(entity);
        CloseableHttpResponse response = client.execute(post);

        String responseText = EntityUtils.toString(response.getEntity());
        //System.out.println(responseText);
        //Assert.assertTrue(responseText.contains("success"));
        String token = JSONPath.eval(responseText, "$.token").toString();
        //System.out.println(token);
        return token;

    }

    @Test
    public static void SearchTest() throws IOException, URISyntaxException {
        CloseableHttpClient client = HttpClients.createDefault();
        //"http://172.31.15.79:9023/prod-api/baseconfig/House?currentPage=1&pageSize=20&sort=desc&sidx=&state=empty"
        URI uri  = new URIBuilder()
                .setScheme("http")
                .setHost("172.31.15.79:9023")
                .setPath("/prod-api/baseconfig/House")
                .setParameter("currentPage", "1")
                .setParameter("pageSize", "20")
                .setParameter("sort", "desc")
                .setParameter("sidx", "")
                .setParameter("state", "empty")
                .build();

        HttpGet get = new HttpGet(uri);
        get.setHeader("Authorization", "Bearer " + LoginToken());

        CloseableHttpResponse response = client.execute(get);
        String responseText = EntityUtils.toString(response.getEntity());
        JSONObject json = JSONObject.parseObject(responseText);


        //System.out.println(responseText);
        String str = JSONPath.eval(responseText, "$.data.list").toString();
        str = str.replace("[", "");
        str = str.replace("]", "");
        str = str.replace("},{", "}\n{");

        System.out.println(str);


    }

}
