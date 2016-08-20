t=raw_input();
t=int(t);
for i in range(0,t):
	line = raw_input()
	line=line.split(" ");
	n=int(line[0])
	k = int(line[1]);
	n=n-1
	k=k-1
	ans=1;
	if k<n/2:
		for j in range(n+1-k,n+1):
			ans=ans*j
		for j in range(1,k+1):
			ans=ans/j
		print ans

	else:
		for j in range(k+1, n+1):
			ans=ans*j
		for j in range(1,n+1-k):
			ans=ans/j
		print ans