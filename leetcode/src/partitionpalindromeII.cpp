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

        int dp[n][n+1];    // dp[i][j] == 1 means s.substr(i,j-i) is palindrome, both of i and j are char index
        for(int i = 0; i < n; ++i){
            memset(dp[i], 0, sizeof(dp[i]));
            dp[i][i+1] = 1;
        }

        for(int len = 2; len <= n; ++len){
            for(int start = 0; start + len <= n; ++start){
                if(len < 4 || dp[start + 1][start + len - 1] == 1){
                    if(s[start] == s[start + len - 1]){
                        dp[start][start + len] = 1;
                    }
                }
            }
        }

        int mc[n+1];  // mc[i] means min cuts of substring [0,i)
        memset(mc, 0, sizeof(mc));

        for(int e = 2; e <= n; ++e){
            if(dp[0][e] == 1){
                mc[e] = 0;
            }else{
                mc[e] = mc[e-1] + 1;   // default value
                for(int j = e-1; j > 0; --j){ // iterate j backward to make use of previously fixed mc[j]
                    if(dp[j][e] == 1){
                        mc[e] = min(mc[e], mc[j] + 1);
                    }
                }
            }
        }

        return mc[n];
    }
};

/* unit test is in ../cpp_unittest/partitionpalindromeII_unittest */
