





def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)

n=input()
for i in range(0,n):
	a=raw_input()
	b=a.split()
	print gcd(int(b[0]),int(b[1]))