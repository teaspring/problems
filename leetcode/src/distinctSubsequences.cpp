/*
 * given a string S and string T, count the number of distinct subsequences of T in S(subsequence in S equals to T)
 * e.g. "ACE" is a subsequence of "ABCDE", while "AEC" is not
 * S = "rabbbit", T="rabbit", count is 3
 *
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
    * solution DP:
    * dp[i][j] means count of distinct subsequences of T.substr(0,i) in S.substr(0,j)
    * dp[i][j] = dp[i][j-1]      //count of distinct subsequences of T.substr(0,i) in S.substr(0,j-1)
    *          + dp[i-1][j-1]    //if T[i-1] == S[j-1]; dp[0][x] == 1
    *          + 0               //else
    * */
    int numDistinct_01(const string& S, const string& T){
        const int m = T.length(), n = S.length();
        if(m > n)    return 0;

        vector<vector<int> > dp(m+1, vector<int>(n+1, 0)); // int dp[m+1][n+1];
        for(int i = 0; i <= n; ++i){
            dp[0][i] = 1;
        }

        for(int j = 1; j <= n; ++j){
            for(int i = 1; i <= m; ++i){
                if(i > j)        break;
                dp[i][j] = dp[i][j-1] + (T[i-1] == S[j-1] ? dp[i-1][j-1] : 0);
            }
        }

        return dp[m][n];
    }

    /*
    * optimization, reduce space from O(m*n) to O(m)
    * */
    int numDistinct_02(const string& S, const string& T){
        const int m = T.length(), n = S.length();
        if(m > n)    return 0;

        vector<int> dp(m+1, 0); // int dp[m + 1];
        dp[0] = 1;

        for(int j = 1; j <= n; ++j){
            for(int i = m; i >= 1; --i){ // scan reversely
                if(i > j)        continue;
                dp[i] += (T[i-1] == S[j-1] ? dp[i-1] : 0); // existing dp[i] is dp[i][j-1], updated dp[i] is dp[i][j]
            }
        }
        return dp[m];
    }
};

/* unit test is in ../distinctSubsequences_unittest */
