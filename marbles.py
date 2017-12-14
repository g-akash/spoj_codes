facs = []
invs = []

num = 12764787846358441471
#print num

def calc_facs():
	global facs
	facs = [0]*1000005
	facs[0]=1
	for i in range(1,1000005):
		facs[i]=(facs[i-1]*i)%num
	return


def mp(x,y):
	ans = 1
	var = x
	for i in range(70):
		#print ans,var
		if y==0:
			break
		if y%2==1:
			ans = ans * var
		ans = ans % num
		var = var * var
		var = var % num
		y = y/2
	return ans

def calc_invs():
	global invs
	invs = [0]*1000005
	for i in range(1000005):
		invs[i]=mp(facs[i],num-2)
	return

#mp(2,num-2)

calc_facs()
#calc_invs()
#print "done"
#print invs[0:20]
#print facs[0:20]

#print facs[9],invs[9],invs[9]

t = int(raw_input())
for i in range(t):
	line = map(long,raw_input().split())
	n = line[0]-1
	r = line[1]-1
	x = n-r
	print (((facs[n]*mp(facs[r],num-2))%num)*mp(facs[x],num-2))%num
