# !/usr/bin/env python
# -*- coding: utf-8 -*-

# how to run: $python -m unittest xxx[.py]

import sys, unittest

class Solution:
    # @param heights, a list of integer
    # @return integer value of max rectangle area
    def largestRectangle(self, heights):
        res, n = 0, len(heights)
        if n == 0:
            return res
        stk = []  # stk is list used as stack to save index
        for i in range(n+1):
            if i == n:
                h = 0
            else:
                h = heights[i]
            while len(stk) != 0:
                p = stk[-1]
                if heights[p] < h:
                    break
                stk.pop()
                if len(stk) == 0:
                    s = -1
                else:
                    s = stk[-1]
                res = max(res, (i - s - 1) * heights[p])
            stk.append(i)
        return res

    # @param matrix, list as a 2D matrix of 0 and 1
    # @return integer which is area of largest rectangle of all 1in 2D martix
    def largestRectangle2D(self, matrix):
        res, n = 0, len(matrix)
        if n==0:
            return res
        histogram = map(lambda x: int(x), matrix[0])    # map process !!
        res = self.largestRectangle(histogram)
        for arr in matrix[1:]:
            for i in range(len(arr)):
                if arr[i] == '0':
                    histogram[i] = 0
                else:
                    histogram[i] += 1
            res = max(res, self.largestRectangle(histogram))
        return res

class TestLRA(unittest.TestCase):
    def test_largestRec(self):
        s = Solution()
        self.assertEquals(s.largestRectangle([2,1,3,1,4,2]), 6)
        self.assertEquals(s.largestRectangle([2,1,5,6,2,3]), 10)
        self.assertEquals(s.largestRectangle([0,0,0,0,0,0,0,11]), 11)

    def test_maxRectangle2D(self):
        s = Solution()
        self.assertEquals(
        s.largestRectangle2D([['1','0','1','1','0','0','1'],
                              ['0','1','1','1','1','0','0'],
                              ['0','1','1','1','0','1','1']]), 6)

if __name__ == '__main__':
    unittest.main()
