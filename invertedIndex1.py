import metapy
import requests
from bs4 import BeautifulSoup
import io
import sys

f = open("plain_final.txt","r")
myList = []
for line in f:
    myList.append(line)
l = len(myList)

doc = metapy.index.Document()

tok = metapy.analyzers.ICUTokenizer(suppress_tags=True)
tok = metapy.analyzers.LowercaseFilter(tok)
tok = metapy.analyzers.ListFilter(tok, "lemur-stopwords.txt", metapy.analyzers.ListFilter.Type.Reject)
tok = metapy.analyzers.Porter2Filter(tok)
ana = metapy.analyzers.NGramWordAnalyzer(1, tok)
space = str(' ').decode("utf-8")
newLine = str('\n').decode("utf-8")
docLen = []
text_file = io.open("Output.txt", "w", encoding='utf-8')
for j in range(0,l):
    u = unicode(myList[j], "utf-8")
    doc.content(u)
    ret = ana.analyze(doc)
    h = ret.items()
    length = len(h)
    docLen.append(length)
    nid = str(j+1).decode("utf-8")
    for i in range(0,length):
        h1 = h[i][0]
        #h2 = h[i][1]
        h2 = str(h[i][1]).decode("utf-8")
        text_file.write(h1)
        text_file.write(space)
        text_file.write(nid)
        text_file.write(space)
        text_file.write(h2)
        text_file.write(newLine)

text_file.close()
length_file = open("docLen.txt", "w")
for k in range(0,len(docLen)):
    length_file.write('{}'.format(docLen[k]))
    length_file.write(' ')
length_file.close()

