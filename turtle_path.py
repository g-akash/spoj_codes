n = map(int,raw_input().split())
m=n[1]
n=n[0]
sq = [[]]*n
ans = [[-1 for x in range(m)] for y in range(n)] 
for i in range(n):
	x = map(int,raw_input().split())
	sq[i]=x
#print sq
ans[0][0]=1
prims = [0]*100050
for i in range(2,100050):
	if prims[i]==1:
		continue
	for j in range(2*i,100050,i):
		prims[j]=1


def calc(x,y):
	global ans
	# print x,y
	# print "start"
	# for i in range(len(ans)):
	# 	print ans[i]
	if x<0 or y<0:
		return 0
	if ans[x][y]>=0:
		return ans[x][y]
	if prims[sq[x][y]]==1:
		ans[x][y]=0
		return 0

	tmp = calc(x-1,y)+calc(x,y-1)+calc(x-1,y-1)
	ans[x][y]=tmp%1000000007
	# print "end"
	# for i in range(len(ans)):
	# 	print ans[i]
	return ans[x][y]

def get_path(x,y):
	print x+1,y+1
	a = str(x)
	b = str(x+1)
	c = str(y)
	d = str(y+1)
	if b+d>b+c and b+c > a+d:
		if x+1<m and y+1<n:
			if ans[x+1][y+1]>0:
				get_path(x+1,y+1)
				return
		if x+1 <m:
			if ans[x+1][y]>0:
				get_path(x+1,y)
				return
		if y+1<n:
			get_path(x,y+1)
			return


	if b+d>a+d and a+d > b+c:
		if x+1<m and y+1<n:
			if ans[x+1][y+1]>0:
				get_path(x+1,y+1)
				return

		if y+1<n:
			get_path(x,y+1)
			return

		if x+1 <m:
			if ans[x+1][y]>0:
				get_path(x+1,y)
				return

	if b+c>b+d and b+d > a+d:

		if x+1 <m:
			if ans[x+1][y]>0:
				get_path(x+1,y)
				return

		if x+1<m and y+1<n:
			if ans[x+1][y+1]>0:
				get_path(x+1,y+1)
				return


		if y+1<n:
			get_path(x,y+1)
			return

	if b+c>a+d and a+d > b+d:

		if x+1 <m:
			if ans[x+1][y]>0:
				get_path(x+1,y)
				return



		if y+1<n:
			get_path(x,y+1)
			return

		if x+1<m and y+1<n:
			if ans[x+1][y+1]>0:
				get_path(x+1,y+1)
				return


	if a+d>b+c and b+c > b+d:

		if y+1<n:
			get_path(x,y+1)
			return

		if x+1 <m:
			if ans[x+1][y]>0:
				get_path(x+1,y)
				return

		if x+1<m and y+1<n:
			if ans[x+1][y+1]>0:
				get_path(x+1,y+1)
				return


	if a+d>b+d and b+d > b+c:

		if y+1<n:
			get_path(x,y+1)
			return


		if x+1<m and y+1<n:
			if ans[x+1][y+1]>0:
				get_path(x+1,y+1)
				return


		if x+1 <m:
			if ans[x+1][y]>0:
				get_path(x+1,y)
				return



fin_ans = calc(n-1,m-1)
fin_ans = max(0,fin_ans)
print fin_ans
if fin_ans > 0:
	get_path(0,0)
#print prims[:20]
#print ans