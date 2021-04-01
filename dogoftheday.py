import giphy_client
import os
from giphy_client.rest import ApiException

api_instance = giphy_client.DefaultApi()
api_key = 'KBoPq5N3OWxzlOmgRe6LyncvFwFETpLr'
tag = 'dog cute'
rating = 'g'
fmt = 'json'

try:
    api_response = api_instance.gifs_random_get(api_key, tag=tag, rating=rating, fmt=fmt)
     
    f = open('README.md', 'w')
    f.write("``` hello, welcome to my github ```")
    f.write("\n\n")
    f.write("![doguinho](" + api_response.data.image_url + ")")
    f.close()

    os.system("git add README.md")
    os.system("git commit -m \"doguinho do dia\"")
    os.system("git push")
except ApiException as e:
    print("Exception when calling DefaultApi->gifs_random_get: %s\n" % e)
