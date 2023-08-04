from bs4 import BeautifulSoup
import pandas as pd

from selenium import webdriver
from selenium.webdriver.common.by import By

import time

# download driver and set driver's path
driver_path = 'C:\\Users\\abcqa'

# build a new Chrome driver(open a new window)
driver = webdriver.Chrome(executable_path=driver_path)

# set and visit the website
url = 'https://bj.offcn.com/zw/2022/psearch.html'
driver.get(url)

# loop for 112 times
pages = 1
while(pages < 161):
    # get content form the website
    html_content = driver.page_source

    # resolve the content using BeautifulSoup
    soup = BeautifulSoup(html_content, 'html.parser')
    table_rows = soup.find_all('tr')

    data = []
    for row in table_rows:
        table_data = row.find_all('td')
        row_data = [cell.get_text(strip=True) for cell in table_data]
        data.append(row_data)

    # use pandas to turn raw data into csv files
    df = pd.DataFrame(data)
    df.to_csv('C:\\Users\\abcqa\\Desktop\\folder\\test2022.csv', index=False, mode='a')

    # turn to next page, using selenium's find_element
    driver.find_element(by=By.XPATH, value="//a[text()='下一页']").click()
    time.sleep(2)

    pages = pages + 1
