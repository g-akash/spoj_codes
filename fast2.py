num = 1298074214633706835075030044377087

t = int(raw_input())



def get_power(a,b):
	ans = 1
	var = a
	while (b!=0):
		if b%2==1:
			ans = ans*var
			ans = ans % num
		var = var*var
		var = var % num
		b/=2
	return ans


for i in range(t):
	n = int(raw_input())

	ans = get_power(2,n+1) - 1
	#print ans
	if ans < 0:
		ans+=num
	print ans