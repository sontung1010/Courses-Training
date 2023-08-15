from bs4 import BeautifulSoup
import requests

# with open("Day_45_Web_Scraping/website.html") as file:
#     contents = file.read()


# soup = BeautifulSoup(contents, "html.parser")
# # print(soup.title.string)

# all_anchor_tags = soup.find_all(name="a")
# # print(all_anchor_tags)

# # for tag in all_anchor_tags:
# #     print(tag.get("href"))

# heading = soup.find(name="h1", id="name")
# print(heading)

# section_heading = soup.find(name="h3", class_="heading")
# print(section_heading)

# company_url = soup.select_one(selector="p a")
# print(company_url)

response = requests.get("https://news.ycombinator.com/news")

yc_web_page = response.text

soup = BeautifulSoup(yc_web_page, "html.parser")
articles = soup.find_all(name="span", class_="titleline")
article_texts = []
article_links = []

for article_tag in articles:
    text = article_tag.getText()
    article_texts.append(text)
    link = article_tag.find(name="a").get("href")
    article_links.append(link)


article_upvotes = [int(score.getText().split()[0]) for score in soup.find_all(name="span", class_="score")]

# print(article_texts)
# print(article_links)
# print(article_upvotes)

largest_number = max(article_upvotes)
largest_index = article_upvotes.index(largest_number)


print(article_texts[largest_index])
print(article_links[largest_index])
