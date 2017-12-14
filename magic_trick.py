t = long(raw_input())
n = 0
vec = []
ml=1
ad=0
sd=0
st=0
ed=0
vals=0

def prnt():
	global sd,st,ed,vals,op,vec,ml,ad
	if sd==0:
		curr=st
		st+=1
	else:
		curr=ed
		ed-=1
	
	vec[curr]=vec[curr]*ml+ad
	vec[curr]%=vals[2]
	print vec[curr],


for test in range(t):
	n = long(raw_input())
	vec = map(long,raw_input().split())
	vals = map(long,raw_input().split())
	st=0
	ed=n-1
	sd=0
	ml=1
	ad=0
	x = raw_input()
	for j in range(len(x)):
		if x[j]=='R':
			sd = (sd+1)%2
			prnt()
		elif x[j]=='A':
			ad+=vals[0]
			ad%=vals[2]
			prnt()
		elif x[j]=='M':
			ml*=vals[1]
			ad*=vals[1]
			ml%=vals[2]
			ad%=vals[2]
			prnt()
			

	print ""

