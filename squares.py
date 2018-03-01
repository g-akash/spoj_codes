t = int(raw_input())

while t>0:
	t-=1
	n = int(raw_input())
	a = n*n+2*n+1
	b = n*(n+1)
	c = b*(2*n+1)
	d = b*b
	e = (2*n+2)
	num = (a*b)/2+d/4-(e*c)/6
	den = (a*n)+c/6-(e*b)/2
	print num/den