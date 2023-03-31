import requests, bs4, os, re


regex = re.compile(r"(.*)(/.*)$")

search_query = "https://www.google.com/search?q="

for folder in os.listdir():
    if os.path.isdir(folder) and not folder.startswith("."):
        res = requests.get(search_query + "codeforces " + folder)
        print("Extracted : ", folder)
        souped = bs4.BeautifulSoup(res.text, "html.parser")
        links = souped.find_all('a')
        for i in links:
            if i['href'].startswith("/url?q=https://codeforces.com"):
                mo = regex.search(i['href'])
                link = mo.group(1).lstrip("/url?q=")
                # print(mo.group(1).lstrip("/url?q="))
                f = open(folder+"/"+folder+".txt", "w")
                f.write(link)
                f.close()
                break
        
        
