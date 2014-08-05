import unittest
# how to execute: >>> python -m unittest largestRectangleArea_unittest

from largestRectangleArea import Solution

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
