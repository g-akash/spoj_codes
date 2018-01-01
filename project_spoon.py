facs = [1]
mul = 2
curr = 1
for i in range(1,72):
	facs.append(curr)
	curr*=mul
	mul += 1

#print facs

res = [1]
for i in range(1,72):
	a = i/2
	b = i-(i/2)
	res.append(facs[i]/(facs[a]*facs[b]))


t = int(raw_input())
for i in range(t):
	x = int(raw_input())
	for j in range(72):
		#print "res ",res[j],j
		if res[j]>=x:
			#print res[j]
			print j
			break
