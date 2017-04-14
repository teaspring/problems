/*
 * given a grid m*n, every cell has value, find a path from left upper [0,0] to right down [m-1, n-1] with minimum sum
 * 
 */
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int> >& grid){   // typical DP
        const int m = grid.size();    // rows
        const int n = grid[0].size(); // cols

        vector<vector<int> > dp(m, vector<int>(n, 0)); // int dp[m][n]
        dp[0][0] = grid[0][0];

        for(int i = 1; i < m; ++i){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int j = 1; j < n; ++j){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};

/* unit test is in ../cpp_unittest/minPathSums_unittest */
