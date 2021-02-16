# -*- coding:utf-8 -*-

import os, sys

def perm(items: [], n: int):
    ''' 实现列表排列: 原地递归, 返回迭代器
    '''
    if n <= 0:
        n = len(items)
    for i in range(len(items)):
        v = items[i:i+1]
        if n == 1:
            yield v  # v is []
        else:
            rest = items[:i] + items[i+1:]  # rest always has n-1 elements
            for p in perm(rest, n-1):
                yield v + p

def comb(items: [], n: int):
    ''' 实现列表组合: 原地递归, 返回迭代器
    '''
    if n <= 0:
        n = len(items)
    for i in range(len(items)):
        v = items[i:i+1]
        if n == 1:
            yield v  # v is []
        else:
            rest = items[i+1:]
            for c in comb(rest, n-1):
                yield v + c


if __name__ == '__main__':
    n, m = 4, 3
    items = list(range(0,n))

    # test case 1: permutation
    res = perm(items, m)
    print('--------permutation of P({},{}) is:'.format(n, m))
    for p in res:
        print(p)

    # test case 2: combination
    res = comb(items, m)
    print('--------combination of C({},{}) is:'.format(n, m))
    for c in res:
        print(c)
