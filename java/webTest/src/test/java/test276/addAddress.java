package test276;

import org.openqa.selenium.By;
import org.openqa.selenium.NoAlertPresentException;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.Select;

import java.util.concurrent.TimeUnit;

public class addAddress {
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

        if (test) {
            System.out.println("调用登录脚本, 登录成功, 继续下一步操作");
            driver.manage().timeouts().implicitlyWait(15, TimeUnit.SECONDS);

			//跳转到添加地址界面
            driver.findElement(By.linkText("账号设置")).click();
            Thread.sleep(1000);
            driver.findElement(By.linkText("个人资料")).click();
            Thread.sleep(1000);
            driver.findElement(By.linkText("收货地址")).click();

			//依次添加地址信息

            //收货人姓名
            driver.findElement(By.name("username")).sendKeys("test275");

            //寄送区域
            Select sl = new Select(driver.findElement(By.id("province")));
            sl.selectByIndex(16);
            sl.selectByVisibleText("许昌市");

            //匿名对象, 不声明对象的实例, 直接调用方法
            new Select(driver.findElement(By.id("district"))).selectByValue("411001");

            //详细地址
            driver.findElement(By.name("address")).sendKeys("test275");

            //邮编
            driver.findElement(By.name("zip")).sendKeys("121212");

            //联系电话
            driver.findElement(By.name("mobile")).sendKeys("13212211221");

            //设置为默认地址
            driver.findElement(By.name("status")).click();
/*

			//点击按钮
            driver.findElement(By.className("btn3")).click();
		

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
