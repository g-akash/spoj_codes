t = int(raw_input())
for i in range(t):
	var = raw_input()
	x,n = map(int,var.split())
	cards = x;
	while cards>=n:
		new_cards = cards%n+cards/n;
		x+=cards/n;
		cards = new_cards
	print x