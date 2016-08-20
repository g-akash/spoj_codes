import sys
stri= sys.stdin.read()
a=stri.split('\n')
for i in range(0,len(a)):
	print 2*int(a[i])-2
#stri= sys.stdin.read()