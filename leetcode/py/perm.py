# !/usr/bin/env python
# -*- coding:utf-8 -*-

# permutation and combination

import os, sys
from copy import copy

# generate permutation
def perm(items, n=None):
    if n is None:
        n = len(items)
    for i in range(len(items)):
        v = items[i:i+1]
        if n == 1:
            yield v
        else:
            rest = items[:i] + items[i+1:]  # rest always has n-1 elements
            for p in perm(rest, n-1):       # recurse
                yield v + p

def swaplist(A, i, j):
    if len(A) <= i or len(A) <= j or i==j:
        return
    tmp = A[i]
    A[i] = A[j]
    A[j] = tmp

# recurse for C++ style
def perm_02(items):
    res = []
    res.append(copy(items))   # initial status must be processed precedingly
    recur(items, 0, len(items), res)
    return res

def recur(items, start, end, res):
    if start >= end:
        return
    recur(items, start+1, end, res)
    for i in range(start+1, end):
        swaplist(items, start, i)
        res.append(copy(items))    # shallow copy
        recur(items, start+1, end, res)
        swaplist(items, start, i)

def comb(items, n=None):
    if n is None:
        n = len(items)
    for i in range(len(items)):
        v = items[i:i+1]
        if n == 1:
            yield v
        else:
            rest = items[i+1:]    # if rest has no element, following code will not yield any more
            for c in comb(rest, n-1):
                yield v + c

def test_01():
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

def test_02():
    res = perm_02(range(4))
    for p in res:
        print p
    print len(res)

if __name__ == '__main__':
    # test_01()
    test_02()
