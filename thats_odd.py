n = int(raw_input())
x = [0]*n
for i in range(n):
	tmp = int(raw_input())
	x[i]=tmp

x.sort()


facs = [0]*50
facs[0]=1
for i in range(1,50):
	facs[i]=facs[i-1]*i

ans = 0
for i in range(n):
	if x[i]<=0:
		continue
	num = n-1
	r = min(i,n-1-i)
	times = facs[n-1]/(facs[r]*facs[n-1-r])
	ans+=(times*x[i])

print ans
	
