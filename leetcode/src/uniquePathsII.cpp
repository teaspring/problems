/*
 * folloing uniquePaths
 * currently the matrix has some obstracle in cells. '1' for obstacle and '0' for pass.
 */
#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class UniquePathsII{
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
        int m = obstacleGrid.size();
        if(m == 0)    return 0;
        int n = obstacleGrid[0].size();
        if(n == 0)    return 0;
        int dp[m][n];
        for(int i=0; i<m; ++i){
            bool cannot = obstacleGrid[i][0] == 1 || (i>0 && dp[i-1][0] == 0);
            dp[i][0] = cannot ? 0 : 1;
        }
        for(int j=0; j<n; ++j){
            bool cannot = obstacleGrid[0][j] == 1 || (j>0 && dp[0][j-1] == 0);
            dp[0][j] = cannot ? 0 : 1;
        }
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                dp[i][j] = 
                    obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

};

int main(int, char**){
    return 0;
}
