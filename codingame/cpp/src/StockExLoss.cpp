/*
* Input
N stock values arranged in order of trading days.
The values are integers.

Output
The maximal loss p, expressed negatively if there is a loss, otherwise 0.
*/

#include <iostream>
#include <algorithm>
#include <cmath> // fabs()
#include <cfloat>
using namespace std;

class Solution
{
    public:
    // return absolute value of maximal loss
    int max_loss_abs(int* stock_prices, int n)
    {
        int peak = 0; // global high
        int trough = 0;
        int res = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            int v = stock_prices[i];
            if (prev == -1 || (prev < v && peak < v))
            {
                peak = v;
                trough = 0;
            } else if (prev > v && (trough == 0 || trough > v))
            {
                trough = v;
                res = max(res, peak - trough);
            }
            prev = v;
        }
        return 0 - res;
    }
    // maximal loss in base point(BP), or 0 if no loss; 1 BP is 0.01%
    // actually, it is equivalent to maximum drawdown(MDD)
    int max_drawdown_bp(float* stock_prices, int n)
    {
        float peak = 0.0f; // global high
        float trough = 0.0f; // subsequent low after peak
        int res = 0; // unit in BP which is 0.01%
        float prev = -1;
        for (int i = 0; i < n; i++) {
            float v = stock_prices[i];
            if (prev == -1 || (prev < v && peak < v))
            {
                peak = v;
                trough = 0;
            } else if (prev > v && (trough == 0 || trough > v))
            {
                trough = v;
                res = max(res, calcu_bp(peak, trough));
            }
            prev = v;
        }
        return 0 - res;

    }
    // maximal drawdown duration in days, or 0 if no loss
    int max_drawdown_duration(float* stock_prices, int n)
    {
        float peak = 0.0f; // global high
        float prev = -1.0f;
        int peak_idx = -1;
        int res = 0; // in days
        bool in_drawdown = false;
        for (int i = 0; i < n; i++) {
            float v = stock_prices[i];
            if (prev == -1
                || (is_float_lt_equal(prev, v) && is_float_lt_equal(peak, v)))
            {
                // in order to measure the duration, only narrow brim is accepted, so it is '<='
                if (in_drawdown)
                {
                    res = max(res, i - peak_idx); // end of drawdown duration!
                }
                // update for up trend
                peak = v;
                peak_idx = i;
                in_drawdown = false;
            } else if (prev > v || (in_drawdown && peak > v))
            {
                res = max(res, i - peak_idx);
                in_drawdown = true;
            }
            prev = v;
        }
        return res;
    }

    // accumulation of all the available profit in absolute value
    float total_profit_abs(float* stock_prices, int n)
    {
        float res = 0.0f;
        for (int i = 1; i < n; i++) {
            float diff = round_to_n_decimals(stock_prices[i] - stock_prices[i - 1], 2); // 0.01 precision
            if (diff > 0.0) res += diff;
        }
        return res;
    }

    private:
    // calculate loss in BP
    inline int calcu_bp(float peak, float trough)
    {
        // implicit convert float to int rounds down to 0
        // std::round() round to nearest integer
        return round((peak - trough) * 10000 / peak);
    }

    // round to given decimal precision
    float round_to_n_decimals(float value, int n) {
        double multiplier = std::pow(10.0, n);
        return std::round(value * multiplier) / multiplier;
    }

    // compare whether two floats are equal within an epsilon
    inline bool are_floats_equal(float a, float b, float epsilon = FLT_EPSILON) {
        return fabs(a - b) < epsilon;
    }

    // if a <= b
    bool is_float_lt_equal(float a, float b, float epsilon = FLT_EPSILON) {
        return ((b - a) > epsilon) || (fabs(a - b) < epsilon);
    }
};