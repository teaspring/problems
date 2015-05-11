/*
 * given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * 2
 * 3,4
 * 6,5,7
 * 4,1,8,3
 * the answer is 2+3+5+1
 * */
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution{

public:
    /*
     * permutation of all the indice, inefficient causing Time Limit Exceed
     * */
    int minTotal_01(vector<vector<int> >& triangle){
        const int n = triangle.size();

        int indice[n];  // start from {0,0,0,0...} the most left path
        memset(indice, 0, sizeof(indice));

        int res = sumPath(triangle, indice);

        while(1){
            int i = n-1;

            while(i > 0){
                if(indice[i] == indice[i-1]){
                    indice[i]++;
                    break;
                }

                --i;
            }

            if(i == 0)    break;

            int k = indice[i];

            for(int j = i+1; j < n; j++){ // take care the permutation, reset the following integers eqaul to indice[i]
                indice[j] = k;
            }

            res = min(res, sumPath(triangle, indice));
        }

        return res;
    }

    /*
     * correct answer from others, using DP.
     * in row [i] for column [j], dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j])
     * it means current row is just dependent on last row. so define a 2*n matrix for DP
     * */
    int minTotal_02(vector<vector<int> >& tri){
        const int n = tri.size();

        int dp[2][n];
        memset(dp, 0, sizeof(dp));

        int last = 0;
        dp[0][0] = tri[0][0];

        for(int i = 1; i < n; ++i){ // row [i] has i+1 elements
            int now = 1 - last; // rotate to use the two rows
            memset(dp[now], 0, sizeof(int) * n);

            dp[now][0] = tri[i][0] + dp[last][0];   // most left path has no other options
            dp[now][i] = tri[i][i] + dp[last][i-1]; // most right ~

            for(int j = 1; j < i; ++j){
                dp[now][j] = tri[i][j] + min(dp[last][j-1], dp[last][j]);
            }

            last = now;
        }

        int ans = dp[last][0];

        for(int i = 1; i < n; ++i){
            ans = min(ans, dp[last][i]);
        }

        return ans;
    }

private:
    /*
     * used by solution 1
     * */
    int sumPath(const vector<vector<int> >& triangle, int* indice){
        const int n = triangle.size();
        int sum = 0;

        for(int i = 0; i < n; ++i){
            sum += triangle[i][indice[i]];
        }

        return sum;
    }
};

/* unit test is in ../cpp_unittest/triangle_unittest */
