package test276;

import io.github.bonigarcia.wdm.WebDriverManager;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class getWebtext {
    public static void main(String[] args) {
        System.setProperty("webdriver.firefox.bin","D:\\Program\\Firefox\\firefox.exe");
        WebDriverManager.firefoxdriver().setup();

        //新建浏览器驱动
        WebDriver driver = new FirefoxDriver();

        driver.get("https://www.selenium.dev/selenium/web/web-form.html");

        String value = driver.findElement(By.cssSelector("div.col-md-4:nth-child(1) > label:nth-child(3)")).getTagName();

        System.out.println(value);





    }
}
