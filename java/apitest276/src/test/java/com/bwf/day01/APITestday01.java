package com.bwf.day01;

import com.alibaba.fastjson.JSONPath;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.utils.URIBuilder;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.testng.Assert;
import org.testng.annotations.Test;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;


public class APITestday01 {
    @Test
    public void testToken() throws URISyntaxException, IOException {
        //1.创建HttpClient
        CloseableHttpClient client = HttpClients.createDefault();

        //2.构建网址
        //https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid=APPID&secret=APPSECRET
        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.weixin.qq.com")
                //网址中省略了端口号, 所以代码中也可以省略端口号
                .setPath("/cgi-bin/token")
                .setParameter("grant_type", "client_credential")
                .setParameter("appid", "wx2e8bba430c75cbea")
                .setParameter("secret", "4e0f943703eabc627949bc4d5088c220")
                //遇到红色波浪线, 鼠标放在红线上, 选择添加异常到方法签名
                //网址存在固定结构, 如果最终构造得到的网址出错, 则会产生问题, 产生异常
                .build();

        //3.创建请求
        HttpGet get = new HttpGet(uri);

        //4.执行请求, 获取响应
        CloseableHttpResponse response = client.execute(get);


        //5.设置断言, 检查响应结果
        //5.1 打印状态行_期望结果: HTTP/1.1 200 OK
        System.out.println(response.getStatusLine());
        Assert.assertEquals(response.getStatusLine().getStatusCode(), 200);

        //5.2 响应消息头_期望结果: application/json; encoding=utf-8
        System.out.println(response.getFirstHeader("Content-Type"));
        Assert.assertTrue(response.getFirstHeader("Content-Type").toString().contains("json"));

        //5.3 响应消息体
        //第四步得到的响应信息为"CloseableHttpResponse"文件, 包含非常复杂的返回信息
        //可以通过getEntity方法将其主体转换为String类型
        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);


        //转换得到的responseText一般为json文件, 需要通过JSONPath取值
        //参数1为取值的json文件, 参数2为路径表达式(其中$表示全字符串); 最后还需要将返回值转换为String类型
        String expires_in = JSONPath.eval(responseText, "$.expires_in").toString();
        /*
        断言报错信息会体现在最终的测试用例中,
        如果测试用例很多, 手工检查的效率很低,
        断言可以帮助过滤它认为正确的测试用例, 因此手动检查断言报错的测试用例即可
         */





    }
}
