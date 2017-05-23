import metapy
import requests
from bs4 import BeautifulSoup
import io
import sys

doc = metapy.index.Document()
doc.content(sys.stdin.read())

tok = metapy.analyzers.ICUTokenizer(suppress_tags=True)
tok = metapy.analyzers.LowercaseFilter(tok)
tok = metapy.analyzers.ListFilter(tok, "lemur-stopwords.txt", metapy.analyzers.ListFilter.Type.Reject)
tok = metapy.analyzers.Porter2Filter(tok)
ana = metapy.analyzers.NGramWordAnalyzer(1, tok)
ret = ana.analyze(doc)
length = len(ret)
h = ret.items()
string  = ''
for i in range(0,length):
    string += h[i][0]
    string += ' '
print(string)
