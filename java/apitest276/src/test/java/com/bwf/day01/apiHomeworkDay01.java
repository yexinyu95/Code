package com.bwf.day01;

import org.apache.http.StatusLine;
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
import java.security.NoSuchAlgorithmException;

import static com.bwf.day01.GetSNCalculate.SN;

public class apiHomeworkDay01 {
/*
GET请求示例
https://api.map.baidu.com/place/v2/suggestion?query=天安门&region=北京&city_limit=true&output=json&ak=你的ak

可传入参数

参数名称,是否必须,默认值,格式,备注
q(query),是,无,上地、天安、中关、shanghai,输入建议关键字（支持拼音）
region,是,无,北京市、上海市等,无
city_limit,否,FALSE,"false"or"true",取值为"true"，仅返回region中指定城市检索结果
coord_type,否,3,坐标类型：1（WGS84ll即GPS经纬度）\2（GCJ02ll即国测局经纬度坐标）\3（BD09ll即百度经纬度坐标）\4（BD09mc即百度米制坐标）",可选参数，用于标注请求中「location」参数使用的坐标类型
ret_coordtype,否,无,gcj02ll,可选参数，添加后POI返回国测局经纬度坐标\若不传该参数，返回结果默认bd09ll（百度经纬度）
output,否,xml,json、xml,返回数据格式，可选json、xml两种
ak,是,无,E4805d16**********707cdc962045,开发者访问密钥
*/


