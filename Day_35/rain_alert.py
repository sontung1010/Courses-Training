import requests
from twilio.rest import Client
import smtplib

OWM_Endpoint = "https://api.openweathermap.org/data/2.8/onecall"
api_key = "d389ae681a6104f289ca3891610ee965"
account_sid = ""
auth_token = ""

weather_params = {
    "lat": 42.28,
    "lon": -83.74,
    "exclude": "current,minutely,daily",
    "appid": api_key
}

response = requests.get(OWM_Endpoint, params=weather_params)
response.raise_for_status()
weather_data = response.json()
weather_slice = weather_data["hourly"][:12]

will_rain = False

for hour_data in weather_slice:
    condition_code = hour_data["weather"][0]["id"]
    if int(condition_code) < 700:
        will_rain = True

if will_rain:
    client = Client(account_sid, auth_token)
    message = client.messages \
        .create(
            body="It's going to rain today. Remember to bring an umbrella.",
            from_="",
            to=""
        )
    
    print(message.status)
    




