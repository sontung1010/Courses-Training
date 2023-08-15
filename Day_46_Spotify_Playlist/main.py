from bs4 import BeautifulSoup
import requests

import spotipy
from spotipy.oauth2 import SpotifyOAuth


# date = input("Which year do you want to travel to? Type the date in this format YYYY-MM-DD: ")
# response = requests.get("https://www.billboard.com/charts/hot-100/" + date)
# soup = BeautifulSoup(response.text, 'html.parser')
# song_names_spans = soup.select("li ul li h3")
# song_names = [song.getText().strip() for song in song_names_spans]
# print(song_names)





sp = spotipy.Spotify(
    auth_manager=SpotifyOAuth(
        scope="playlist-modify-private",
        redirect_uri="https://example.com",
        client_id="",
        client_secret="",
        show_dialog=True,
        cache_path="Day_46_Spotify_Playlist/token.txt",
        # username="Tung"
    )
)
user_id = sp.current_user()["id"]


date = input("Which year do you want to travel to? Type the date in this format YYYY-MM-DD: ")
response = requests.get("https://www.billboard.com/charts/hot-100/" + date)
soup = BeautifulSoup(response.text, 'html.parser')
song_names_spans = soup.select("li ul li h3")
song_names = ["The list of song", "titles from your", "web scrape"]

# song_uris = ["The list of", "song URIs", "you got by", "searching Spotify"]

song_uris = []
year = date.split("-")[0]
for song in song_names:
    result = sp.search(q=f"track:{song} year:{year}", type="track")
    print(result)
    try:
        uri = result["tracks"]["items"][0]["uri"]
        song_uris.append(uri)
    except IndexError:
        print(f"{song} doesn't exist in Spotify. Skipped")

playlist = sp.user_playlist_create(user=user_id, name=f"{date} Billboard 100", public=False)

print(playlist)

sp.playlist_add_items(playlist_id=playlist["id"], items=song_uris)