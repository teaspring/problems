import unittest

def max_loss(prices: list) -> int:
    peak = floor = res = 0
    prev = -1
    for v in prices:
        if prev == -1 or (prev < v and peak < v):
            peak = v
            floor = 0
        elif prev > v and (floor == 0 or floor > v):
            floor = v
            res = max(res, peak - floor)
        prev = v
    return -res

class TestStockExLoss(unittest.TestCase):
    def test_positive_1(self):
        prices = [3, 2, 4, 2, 1, 5]
        self.assertEqual(max_loss(prices), -3)

    def test_positive_2(self):
        prices = [3, 2, 10, 7, 15, 14]
        self.assertEqual(max_loss(prices), -3)
    
    def test_negative_1(self):
        prices = [3, 4, 7, 9, 10]
        self.assertEqual(max_loss(prices), 0)

if __name__ == '__main__':
    unittest.main()