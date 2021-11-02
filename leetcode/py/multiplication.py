# 实现乘法原理

import os, sys
from typing import List, Dict


def multiplication(groups_list: List[List], merge_func):
    ''' 实现乘法原理.
    对于[[a, b], [x, y]], 返回[[a,x], [a,y], [b,x], [b,y]]
    @param groups_list: 原始二维列表, 每一项是一个列表
    @param merge_func: method(), 用来操作两个数组切片
    '''
    if len(groups_list) == 1:
        for u in groups_list[0]:
            yield u
    else:
        for u in groups_list[0]:
            rest = groups_list[1:]
            for v in multiplication(rest, merge_func):
                yield merge_func(u, v)

def simple_ext(item, list: List):
    res = [item]
    res.extend(list)
    return res


if __name__ == '__main__':
    list_1 = [1, 2]
    list_2 = ['a', 'b']
    list_3 = ['甲', '乙']
    for x in multiplication([list_1, list_2, list_3], simple_ext):
        print(x)
