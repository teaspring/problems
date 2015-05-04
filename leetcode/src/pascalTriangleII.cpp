/*
 * given an index k, return kth row of Pascal's triangle.
 * e.g, given k=3, return: 1,3,3,1
 * */
#include <vector>
#include <cstring>

using namespace std;

class Solution{

public:
    /*
     *
     * */
    vector<int> getRow(int k){  // k is 0-based row index, with k+1 elements in row
        vector<int> res;
        if(k < 0)    return res;

        int dp[2][k+1];
        memset(dp, 0, sizeof(dp));

        int last = 0;
        dp[last][0] = 1;

        for(int i = 1; i <= k; i++){
            int now = 1 - last;
            memset(dp[now], 0, sizeof(dp[now]));

            dp[now][0] = dp[last][0];
            for(int j = 1; j < i; ++j){
                dp[now][j] = dp[last][j-1] + dp[last][j];
            }

            dp[now][i] = dp[last][i-1];
            last = now;
        }

        for(int i = 0; i <= k; i++){
            res.push_back(dp[last][i]);
        }

        return res;
    }
};

/* unit test is in ../cpp_unittest/pascalTriangleII_unittest */
