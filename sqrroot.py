t=0
t = int(input())

n=0
for i in range(t):
	n = input()
	n = int(n)
	x=0
	y=n+1
	for i in range(10000):
		if y-x<=1:
			break
		mid = int((x+y)//2)
		if mid*mid>n:
			y=mid
		else:
			x = mid

	print(x)

