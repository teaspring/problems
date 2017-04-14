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

        vector<int> history(n, 0);
        int low = prices[0];
        for(int i=1; i < n; ++i){
            low = min(low, prices[i]);
            history[i] = max(history[i-1], prices[i] - low); // max profit for days [0, i] with 1 transaction, day i can sell out
        }

        vector<int> future(n, 0);
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
     * this solution is judged on oj.leetcode.com for 'Runtime Error' with a very large prices[] arg...
     * */
    int maxProfitIV_01(int k, const vector<int>& prices) {
        int cnt = 0;
        int sum = getAllProfit(prices, cnt);
        if (k >= cnt)    return sum;

        const int n = prices.size();
        vector<vector<int> > dp(k+1, vector<int>(n+1, 0)); // int dp[k+1][n+1] dp[i][j] means max profit among days[1...n] with i transactions mostly

        int low = prices[0];
        for(int i=1; i < n; ++i) {  // init dp[1][]
            low = min(low, prices[i]);
            dp[1][i+1] = max(dp[1][i], prices[i] - low);
        }

        vector<vector<int> > future(n, vector<int>(n+1, 0)); // int future[n][n+1] means max profit among days[i...j] with 1 transaction

        for(int j = 2; j <= n; j++) {
            int high = prices[j-1];
            for(int i = j-2; i >= 0; --i){
                high = max(high, prices[i]);
                future[i][j] = max(future[i+1][j], high - prices[i]);
            }
        }

        for(int i=2; i <= k; ++i) {
            for(int j=1; j <= n; ++j) {
                int sum = 0;
                for(int k = j-2; k >= 0; --k) { // k is just iterator
                    sum = max(sum, dp[i-1][k] + future[k][j]);
                }
                dp[i][j] = sum;
            }
        }
        return dp[k][n];
    }

    /*
     * from discuss on leetcode.com. very clever!
     * tmpMax is an awesome var
     * */
    int maxProfitIV_02(int k, const vector<int>& prices) {
        int cnt = 0;
        int sum = getAllProfit(prices, cnt);
        if (k >= cnt)    return sum;

        const int n = prices.size();
        vector<vector<int> > dp(k+1, vector<int>(n, 0)); // int dp[k+1][n] means max profit of mostly i-1 transactions among prices[0...j-1]

        for(int i=1; i <= k; i++) {
            int tmpMax = 0 - prices[0]; // tmpMax means max profit of mostly i-1 transactions among prices[0...j-1], and buy at prices[j] to be ready for later
            for(int j=1; j < n; j++) {
                dp[i][j] = max(dp[i][j-1], prices[j] + tmpMax); // dp[i][j] is based on dp[i][j-1]
                tmpMax = max(tmpMax, dp[i-1][j-1] - prices[j]);
            }
        }
        return dp[k][n-1];
    }

    /**
     * get total profit if all the available transactions are executed
     * Two output: total profit, and minimum transaction count;
     * */
    int getAllProfit(const vector<int>& prices, int& count) {
        count = 0;
        const int n = prices.size();
        if(n < 2)    return 0;

        int sum = 0, lowIdx = -1;
        for(int i=1; i <= n; i++) {
            if (i == n || prices[i] < prices[i-1]) {  // decending or reach end
                if (lowIdx != -1) {
                    count++;
                    lowIdx = -1;
                }
            } else if(prices[i] > prices[i-1]){  // ascending
                if(lowIdx == -1) {
                    lowIdx = i-1;
                }
                sum += prices[i] - prices[i-1]; // if prices[i] > [i-1], this step counts for total profit
            }
        }
        return sum;
    }
};

