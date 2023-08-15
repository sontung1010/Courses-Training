from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

options = webdriver.ChromeOptions()
options.add_experimental_option("detach", True)

driver = webdriver.Chrome(options=options)

driver.get("http://secure-retreat-92358.herokuapp.com/")

first_name = driver.find_element(By.NAME, "fName")
first_name.send_keys("Tung")
last_name = driver.find_element(By.NAME, "lName")
last_name.send_keys("Do")
email = driver.find_element(By.NAME, "email")
email.send_keys("example@gmail.com")

submit = driver.find_element(By.CSS_SELECTOR, "form button")
submit.click()








# driver.get("https://en.wikipedia.org/wiki/Main_Page")

# search = driver.find_element(By.NAME, "search")
# search.send_keys("Python")
# search.send_keys(Keys.ENTER)