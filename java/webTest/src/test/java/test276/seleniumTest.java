package test276;


import io.github.bonigarcia.wdm.WebDriverManager;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.Select;
import org.testng.annotations.Test;

import java.util.concurrent.TimeUnit;

public class seleniumTest {
    public static void main(String[] args) throws InterruptedException {
        System.setProperty("webdriver.firefox.bin","D:\\Program\\Firefox\\firefox.exe");
        WebDriverManager.firefoxdriver().setup();

        //新建浏览器驱动
        WebDriver driver = new FirefoxDriver();


        //访问对应的网址
        driver.get("http://localhost/iwebshop/index.php");

        //定位并执行登陆操作
        driver.findElement(By.linkText("登录")).click();

        driver.findElement(By.name("login_info")).sendKeys("test276");
        driver.findElement(By.name("password")).sendKeys("123456");
        driver.findElement(By.className("input_submit")).click();

        //检查登录是否成功
        Thread.sleep(3000);
        String actual =  driver.getCurrentUrl();

        //添加隐式等待
        driver.manage().timeouts().implicitlyWait(5, TimeUnit.SECONDS);

        //访问页面上的指定网页
        driver.findElement(By.linkText("地址管理")).click();
        driver.findElement(By.xpath("//div[@class='new_address_btn']")).click();

        //切换到弹出的新"框架", 然后输入地址信息
        driver.switchTo().frame("OpenaddressWindow");
        driver.findElement(By.xpath("/html/body/form/section/ul/li[1]/input")).sendKeys("test");

        //下拉框选择
        new Select(driver.findElement(By.name("province"))).selectByIndex(3);
        new Select(driver.findElement(By.name("city"))).selectByValue("130400");
        new Select(driver.findElement(By.name("area"))).selectByVisibleText("邯郸县");






//        driver.quit();

    }

    @Test
    public static void testOne(){
        System.out.println("3");
    }




}
