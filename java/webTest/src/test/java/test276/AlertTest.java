package test276;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

import java.util.concurrent.TimeUnit;

public class AlertTest {
    public static void main(String[] args) {
        WebDriver driver = new FirefoxDriver();
        driver.manage().window().maximize();
        driver.manage().timeouts().implicitlyWait(5, TimeUnit.SECONDS);
        driver.get("file:///C:/Users/51Testing/Desktop/alert.html");

        driver.findElement(By.id("btnConfirm")).click();
        driver.switchTo().alert().accept();


        driver.findElement(By.id("btnAlert")).click();


        driver.findElement(By.id("btnPrompt")).click();




    }

}
