/*
 * BeanMan game: moving in a M*N matrix and eat bean on each cell if it is there
 * Problem I : one man, only downward and rightward, maximum score
 * Problem II: two men, only downward and rightward, maximum score sum
 * */

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

    /*
     * problem II, we use dp[][][][] ?!
     * */
    int beanManII(const vector<vector<int> >& pool){
        if(pool.empty())    return 0;

        const int n = pool.size();
        const int m = pool[0].size();

        int dp[n][m][n][m];
        memset(dp, 0, sizeof(dp));

        dp[0][0][0][0] = pool[0][0];

        for(int i = 1; i < n; i++){
            dp[i][0][0][0] = dp[i-1][0][0][0] + pool[i][0]; // beanMan A scores from [0][0] to [i][0]
            dp[0][0][i][0] = dp[i][0][0][0]; // either beanMan B move this path
            dp[i][0][i][0] = dp[i][0][0][0]; // or both A and B together, as the path is only one, the max score has no change
        }

        for(int j = 1; j < m; j++){
            dp[0][j][0][0] = dp[0][j-1][0][0] + pool[0][j];
            dp[0][0][0][j] = dp[0][j][0][0];
            dp[0][j][0][j] = dp[0][j][0][0]; // same to above
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][0][0][j] = dp[i][0][0][0] + dp[0][0][0][j];
                dp[0][j][i][0] = dp[i][0][0][j]; // beanMan A and B runs on two edge paths

                dp[i][j][0][0] = max(dp[i-1][j][0][0], dp[i][j-1][0][0]) + pool[i][j];
                dp[0][0][i][j] = dp[i][j][0][0];
            }
        }

        /*
         * above process is for single bean man max score
         *
         * idea 1:
         * dp[i][j][i][j] = dp[i][j-1][i-1][j] + pool[i][j], this value has no option
         * and dp[i][j-1][i-1][j] needs be set ahead of it
         *
         * */
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][0][0][j] = dp[i][0][0][0] + dp[0][0][0][j] - pool[0][0];
                dp[0][j][i][0] = dp[i][0][0][j];
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                // how to set dp[i][j-1][i-1][j] ?
                int tmp =  pool[i-1][j] + pool[i][j-1];

                int leftmid   = j > 1 ? dp[i][j-2][i-1][j-1] : 0;
                int midupper  = i > 1 ? dp[i-1][j-1][i-2][j] : 0;
                int leftupper = (i > 1 && j > 1) ? dp[i][j-2][i-2][j] : 0;
                int midmid    = dp[i-1][j-1][i-1][j-1];
                tmp += max(max(leftmid, max(midupper, leftupper)), midmid);

                dp[i][j-1][i-1][j] = tmp;

                // definitely dp[i][j-1][i-1][j] >= max(dp[i-1][j][i-1][j], dp[i][j-1][i][j-1])
                dp[i][j][i][j] = dp[i][j-1][i-1][j] + pool[i][j];
                dp[i][j][i-1][j] = dp[i][j][i][j];
            }
        }

        return dp[n-1][m-1][n-1][m-1];
    }
};

/* unit test is in ../unittest/beanMan_unittest */
