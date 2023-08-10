from pprint import pprint
import requests
import os

SHEETY_PRICES_ENDPOINT = "https://api.sheety.co/974059a11829624d89307f174029407d/pythonFlightDeals/prices"
SHEET_USERS_ENDPOINT = "https://api.sheety.co/974059a11829624d89307f174029407d/pythonFlightDeals/users"


BEARER = os.getenv("BEARER")

class DataManager:
    def __init__(self):
        self.destination_data = {}
        self.headers = {
            "Authorization": f"Bearer {BEARER}"
        }

    def get_destination_data(self):
        response = requests.get(url=SHEETY_PRICES_ENDPOINT, headers=self.headers)
        data = response.json()
        self.destination_data = data["prices"]
        return self.destination_data
    
    def update_destination_codes(self):
        for city in self.destination_data:
            new_data = {
                "price": {
                    "iataCode": city["iataCode"]
                }
            }
            response = requests.put(
                url=f"{SHEETY_PRICES_ENDPOINT}/{city['id']}",
                json=new_data
            )
            print(response.text)

    def get_customer_emails(self):
        customers_endpoint = SHEET_USERS_ENDPOINT
        response = requests.get(customers_endpoint, headers=self.headers)
        data = response.json()
        self.customer_data = data["users"]
        return self.customer_data