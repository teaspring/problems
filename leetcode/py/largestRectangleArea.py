# !/usr/bin/env python
# -*- coding: utf-8 -*-

# how to execute: >>> python -m unittest largestRectangleArea

import sys, unittest

class Solution:
    # @param height, a list of integer
    # @return an integer
    def largestRA(self, height):
        n = len(height)
        if n == 0:
            return 0
        stk = []
        res = 0
        for i in range(n+1):
            if i == n:
                h = 0
            else:
                h = height[i]
            while len(stk) != 0:
                p = stk[-1]
                if height[p] < h:
                    break
                stk.pop()
                if len(stk) == 0:
                   s = -1
                else:
                   s = stk[-1]
                curr = (i - 1 - s) * height[p]
                if res < curr:
                    res = curr
            stk.append(i)
        return res

# Not in need now: from largestRectangleArea import Solution

class TestLRA(unittest.TestCase):
    def test_execute(self):  # each test case must be named as text_xxx
        s = Solution()
        a = s.largestRA([2,1,3,1,4,2])
        self.assertEquals(a, 6)

        a = s.largestRA([2,1,5,6,2,3])
        self.assertEquals(a, 10)

        a = s.largestRA([0,0,0,0,0,0,11])
        self.assertEquals(a, 11)

if __name__ == '__main__':
    unittest.main()
