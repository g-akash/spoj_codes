n = int(raw_input())

ans = 1
var = 1

for i in range(1,n+1):
	var*=i;
	ans*=var;
	ans%=109546051211
	var%=109546051211

print ans