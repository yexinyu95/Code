package test276;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;

import java.util.concurrent.TimeUnit;

public class seleniumFunc {

    /**
     * 登录操作
     */
    public boolean loginAction(WebDriver driver, String username, String password) throws InterruptedException {
        //访问后端网站
        driver.get("http://127.0.0.1:8088/index.php?m=user&c=public&a=login");

        //逐个输入数据, 用户名/密码/验证码
        driver.findElement(By.name("username")).sendKeys(username);
        driver.findElement(By.name("password")).sendKeys(password);
        driver.findElement(By.className("login_btn")).click();

        //等待一段时间, 以便浏览器跳转
        Thread.sleep(10000);

        //记录跳转后的网址
        String expected = "http://127.0.0.1:8088/index.php?m=user&c=index&a=index";
        String actual = driver.getCurrentUrl();

        //判断网址是否正确
        return actual.equals(expected);
    }

    /**
     * 寻找网页上的元素
     */
    public void findText(WebDriver driver, String texta, String textb, String textc) {
        driver.manage().timeouts().implicitlyWait(15, TimeUnit.SECONDS);

        driver.findElement(By.linkText(texta)).click();
        driver.findElement(By.linkText(textb)).click();
        driver.findElement(By.linkText(textc)).click();

    }


}
