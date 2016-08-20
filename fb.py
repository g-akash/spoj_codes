import fb #To install this package run: sudo pip install fb
from facepy import GraphAPI #To install this package run: sudo pip install facepy
import time
token="CAACEdEose0cBAKO4DiqfxASWlKx35gWZCxmWhLjXiA6mt5RxUUI7hm82K40CRbivkAyvEZB4WywbI2YHyI8FsVnVZCeYRb2ogBWqrpvQSVVxyDM2nFdKTJHEi02LIKIeiCResgVRZArpecl0wbytz0w70EPlzXZAGtKwUqwsFErl0tjoQO4rs0oxRMOH8H2ABkGQMi3CJJwZDZD"#Insert access token here.  
facebook=fb.graph.api(token)
graph1 = GraphAPI(token)
vid=102988293558 #This is flipkart page's facebook id
query=str(vid)+"/posts?fields=id&limit=5000000000"
r=graph1.get(query)
idlist=[x['id'] for x in r['data']]
print("There are "+ str(len(idlist)) +" commentable posts.")
char1='y'
count=0