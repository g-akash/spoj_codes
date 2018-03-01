from decimal import *
import math

getcontext().prec = 50
#print Decimal(math.pi)

mul = Decimal(1.0)-Decimal(6.0)/(Decimal(math.pi)*Decimal(math.pi))
n = int(raw_input())
x = 1
y = 40000000000000000
while y-x > 1:
	mid = (x+y)/2
	if Decimal(mid)*Decimal(mul)>Decimal(n):
		y = mid
	else:
		x = mid


def sqful(num):
	for i in range(2,10000000):
		if num%(i*i)==0:
			return True
	return False

if sqful(y):
	print y
elif sqful(y+1):
	print y+1
elif sqful(y+2):
	print y+2
else:
	print y+3