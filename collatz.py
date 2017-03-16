import sys
for n in sys.stdin:
	n=int(n)
	count=1
	while n!=1:
		if n%2==0:
			n=n/2
			count+=1
		else:
			n=3*n+1
			count=count+1
	print count
	
