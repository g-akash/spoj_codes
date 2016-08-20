t=input();
t=int(t)
for i in range(0,t):
	a=raw_input();
	if a.strip() == '':
		a=raw_input();
	a=a.split();
	x=int(a[0])
	y=int(a[1])
	if(x%2==0 and y%2==0):
		print x*y/2
	if(x%2!=0 and y%2==0):
		print y*(x/2+1)
	if(x%2==0 and y%2!=0):
		print x*(y/2+1)
	if(x%2!=0 and y%2!=0):
		v1=x*(y/2+1)
		v2=y*(x/2+1)
		if(v1>v2):
			print v1;
		if(v2>=v1):
			print v2;