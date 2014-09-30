/*
 * given string s1, s2, s3, ask if s1 and s2 interleave s3
 */
#include "../include/preliminary.h"

class InterleaveString{
public:
    bool isInterleave(string s1, string s2, string s3){
        if(s1.size() + s2.size() != s3.size())    return false;    // check length
        int m = s1.size(), n = s2.size();
        int arr1[256], arr2[256];
        memset(arr1, 0, sizeof(arr1));
        memset(arr2, 0, sizeof(arr2));
        for(int i=0; i<m; i++)    arr1[(int)s1[i]]++;
        for(int i=0; i<n; i++)    arr1[(int)s2[i]]++;
        for(int i=0; i<m+n; i++)  arr2[(int)s3[i]]++;
        for(int i=0; i < m+n; i++){    // check set of s1+s2 and s3
            if(arr1[i] != arr2[i])    return false;
        }

        int dp[m+1][n+1];    // dp[i][j] == 1 means s1.sub(0,i) and s2.sub(0,j) interleaves s3.sub(0, i+j), both of i and j are lengths
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i=1; i<=m; i++){
            if(s1[i-1] != s3[i-1])    break;
            dp[i][0] = 1;
        }
        for(int j=1; j<=n; j++){
            if(s2[j-1] != s3[j-1])    break;
            dp[0][j] = 1;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = (dp[i][j-1] == 1 && s2[j-1] == s3[i+j-1])
                          || (dp[i-1][j] == 1 && s1[i-1] == s3[i+j-1]) ? 1 : 0;
            }
        }
        return dp[m][n] == 1;
    }

    void test_01(){
        string s1("aabcc");
        string s2("dbbca");
        cout << (isInterleave(s1, s2, string("aadbbcbcac")) ? "true" : "false") << endl;
        cout << (isInterleave(s1, s2, string("aadbbbaccc")) ? "true" : "false") << endl;
    }

    void test_02(){
        string s1("");
        string s2("b");
        cout << (isInterleave(s1, s2, string("b")) ? "true" : "false") << endl;
    }
};

int main(){
    InterleaveString ils;
    ils.test_01();
    ils.test_02();
    return 0;
}

