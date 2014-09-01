# !/usr/bin/env python

# given an array with n objects colored red(0), white(1) and blue(2). sort them so that objects of same color are adjacent, with colors in red, white and red

import sys, unittest

class Solution:
    # @param A a list of integers 0,1,2 to represent red, white and blue
    # @return nothing, sort in place
    def sortColor(self, A):
        n = len(A)
        if n == 0:
            return
        p,q,t = -1, 0, n
        while q < t:
            if A[q] == 2:
                t -= 1
                A[q], A[t] = A[t], A[q]
                continue
            elif A[q] == 0:
                p += 1
                A[q], A[p] = A[p], A[q]
            q += 1
        return

class TestSortColor(unittest.TestCase):
    def test_01(self):
        s = Solution()
        A = [1,0,2,0,0,2,1,1,0]
        s.sortColor(A)
        p = A[0]
        for q in A[1:]:
            self.assertTrue(p <= q)
            p = q

if __name__ == '__main__':
    unittest.main()
