package test276;

import org.openqa.selenium.By;
import org.openqa.selenium.Keys;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.interactions.Actions;

import java.util.Set;
import java.util.concurrent.TimeUnit;

public class Shopping {

    public static void main(String[] args) throws InterruptedException {
        //初始化浏览器驱动并最大化
        WebDriver driver = new FirefoxDriver();
        driver.manage().window().maximize();

        //访问网站
        driver.get("http://127.0.0.1:8088/index.php?m=user&c=public&a=login");

        //逐个输入数据, 用户名/密码/验证码
        driver.findElement(By.name("username")).sendKeys("test275");
        driver.findElement(By.name("password")).sendKeys("123456");
        driver.findElement(By.className("login_btn")).click();

        //等待一段时间, 以便浏览器跳转
        Thread.sleep(10000);

        //记录跳转后的网址
        String expected = "http://127.0.0.1:8088/index.php?m=user&c=index&a=index";
        String actual = driver.getCurrentUrl();

        boolean test = actual.equals(expected);

        driver.manage().timeouts().implicitlyWait(15, TimeUnit.SECONDS);



        if (test) {
            System.out.println("调用登录脚本, 登录成功, 继续下一步操作");

//            1、调用登录脚本

//            2、点击【返回商城首页】
            driver.findElement(By.linkText("返回商城首页")).click();
//            3、将鼠标移动至【手机、数码、通讯】上
            Actions ac= new Actions(driver);
            ac.moveToElement(driver.findElement(By.linkText("手机、数码、通讯"))).perform();

//            4、点击【手机】
            driver.findElement(By.linkText("手机")).click();
//            new Actions(driver).moveToElement(driver.findElement(By.linkText("手机"))).click();
//            5、点击【苹果 (Apple) iPhone 6 】（partialLinkText）
            driver.findElement(By.partialLinkText("苹果 (A")).click();

//            6、修改购买数量-5
            driver.close();
            for(String handles: driver.getWindowHandles()) {
                driver.switchTo().window(handles);
            }

            //driver.findElement(By.className("goods-number")).clear(); //clear不能清除默认值
            driver.findElement(By.className("goods-number")).sendKeys(Keys.BACK_SPACE);
            Thread.sleep(3000);
            driver.findElement(By.className("goods-number")).sendKeys("5");

//            7、点击【加入购物车】
            driver.findElement(By.className("goods-pay-btn-c")).click();

//           8、点击【去购物车结算】
            driver.findElement(By.className("shopCar_T_span3")).click();

//            9、点击【结算】
            driver.findElement(By.linkText("结算")).click();

//            10、确认收货地址（只支持上海配送）
            driver.findElement(By.xpath("//div[@data-city='310100']")).click();

//            11、确认配送方式-顺丰
            driver.findElement(By.xpath("//input[@value='1' and @name='delivery_id']")).click();

//            12、确认支付方式-在线
            driver.findElement(By.xpath("//input[@value='0' and @name='pay_type']")).click();

//            13、提交订单
            driver.findElement(By.xpath("//div[@class='agree-order-fr-btn']")).click();





/*

            //检查弹出窗口, 并且确定
            try {
                String text = driver.switchTo().alert().getText();
                driver.switchTo().alert().accept();
                System.out.println(text);
            }
            catch (NoAlertPresentException e){
                System.out.println("代码报错,没有弹窗弹出,修改失败");
            }
*/


        } else {
            System.out.println("调用登录脚本, 登录失败, 终止操作");
        }

//        driver.quit();

    }
}