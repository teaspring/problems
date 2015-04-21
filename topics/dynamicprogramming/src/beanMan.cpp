/*
* BeanMan game: moving in a M*N matrix and try to eat the maximum beans
* Problem I : one man, only downward and rightward
* Problem II: two men, only downward and rightward
*/

#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

class Solution{

public:
    /*
     * porblem I, classic DP
     * */
    int beanMan(const vector<vector<int> >& pool){
        if(pool.empty())    return 0;

        const int n = pool.size();
        const int m = pool[0].size();

        int dp[n][m];
        memset(dp, 0, sizeof(dp));
    
        dp[0][0] = pool[0][0];

        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0] + pool[i][0];
        }

        for(int j = 1; j < m; j++){
            dp[0][j] = dp[0][j-1] + pool[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + pool[i][j];
            }
        }

        return dp[n-1][m-1];
    }
};

/* unit test is in ../unittest/beanMan_unittest */
