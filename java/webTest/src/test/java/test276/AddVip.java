package test276;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.util.concurrent.TimeUnit;

public class AddVip {
    public static void main(String[] args) throws InterruptedException {
//        1、打开浏览器
        WebDriver driver = new FirefoxDriver();
//        2、浏览器最大化
        driver.manage().window().maximize();
//        3、隐式等待
        driver.manage().timeouts().implicitlyWait(5, TimeUnit.SECONDS);
//        4、获取网址
        driver.get("http://127.0.0.1:8088/index.php?&m=admin&c=public&a=login");
//        5、输入用户名、密码、验证码
        driver.findElement(By.name("username")).sendKeys("admin");
        driver.findElement(By.name("userpass")).sendKeys("password");
        driver.findElement(By.name("userverify")).sendKeys("1234");
//        6、点击【登录】
        driver.findElement(By.className("Btn")).click();
//        7、点击【会员管理】 、【添加会员】
        driver.findElement(By.linkText("会员管理")).click();
        driver.findElement(By.linkText("添加会员")).click();

        //切换框架
//        driver.switchTo().frame(0);
//        driver.switchTo().frame("mainFrame");
        driver.switchTo().frame(driver.findElement(By.name("mainFrame")));



//        8、输入会员信息
        driver.findElement(By.name("username")).sendKeys("熊大熊大");
        driver.findElement(By.name("mobile_phone")).sendKeys("13212123434");

        driver.findElement(By.xpath("//input[@value='1' and @name='sex']")).click();
        driver.findElement(By.name("birthday")).sendKeys("2002-02-21");

        driver.findElement(By.name("email")).sendKeys("test@1.com");
        driver.findElement(By.name("qq")).sendKeys("123456");

//        9、点击【提交】
        driver.findElement(By.className("button_search")).click();

//        10、验证是否添加成功
        //网页没有跳转, 不能通过网址判断是否添加成功
        //需要通过获取网页内容进行判断,

        //如果网页内容包含注册时间, 则说明添加会员成功; 否则添加会员失败
        WebDriverWait wait = new WebDriverWait(driver, 15);

        String pageSource = driver.getPageSource();

        if(pageSource.contains("注册时间")){
            System.out.println("添加会员成功");
        }else{
            System.out.println("添加会员失败");
        }


        driver.switchTo().parentFrame();
        driver.findElement(By.linkText("退出系统")).click();

    }

}
