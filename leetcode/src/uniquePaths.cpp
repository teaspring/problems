/*
 * given a matrix of m*n, for a robot, it needs to walk from left top corner to right bottom corner
 * find count of the distinct walkings
 */

#include <cstring>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     * recurse. this solution time complexity is bad
     * */
    int uniquePaths_01(int m, int n){
        return onePath(1, 1, m, n);
    }

    /*
     * DP
     * */
    int uniquePaths_02(const int m, const int n){
        vector<vector<int> > dp(m, vector<int>(n, 0)); // int dp[m][n]

        for(int i = 0; i < m; ++i){
            dp[i][0] = 1;
        }

        for(int j = 0; j < n; ++j){
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }

private:
    /*
     * used by solution 1
     * */
    int onePath(int x, int y, int m, int n){
        if(x > m || y > n)    return 0;  // necessary clause

        if(x == m && y == n)    return 1;

        return onePath(x+1, y, m, n) + onePath(x, y+1, m, n);
    }
};

/* unit test is in ../cpp_unittest/uniquePaths_unittest */
