import functools

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
