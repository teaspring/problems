/*
 * on a m*n board, find all unique paths from left upper corner to right bottom corner
 * where '1' for obstacle and '0' for pass.
 */

#include <cstring>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     *
     * */
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
        if(obstacleGrid.empty())    return 0;
        const int m = obstacleGrid.size();

        if(obstacleGrid[0].empty())    return 0;
        const int n = obstacleGrid[0].size();

        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < m; ++i){
            bool cannot =
                obstacleGrid[i][0] == 1 || (i > 0 && dp[i-1][0] == 0);

            dp[i][0] = cannot ? 0 : 1;
        }

        for(int j = 1; j < n; ++j){  // skip dp[0][0]
            bool cannot =
                obstacleGrid[0][j] == 1 || (j > 0 && dp[0][j-1] == 0);

            dp[0][j] = cannot ? 0 : 1;
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = 
                    obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

/* unit test is in ../cpp_unittest/uniquePathsII_unittest */
