/*
 * given a grid m*n, every cell has value, find a path from left upper [0,0] to right down [m-1, n-1] with minimum sum
 * 
 */
#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class minPathSums{
public:
    int minPathSum(vector<vector<int> >& grid){   // typical DP
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for(int i=1; i<m; ++i){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j=1; j<n; ++j){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(int i=1; i<m; ++i){
            for(int j=1; j<m; ++j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    return 0;
}
