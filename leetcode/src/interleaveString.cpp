/*
 * given string s1, s2, s3, ask if s1 and s2 interleave s3.
 * e.g. "abc" and "ad" can interleave "aabdc"
 * Note: inner order of s1 or s2 should not be changed in s3
 * */
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     * classoc DP
     * */
    bool isInterleave(const string& s1, const string& s2, const string& s3){
        if(s1.size() + s2.size() != s3.size())    return false;    // check length

        const int m = s1.size();
        const int n = s2.size();

        // first check them via the char set
        vector<int> arr1(256, 0);
        vector<int> arr2(256, 0);

        for(int i=0; i < m; i++)    arr1[(int)s1[i]]++;
        for(int i=0; i < n; i++)    arr1[(int)s2[i]]++;
        for(int i=0; i < m+n; i++)  arr2[(int)s3[i]]++;

        for(int i=0; i < m+n; i++){    // check set of s1+s2 and s3
            if(arr1[i] != arr2[i])    return false;
        }

        // validation via DP
        // dp[i][j] == 1 means s1.sub(0,i) and s2.sub(0,j) interleaves s3.sub(0, i+j), both of i and j are lengths
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, 0)); // bool dp[m+1][n+1]
        dp[0][0] = true;

        for(int i = 1; i <= m && s1[i-1] == s3[i-1]; i++){
            dp[i][0] = true;
        }

        for(int j = 1; j <= n && s2[j-1] == s3[j-1]; j++){
            dp[0][j] = true;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1])
                          || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }

        return dp[m][n];
    }
};

