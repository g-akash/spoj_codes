from random import *
import time


t = int(raw_input())
p = 0

def power(a,b):
	ans = 1
	var = a
	while b!=0:
		if b%2==1:
			ans = ans * var
			ans = ans%p
		var = var * var
		var = var%p
		b/=2
	return ans

seed(time.clock())

for i in range(t):
	p = int(raw_input())
	num = 0
	ans = True
	for i in range(100):
		num = 0
		while num%p==0:
			num = randint(3,10000)

		rem = power(num,p-1)
		#print num,rem
		if rem !=1:
			ans = False
	if ans:
		print "YES"
	else:
		print "NO"
