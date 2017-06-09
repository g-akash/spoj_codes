n = int(raw_input())
ls = map(int,raw_input().split())
ln = len(ls)
osum = [-1]*ln
esum = [-1]*ln

def get_sum(x,typ):
	global ln
	global ls
	if x>=ln:
		return 0

	if typ=="even":
		if esum[x]>=0:
			return esum[x]

		tmp1 = get_sum(x+1,"even")
		tmp2 = 0
		if ls[x]%2==0:
			tmp2 = ls[x]+get_sum(x+1,"odd")
		tmp1 = max(tmp1,tmp2)
		esum[x]=tmp1
		return tmp1
	elif typ == "odd":
		if osum[x]>=0:
			return osum[x]

		tmp1 = get_sum(x+1,"odd")
		tmp2 = 0
		if ls[x]%2==1:
			tmp2 = ls[x]+get_sum(x+1,"even")
		tmp1 = max(tmp1,tmp2)
		esum[x]=tmp1
		return tmp1

ans = max(get_sum(0,"even"),get_sum(0,"odd"))
print ans