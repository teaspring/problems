import unittest

def max_loss(stk_prices: list) -> int:
    ''' actuallt it is maximum drawdown'''
    peak = floor = res = 0
    prev = -1
    for v in stk_prices:
        if prev == -1 or (prev < v and peak < v):
            peak = v
            floor = 0
        elif prev > v and (floor == 0 or floor > v):
            floor = v
            res = max(res, peak - floor)
        prev = v
    return -res

def calcu_bp(numerator, denominator) -> int:
    # if delta * 10000 // denominator, it rounds down to int
    return round(numerator * 10000 / denominator)

# max drawdown(MDD) in basis point(0.01%)
def max_drawdown_bp(stk_prices: list) -> int:
    peak = 0.0  # global high
    trough = 0.0 # subsequent low after peak
    res = 0
    prev = -1
    for v in stk_prices:
        if prev == -1 or (prev < v and peak < v):
            peak = v
            trough = 0
        elif prev > v and (trough == 0 or trough > v):
            trough = v
            res = max(res, calcu_bp(peak - trough, peak))
        prev = v
    return -res

def max_drawdown_duration(stk_prices: list) -> int:
    peak = 0.0  # global high
    peak_idx = -1
    res = 0 # in days
    prev = -1.0
    in_dd = False # in drawdown
    for i in range(len(stk_prices)):
        v = stk_prices[i]
        if prev == -1 or (prev <= v and peak <= v):
            # in order to measure the duration, only narrow brim is accepted, so it is '<='
            if (in_dd):
                res = max(res, i - peak_idx)
            peak = v
            peak_idx = i
            in_dd = False
        elif prev > v or (in_dd and peak > v):
            res = max(res, i - peak_idx)
            in_dd = True
        prev = v
    return res

class TestStockExLoss(unittest.TestCase):
    # each test case must start with 'test_'
    def test_simple_int(self):
        prices = [3, 2, 4, 2, 1, 5]
        self.assertEqual(-3, max_loss(prices))
    
    def test_mdd_bp(self):
        prices = [10.12, 10.23, 10.91, 10.11, 9.61, 10.20, 10.98, 11.35, 11.81, 11.53, 10.91, 10.51, 10.76]
        self.assertEqual(-1192, max_drawdown_bp(prices)) # 10.91 -> 9.61

    def test_mdd_bp_no_down(self):
        prices = [9.0, 9.3, 9.6, 9.8, 10.2]
        self.assertEqual(0, max_drawdown_bp(prices))

    def test_mdd_dura_multi(self):
        prices = [10.1, 9.0, 9.3, 9.8, 10.2, 9.7, 9.6, 9.9]
        self.assertEqual(4, max_drawdown_duration(prices)) # 10.1 -> 10.2

    def test_mdd_dura_long(self):
        prices = [10.12, 10.23, 10.91, 10.11, 9.61, 10.20, 10.54, 10.81, 11.15, 11.41, 11.33, 10.91, 10.51, 10.76]
        self.assertEqual(6, max_drawdown_duration(prices)) # 10.91 -> 11.15

    def test_mdd_dura_flat_days(self):
        prices = [10.1, 10.1, 9.0, 9.3, 9.8, 10.1, 10.1, 10.2, 9.7, 9.6, 9.9]
        self.assertEqual(4, max_drawdown_duration(prices)) # 10.1[1] -> 10.1[5]

if __name__ == '__main__':
    unittest.main()