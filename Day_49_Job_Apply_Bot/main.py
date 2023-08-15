from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import NoSuchElementException
import time

ACCOUNT_EMAIL = ""
ACCOUNT_PASSWORD = ""
PHONE = ""

options = webdriver.ChromeOptions()
options.add_experimental_option("detach", True)
driver = webdriver.Chrome(options=options)
driver.get("https://www.linkedin.com/jobs/search/?currentJobId=2976771076&f_AL=true&keywords=python")

time.sleep(2)
sign_in_button = driver.find_element(By.LINK_TEXT, "Sign in")
sign_in_button.click()

time.sleep(5)
email_field = driver.find_element(By.ID, "username")
email_field.send_keys(ACCOUNT_EMAIL)
password_field = driver.find_element(By.ID, "password")
password_field.send_keys(ACCOUNT_PASSWORD)
password_field.send_keys(Keys.ENTER)

time.sleep(5)

# all_listings = driver.find_elements(By.CSS_SELECTOR, ".job-card-container--clickable")
all_listings = driver.find_elements(By.CSS_SELECTOR, ".jobs-search-results__list-item")
print(type(all_listings))

for listing in all_listings:
    print("called")
    listing.click()
    time.sleep(2)

    try:
        apply_button = driver.find_element(By.CSS_SELECTOR, ".jobs-apply-button--top-card")
        # apply_button = driver.find_element(By.CSS_SELECTOR, ".job-s-apply button")
        apply_button.click()
        time.sleep(5)

        phone = driver.find_element(By.CLASS_NAME, "fb-single-line-text__input")
        if phone.text == "":
            phone.send_keys(PHONE)

        submit_button = driver.find_element(By.CSS_SELECTOR, "footer button")

        if submit_button.get_attribute("data-control-name") == "continue_unify":
            close_button = driver.find_element(By.CLASS_NAME, "artdeco-modal__dismiss")
            close_button.click()
            time.sleep(2)
            discard_button = driver.find_elements(By.CLASS_NAME, "artdeco-modal__confirm-dialog-btn")[1]
            discard_button.click()
            print("Complex application, skipped.")
            continue
        else:
            submit_button.click()

        time.sleep(2)
        close_button = driver.find_element(By.CLASS_NAME, "artdeco-modal__dismiss")
        close_button.click()

    except NoSuchElementException:
        print("No application button, skipped.")
        continue

time.sleep(5)
driver.quit()