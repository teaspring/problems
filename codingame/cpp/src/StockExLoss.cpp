/*
* Input
N stock values arranged in order of trading days.
The values are integers.

Output
The maximal loss p, expressed negatively if there is a loss, otherwise 0.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    public:
    int process1(int* stock_vals, int n)
    {
        int peak = 0, floor = 0, res = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            int v = stock_vals[i];
            if (prev == -1 || (prev < v && peak < v))
            {
                peak = v;
                floor = 0;
            } else if (prev > v && (floor == 0 || floor > v))
            {
                floor = v;
                res = max(res, peak - floor);
            }
            prev = v;
        }
        return 0 - res;
    }
};