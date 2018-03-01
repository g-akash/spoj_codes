

def check_power(x):
	while x>0:
		if x%2==1 and x!=1:
			return False
		x/=2
	return True


def gcd(x,y):
	if x==0 or y==0:
		if x!=0:
			return x
		elif y!=0:
			return y
		else:
			return 1
	if x%y==0:
		return y
	else:
		return gcd(y,x%y)

def calcpow(a,b):
	ans = 1
	curr = a
	while b>0:
		if b%2==1:
			ans*=curr
		curr*=curr
		ans%=1000000007
		curr%=1000000007
		b/=2
	return ans


test = int(raw_input())
while test>0:
	test-=1;
	x = map(int,raw_input().split())
	if len(x)<3:
		print 0
		continue
	l = x[0]
	d = x[1]
	t = x[2]
	ol = l
	if t>3:
		print 0
		continue
	elif t==2:
		d=2*d*d-l*l
		l=l*l
	elif t==3:
		d=4*d*d*d-3*d*l*l
		l=l*l*l

	d*=ol
	gd = gcd(d,l)
	d/=gd
	l/=gd
	cp = calcpow(l,1000000005)
	ans = d*cp
	ans%=1000000007
	print ans

	