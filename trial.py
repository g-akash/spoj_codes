import math
n = int(input())
while(n>0):
    a,b = map(int,input().split())
    count=0
    for i in range(a,b+1):
        root = float(math.sqrt(i))
        if((root*root)==i):
            count=count+1
            print(i,count)
    print("final",count)
    n=n-1
