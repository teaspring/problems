# permutation and combination

import os, sys

# generate permutation
def perm(items, n=None):
    if n is None:
        n = len(items)
    for i in range(len(items)):
        v = items[i:i+1]
        if n == 1:
            yield v
        else:
            rest = items[:i] + items[i+1:]    # lower recursion of permutation
            for p in perm(rest, n-1):
                yield v + p

def comb(items, n=None):
    if n is None:
        n = len(items)
    for i in range(len(items)):
        v = items[i:i+1]
        if n == 1:
            yield v
        else:
            rest = items[i+1:]    # lower recursion of combination
            for c in comb(rest, n-1):
                yield v + c

# main function
if len(sys.argv) < 2:
    items = '1234'
else:
    items = sys.argv[1]

if len(sys.argv) < 3:
    n = None
else:
    n = int(sys.argv[2])

ps = perm(items, n)
print 'permutation:'
for p in ps:
    print p
print '-'*20

cs = comb(items, n)
print 'combination:'
for c in cs:
    print c

