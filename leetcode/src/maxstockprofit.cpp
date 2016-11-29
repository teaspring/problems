/*
 * Best Time to Buy and Sell Stock
 * Problem III: Given an array for which the ith element is the price of a given stock on day i. Find the maximum profit with at most two transactions
 *
 * Problem IV: find the maximum profit with at most k transactions
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

        int low = prices[0];
        for(int i=1; i < n; ++i){
            low = min(low, prices[i]);
            history[i] = max(history[i-1], prices[i] - low); // max profit for days [0, i] with 1 transaction, day i can sell out
        }

        int future[n];
        memset(future, 0, sizeof(future));

        int high = prices[n-1], sum = 0;
        for(int i = n-2; i >= 0; --i){
            high = max(high, prices[i]);
            future[i] = max(future[i+1], high - prices[i]); // max profit for days [i, n-1] with 1 transaction, day i can buy in

            sum = max(sum, history[i] + future[i]);
        }

        return sum;
    }

    /**
     * idea comes from solution to maxProfitIII. total time in O(n^3)...
     * */
    int maxProfitIV(int k, const vector<int>& prices) {
        int cnt = 0;
        int sum = getAllAvailableProfit(prices, cnt);
        if (k >= cnt) {
            return sum;
        }

        const int n = prices.size();
        int dp[k+1][n+1]; // dp[i][j] means max profit with i transactions mostly among prices[1...n]
        for(int i=0; i < k; ++i) {
            memset(dp[i], 0, sizeof(dp[i])); // note the meaning of sizeof(int[])
        }

        int low = prices[0];
        for(int i=1; i < n; ++i) {  // init dp[1][]
            low = min(low, prices[i]);
            dp[1][i+1] = max(dp[1][i], prices[i] - low);
        }

        int future[n];
        memset(future, 0, sizeof(future));

        int high = prices[n-1];
        for(int i = n-2; i >= 0; --i){
            high = max(high, prices[i]);
            future[i] = max(future[i+1], high - prices[i]); // max profit for days [i, n-1] with 1 transaction, day i can buy in
        }

        for(int i=2; i <= k; ++i) {
            for(int j=1; j <= n; ++j) {
                int sum = 0;
                for(int k = j-2; k >= 0; --k) {
                    sum = max(sum, dp[i-1][k] + future[k]);
                }
                dp[i][j] = sum;
            }
        }
        return dp[k][n];
    }

    /**
     * get maximum potential profit if all the available transactions are executed
     * */
    int getAllAvailableProfit(const vector<int>& prices, int& count) {
        count = 0;
        const int n = prices.size();
        if(n < 2)    return 0;

        int sum = 0;
        int lowIdx = -1, low = 0, high = 0;
        for(int i=1; i <= n; i++) {
            if (i == n || prices[i] < prices[i-1]) {  // decending or reach end
                if (lowIdx != -1) {
                    count++;
                    sum += high - low;
                    lowIdx = -1;
                }
            } else if(prices[i] > prices[i-1]){  // ascending
                if(lowIdx == -1) {
                    lowIdx = i-1;
                    low = prices[lowIdx];
                }
                high = prices[i];
            }
        }
        return sum;
    }
};

