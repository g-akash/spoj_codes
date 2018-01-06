t = int(raw_input())
for y in range(t):
	nq = map(int,raw_input().split())
	d = map(int,raw_input().split())
	val = 1
	for var in d:
		val = val*var
	x = map(int,raw_input().split())
	for j in range(len(x)):
		print x[j]/val,
	print ""