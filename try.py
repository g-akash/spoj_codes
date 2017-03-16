s=0
for i in range(0,892):
	s=s*10+1;
print s;
s=s*s;
ans=0;
while s!=0:
	ans=ans+s%10;
	s=s/10;

print ans;