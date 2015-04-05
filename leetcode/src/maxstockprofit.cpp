/*
 * Best Time to Buy and Sell Stock
 * III.Given an array for which the ith element is the price of a given stock on day i. Find the maximum profit with at most two transactions
 * test data: 
 * gas{1,2,3,4,5}, cost{3,4,5,1,2}
 * */
#include "../include/preliminary.h"

using namespace std;

class Solution{

public:
    int maxProfitIII(const vector<int> &prices){
        const int n = prices.size();
        if(n < 2)    return 0;

        int history[n];
        memset(history, 0, sizeof(history));
        int future[n];
        memset(future, 0, sizeof(future));

        int valley = prices[0];
        for(int i = 1;i < n; ++i){
            valley = min(valley, prices[i]);

            history[i] = max(history[i-1], prices[i] - valley); // max profit for days [0, i]
        }

        int peak = prices[n-1], sum = 0;
        for(int i = n-2;i >= 0; --i){
            peak = max(peak, prices[i]);
            future[i] = max(future[i+1], peak - prices[i]); // max profit for days [i, n-1]

            sum = max(sum, history[i] + future[i]);
        }

        return sum;
    }
};

