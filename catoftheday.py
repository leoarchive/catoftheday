import giphy_client
import os
from giphy_client.rest import ApiException

api_instance = giphy_client.DefaultApi()
api_key = 'KBoPq5N3OWxzlOmgRe6LyncvFwFETpLr'
tag = 'cute cat'
rating = 'r'
fmt = 'json'

try:
    api_response = api_instance.gifs_random_get(api_key, tag=tag, rating=rating, fmt=fmt)

    while True:
        api_response = api_instance.gifs_random_get(api_key, tag=tag, rating=rating, fmt=fmt)
        print("novo gatinho: " + api_response.data.image_url)
        print("confirmar? s/n")
        i = input()
        if i == "s":
            break

    f = open('README.md', 'w')
    f.write("``` hello, welcome to my github ```")
    f.write("\n\n")
    f.write("![gatinho](" + api_response.data.image_url + ")")

    os.system("git add README.md")
    os.system("git commit -m \"gatinho do dia\"")
    os.system("git push")
except ApiException as e:
    print("Exception when calling DefaultApi->gifs_random_get: %s\n" % e)
