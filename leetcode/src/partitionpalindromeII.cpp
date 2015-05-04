/*
 * given a string s, partition s such that every substring of partition is a palindrome
 * return the minimum cuts needed for a palindrome partitioning of s
 *
 * test data:
 * cbbcc
 * aaaaaaaaaab
 * */

#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution{

public:
    /*
     *
     * */
    int minCut(const string& s){
        const int n = s.size();
        if(n < 2)        return 0;

        int dp[n][n+1];    // dp[i][j] == 1 means substr [i,j) is palindrome
        for(int i = 0; i < n; ++i){
            memset(dp[i], 0, sizeof(dp[i]));
            dp[i][i+1] = 1;
        }

        for(int len = 2; len <= n; ++len){
            for(int start = 0; start + len <= n; ++start){
                if(len < 4 || dp[start + 1][start + len - 1]==1){
                    if(s[start] == s[start + len - 1]){
                        dp[start][start + len] = 1;
                    }
                }
            }
        }

        int mc[n+1];  // mc[i] means min cuts of substring [0,i) of length i
        memset(mc, 0, sizeof(mc));

        for(int i = 2; i <= n;++i){
            if(dp[0][i] == 1){
                mc[i] = 0;
            }else{
                int ic = i-2;   // minimize ic and mc[i] is ic+1 at least
                for(int j = i-1; j > 0; --j){ // now i as end of range, so j has to scan reversely from right to left
                    if(dp[j][i] == 1){
                        ic = min(ic, mc[j]);
                    }
                }
                mc[i] = ic + 1;
            }
        }

        return mc[n];
    }
};

/* unit test is in ../cpp_unittest/partitionpalindromeII_unittest */