    @Test
    //1.1 正常测试, 输入所有必填项
    //预期结果: 返回的信息中包含所查询的地名
    public void TestOneA() throws URISyntaxException, IOException, NoSuchAlgorithmException {
        CloseableHttpClient client = HttpClients.createDefault();

        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.map.baidu.com")
                .setPath("/place/v2/suggestion")
                .setParameter("query", "天安门")
                .setParameter("region", "北京")
                .setParameter("ak", "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k")
                .setParameter("sn", "a74e1be5704808de8fdf965740ae2a38")
                .build();

        String SNValue = SN("/place/v2/suggestion?","query","天安门","region","北京","ak","oaixlqaM1995LwdeZd3ZfBCaaseLAV7k");
        System.out.println(SNValue);

        HttpGet get = new HttpGet(uri);

        //get.addHeader("Accept", "application/json");

        CloseableHttpResponse response = client.execute(get);
        StatusLine status = response.getStatusLine();
        System.out.println(status);
        Assert.assertEquals(status.getStatusCode(), 200);

        String content_type = response.getFirstHeader("Content-Type").toString();
        System.out.println(content_type);
        //Assert.assertTrue(content_type.contains("xml"));

        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);
        Assert.assertTrue(responseText.contains("天安门"));

    }

    @Test
    //1.2 正常测试, 输入所有必填项和选填项
    //预期结果: 返回的信息中包含所查询的地名
    public void TestOneB() throws URISyntaxException, IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.map.baidu.com")
                .setPath("/place/v2/suggestion")
                .setParameter("query", "天安门")
                .setParameter("region", "北京市")
                .setParameter("city_limit", "true")
                .setParameter("coord_type", "2")
                .setParameter("ret_coordtype", "gcj02ll")
                .setParameter("ak", "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k")
                .setParameter("output", "json")
                .build();

        HttpGet get = new HttpGet(uri);

        CloseableHttpResponse response = client.execute(get);
        StatusLine status = response.getStatusLine();
        //System.out.println(status);
        Assert.assertEquals(status.getStatusCode(), 200);

        String content_type = response.getFirstHeader("Content-Type").toString();
        System.out.println(content_type);
        Assert.assertTrue(content_type.contains("json"));
        //测试失败, 输出结果类似json类型, 但是返回的标题头却显示为JavaScript类型, 原因未知

        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);
        Assert.assertTrue(responseText.contains("天安门"));

    }

    @Test
    //2.1 异常测试, 不输入必填项query, 其他输入正确
    //预期结果: 请求失败, 或返回的信息提示输入不合法
    public void TestTwoA() throws URISyntaxException, IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.map.baidu.com")
                .setPath("/place/v2/suggestion")
                //.setParameter("query", "天安门")
                .setParameter("region", "北京市")
                .setParameter("city_limit", "true")
                .setParameter("coord_type", "2")
                .setParameter("ret_coordtype", "gcj02ll")
                .setParameter("ak", "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k")
                .build();

        HttpGet get = new HttpGet(uri);

        CloseableHttpResponse response = client.execute(get);
        StatusLine status = response.getStatusLine();
        System.out.println(status);
        Assert.assertEquals(status.getStatusCode(), 200);

        String content_type = response.getFirstHeader("Content-Type").toString();
        System.out.println(content_type);
        Assert.assertTrue(content_type.contains("xml"));

        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);
        Assert.assertTrue(responseText.contains("Invalid"));

    }

    @Test
    //2.2 异常测试, 不输入必填项region, 其他输入正确
    //预期结果: 请求失败, 或返回的信息提示输入不合法
    public void TestTwoB() throws URISyntaxException, IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.map.baidu.com")
                .setPath("/place/v2/suggestion")
                .setParameter("query", "天安门")
                //.setParameter("region", "北京市")
                .setParameter("city_limit", "true")
                .setParameter("coord_type", "2")
                .setParameter("ret_coordtype", "gcj02ll")
                .setParameter("ak", "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k")
                .build();

        HttpGet get = new HttpGet(uri);

        CloseableHttpResponse response = client.execute(get);
        StatusLine status = response.getStatusLine();
        //System.out.println(status);
        Assert.assertEquals(status.getStatusCode(), 200);

        String content_type = response.getFirstHeader("Content-Type").toString();
        System.out.println(content_type);
        Assert.assertTrue(content_type.contains("xml"));

        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);
        Assert.assertTrue(responseText.contains("Invalid"));

    }

    @Test
    //2.3 异常测试, 不输入必填项ak, 其他输入正确
    //预期结果: 请求失败, 或返回的信息提示输入不合法
    public void TestTwoC() throws URISyntaxException, IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.map.baidu.com")
                .setPath("/place/v2/suggestion")
                .setParameter("query", "天安门")
                .setParameter("region", "北京市")
                .setParameter("city_limit", "true")
                .setParameter("coord_type", "2")
                .setParameter("ret_coordtype", "gcj02ll")
                //.setParameter("ak", "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k")
                .build();

        HttpGet get = new HttpGet(uri);

        CloseableHttpResponse response = client.execute(get);
        StatusLine status = response.getStatusLine();
        System.out.println(status);
        Assert.assertEquals(status.getStatusCode(), 200);

        String content_type = response.getFirstHeader("Content-Type").toString();
        System.out.println(content_type);
        //Assert.assertTrue(content_type.contains("xml"));

        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);
        Assert.assertTrue(responseText.contains("AK"));

    }

    @Test
    //2.4 异常测试, query输入非地名字符, 其他输入正确
    //预期结果: 请求失败, 或返回的信息提示输入不合法
    public void TestTwoD() throws URISyntaxException, IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.map.baidu.com")
                .setPath("/place/v2/suggestion")
                .setParameter("query", "$$")
                .setParameter("region", "北京市")
                .setParameter("city_limit", "true")
                .setParameter("coord_type", "2")
                .setParameter("ret_coordtype", "gcj02ll")
                .setParameter("ak", "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k")
                .build();

        HttpGet get = new HttpGet(uri);

        CloseableHttpResponse response = client.execute(get);
        StatusLine status = response.getStatusLine();
        System.out.println(status);
        Assert.assertEquals(status.getStatusCode(), 200);

        String content_type = response.getFirstHeader("Content-Type").toString();
        System.out.println(content_type);
        Assert.assertTrue(content_type.contains("xml"));

        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);
        Assert.assertTrue(responseText.contains("Failure"));

    }

    @Test
    //2.5 异常测试, city_limit输入其他字符串, 其他输入正确
    //预期结果: 请求失败, 或返回的信息提示输入不合法, 或参数修改为默认值
    public void TestTwoE() throws URISyntaxException, IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.map.baidu.com")
                .setPath("/place/v2/suggestion")
                .setParameter("query", "天安门")
                .setParameter("region", "北京市")
                .setParameter("city_limit", "A")
                .setParameter("coord_type", "2")
                .setParameter("ret_coordtype", "gcj02ll")
                .setParameter("ak", "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k")
                .build();

        HttpGet get = new HttpGet(uri);

        CloseableHttpResponse response = client.execute(get);
        StatusLine status = response.getStatusLine();
        System.out.println(status);
        Assert.assertEquals(status.getStatusCode(), 200);

        String content_type = response.getFirstHeader("Content-Type").toString();
        System.out.println(content_type);
        Assert.assertTrue(content_type.contains("xml"));

        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);
        //Assert.assertTrue(responseText.contains("Failure"));

    }

    @Test
    //2.6 异常测试, ret_coordtype输入非法取值, 其他输入正确
    //预期结果: 请求失败, 或返回的信息提示输入不合法
    public void TestTwoF() throws URISyntaxException, IOException {
        CloseableHttpClient client = HttpClients.createDefault();

        URI uri = new URIBuilder()
                .setScheme("https")
                .setHost("api.map.baidu.com")
                .setPath("/place/v2/suggestion")
                .setParameter("query", "天安门")
                .setParameter("region", "北京市")
                .setParameter("city_limit", "true")
                .setParameter("coord_type", "2")
                .setParameter("ret_coordtype", "123")
                .setParameter("ak", "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k")
                .build();

        HttpGet get = new HttpGet(uri);

        CloseableHttpResponse response = client.execute(get);
        StatusLine status = response.getStatusLine();
        System.out.println(status);
        Assert.assertEquals(status.getStatusCode(), 200);

        String content_type = response.getFirstHeader("Content-Type").toString();
        System.out.println(content_type);
        Assert.assertTrue(content_type.contains("xml"));

        String responseText = EntityUtils.toString(response.getEntity());
        System.out.println(responseText);
        //Assert.assertTrue(responseText.contains("Failure"));

    }
    

}
