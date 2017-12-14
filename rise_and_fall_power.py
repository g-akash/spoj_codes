import math



def calc_las(x,k):
	y = x
	ans = 1
	tmp = x
	for i in range(40):
		if y == 0:
			break
		if y%2==1:
			ans = ans * tmp
		tmp = tmp * tmp
		tmp = tmp%k
		ans = ans % k
		y = y/2
	return ans


t = int(raw_input())
for i in range(t):
	x = map(int,raw_input().split())
	lg = math.log10(x[0])
	val = float(x[0])*lg
	#print val
	val = val-float(int(val)-100)
	
	#print val
	ans = 10**val
	tmp = 10**x[1]
	for j in range(200):
		if ans < tmp:
			break
		ans/=10.0
	ans = int(ans)
	ans1 = calc_las(x[0],10**x[1])
	print ans,("%0"+str(x[1])+"d")%(ans1,)
