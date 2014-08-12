# !/usr/bin/env/ python

# given two sorted int array A and B of size m and n respectively, find median value of the two arrays. run inplace and time complexity should be in O(m+n)

import sys, unittest

class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        m, n = len(A), len(B)
        if m==0 and n==0:
            return 0.0
        if (m+n) & 1:
            mid = (m+n) >> 1
            return self.find(A, B, mid)
        else:
            r = (m+n) >> 1
            l = r -1
            return (self.find(A, B, l) + self.find(A, B, r))/2.0

    # @param th, the nth element to search in overall A and B  
    def find(self, A, B, th):
        m, n = len(A), len(B)
        if m == 0:
            return B[th]
        if n == 0:
            return A[th]
        mida, midb = (m-1) >> 1, (n-1) >> 1
        if A[mida] < B[midb]:    # enable lower median of A is greater than the one of B
            return self.find(B, A, th)
        if mida + 1 + midb + 1 <= th + 1:   # th is more, reduce to search in B's right half
            return self.find(A, B[midb+1:], th - (midb+1))
        else:             # half of A has excessive elements, reduce to search in A's left half
            return self.find(A[:mida], B, th)


class Test_us(unittest.TestCase):
    def test_01(self):
        s = Solution()
        self.assertEquals(s.findMedianSortedArrays([1,2,3], [4,5]), 3.0)
        self.assertEquals(s.findMedianSortedArrays([3,4,5], [1,2]), 3.0)
        self.assertEquals(s.findMedianSortedArrays([1,2], [0,3,4,5]), 2.5)
        self.assertEquals(s.findMedianSortedArrays([1,2,3], [4,5,6,7]), 4.0)
        self.assertEquals(s.findMedianSortedArrays([3], [1,2,4,5,8]), 3.5)
        self.assertEquals(s.findMedianSortedArrays([], [4,5]), 4.5)

if __name__ == '__main__':
    unittest.main()
