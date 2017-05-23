import urllib.request as ur
from bs4 import BeautifulSoup
def extract_text(link):
    f = ur.urlopen(link)
    myfile = f.read()
    soup = BeautifulSoup(myfile, 'html.parser')
    to_extract = soup.findAll('script')
    for item in to_extract:
        item.extract()
    mytext = " ".join(soup.get_text().split("\n"))
    mytext = " ".join(mytext.split("\r"))
    return mytext

f = open("text.txt", 'r')
output = open("plain.txt", 'w+', encoding='utf-8')
nn = 0
for line in f:
    text = extract_text(line)
    length = len(text)
    for i in range(0,length):
        output.write('{}'.format(text[i]))
    output.write('\n')
output.close()






