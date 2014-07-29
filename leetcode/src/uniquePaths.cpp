/*
 * given a matrix of m*n, for a robot, it needs to walk from left top corner [0,0] to right bottom corner [m-1,n-1]
 * find count of the distinct walkings
 *
 */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class UniquePaths{
public:
    int oncePath(int x, int y, int m, int n){   // recurse should be avoided here since it has too much redundancy
        if(x==m && y==n)    return 1;
        if(x>m || y>n)      return 0;
        return oncePath(x+1, y, m, n) + oncePath(x, y+1, m, n);
    }

    int uniquePaths_01(int m, int n){
        return oncePath(1, 1, m, n);
    }

    int uniquePaths_02(int m, int n){
        int dp[m][n];
        for(int i=0; i<m; ++i){
            dp[i][0] = 1;
        }
        for(int j=0; j<n; ++j){
            dp[0][j] = 1;
        }

        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

};

int main(int, char**){
    UniquePaths *up = new UniquePaths();
    printf("%d\n", up->uniquePaths_02(3, 3));
    delete up;
    up = 0;
    return 0;
}
