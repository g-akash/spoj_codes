import itertools
import operator
n = int(raw_input())
L = map(int,raw_input().split())
SL = sorted((x, i) for i, x in enumerate(L))
gp = itertools.groupby(SL, key=operator.itemgetter(0))
def a((i, it)):
    return len(list(it)), -L.index(i)
print max(gp, key=a)[0]