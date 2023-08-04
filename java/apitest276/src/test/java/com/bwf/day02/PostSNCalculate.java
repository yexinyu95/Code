package com.bwf.day02;// 根据您选择的AK以为您生成调用代码
// 检测您当前的AK设置了sn检验，本示例中已为您生成sn计算代码
import java.io.UnsupportedEncodingException;
import java.security.NoSuchAlgorithmException;
import java.net.URLEncoder;
import java.util.TreeMap;
import java.util.Map;

public class PostSNCalculate {

    public static String Host = "https://api.map.baidu.com";

    public static String URI = "/trackmatch/v1/track";

    public static String AK = "oaixlqaM1995LwdeZd3ZfBCaaseLAV7k";

    public static String SK = "3Y58SY1q6FbAHGz7IuWgHA3zy8CLeEhg";

    public static void main(String[] args) throws Exception {

        PostSNCalculate tm = new PostSNCalculate();

        // 请求参数
        //String option = "need_mapmatch:1|transport_mode:driving|denoise_grade:1|vacuate_grade:1";
        //String standard_option = "need_mapmatch:1|transport_mode:driving|denoise_grade:1|vacuate_grade:1";
        String coord_type_input = "bd09ll";
        String coord_type_output = "bd09ll";
        String standard_track = "[" +
                "\"36.2715924153,120.401133898,1542702871,10,0,182,10\"," +
                "\"36.2710674153,120.401122046,1542702922,10,0,196,10\"," +
                "\"36.2006024054,120.37507592,1542705846,10,61.12,346,10\"," +
                "\"36.2087023867,120.372944857,1542705897,10,71.34,348,10\"" +
                "]";
        String track = "[" +
                "\"36.2716924153,120.401133898,1542702871,10,0,182,10\"," +
                "\"36.2712674153,120.401122046,1542702922,10,0,196,10\"," +
                "\"36.2006024054,120.37507592,1542705846,10,61.12,346,10\"," +
                "\"36.2087023867,120.372944857,1542705897,10,71.34,348,10\"" +
                "]";

        // POST请求，此处使用TreeMap，默认按key排序
        Map params = new TreeMap<String, String>();
        //params.put("option", option);
        //params.put("standard_option", standard_option);
        params.put("coord_type_input", coord_type_input);
        params.put("coord_type_output", coord_type_output);
        params.put("standard_track", standard_track);
        params.put("track", track);
        params.put("ak", AK);

        tm.requestPost(Host, URI, params, SK);
    }

    /** 发送POST请求 */
    // 计算sn跟参数对出现顺序有关，
    // get请求请使用LinkedHashMap保存<key,value>，该方法根据key的插入顺序排序；
    // post请使用TreeMap保存<key,value>，该方法会自动将key按照字母a-z顺序排序。
    public void requestPost(String host, String uri, Map<String, String> param, String sk) throws Exception {
        String strUrl = host + uri;
        if (strUrl == null || strUrl.length() <= 0 || param == null || param.size() <= 0) {
            return;
        }

        // 构造x-www-form-urlencoded格式的字符串
        StringBuffer queryString = new StringBuffer();
        for (Map.Entry<?, ?> pair : param.entrySet()) {
            queryString.append(pair.getKey() + "=");
            queryString.append(URLEncoder.encode((String) pair.getValue(), "UTF-8") + "&");
        }
        if (queryString.length() > 0) {
            queryString.deleteCharAt(queryString.length() - 1);
        }
        String paramString = queryString.toString();

        // 计算sn
        String sn= caculateSn(uri, paramString, sk);
        System.out.println(sn);
        //paramString += "&sn=" + sn;


/*
        String result = "";
        try {
            URL url = new URL(strUrl);
            HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
            urlConnection.setRequestMethod("POST");
            //设置连接的超时值为3000毫秒，超时将抛出SocketTimeoutException异常
            urlConnection.setConnectTimeout(3000);
            //设置读取的超时值为3000毫秒，超时将抛出SocketTimeoutException异常
            urlConnection.setReadTimeout(3000);
            //将url连接用于输出，这样才能使用getOutputStream()。getOutputStream()返回的输出流用于传输数据
            urlConnection.setDoOutput(true);
            //设置Content-Type
            urlConnection.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
            //getOutputStream()返回的输出流，用于写入参数数据。
            OutputStream outputStream = urlConnection.getOutputStream();
            outputStream.write(paramString.getBytes());
            outputStream.flush();
            outputStream.close();
            //此时将调用接口方法。getInputStream()返回的输入流可以读取返回的数据。
            InputStreamReader isr = new InputStreamReader(urlConnection.getInputStream());
            BufferedReader reader = new BufferedReader(isr);
            StringBuffer buffer = new StringBuffer();
            String line;
            while ((line = reader.readLine()) != null) {
                buffer.append(line);
            }
            reader.close();
            isr.close();

            System.out.println("返回的内容: " + buffer.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }

        */
    }

    private String caculateSn(String URI, String param, String SK)
            throws UnsupportedEncodingException, NoSuchAlgorithmException {
        // 对paramsStr前面拼接上uri，后面直接拼接sk
        String wholeStr = new String(URI + "?" + param + SK);
        // 对上面wholeStr再作utf8编码
        String tempStr = URLEncoder.encode(wholeStr, "UTF-8");

        // 调用下面的MD5方法得到最后的sn签名
        String sn = MD5(tempStr);
        return sn;
    }

    // 来自stackoverflow的MD5计算方法，调用了MessageDigest库函数，并把byte数组结果转换成16进制
    private String MD5(String md5) {
        try {
            java.security.MessageDigest md = java.security.MessageDigest.getInstance("MD5");
            byte[] array = md.digest(md5.getBytes());
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < array.length; ++i) {
                sb.append(Integer.toHexString((array[i] & 0xFF) | 0x100).substring(1, 3));
            }
            return sb.toString();
        } catch (java.security.NoSuchAlgorithmException e) {
        }
        return null;
    }
}