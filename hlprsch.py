l = int(raw_input())
m = int(raw_input())
t = int(raw_input())
n = int(raw_input())
z = int(raw_input())


l-=m

while z>=t:
	m2 = m+l
	l2 = m*n
	m = m2
	l = l2


	z-=t


print m+l