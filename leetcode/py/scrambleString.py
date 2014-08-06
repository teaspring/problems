# scramble string
# given a string s1, represent it as a binary tree by partitioning it to two non-empty substrings recursively
# to scramble a string, we choose any non-leaf node and swap its two children
# for s1 = "great"
# s2 = "terag" yes
# s2 = "agtre" false

import sys, unittest

class Solution:
    def isScramble(self, s1, s2):
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
        if sorted(s1) != sorted(s2):    # s1.sort() is in-place
            return False
        for i in range(len(s1))[1:]:
            if self.isScramble(s1[0:i], s2[0:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            if self.isScramble(s1[0:i], s2[-i:]) and self.isScramble(s1[-i:], s2[0:i]):
                return True
        return False

# unit test
class TestSS(unittest.TestCase):
    def test_execute(self):
        s = Solution()
        self.assertTrue(s.isScramble('great', 'terag'))
        self.assertFalse(s.isScramble('abcdefghijklmn', 'efghijklmncadb'))

if __name__ == '__main__':
    unittest.main()
