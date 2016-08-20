ans = []
ans.append(1);
ans.append(1);
for i in range (2,151):
	val=0
	for j in range(0,i):
		val = val + ans[j]*ans[i-1-j]
	ans.append(val)

n=raw_input()
n=int(n)
while n != -1:
	print ans[n]
	n=raw_input()
	n=int(n)