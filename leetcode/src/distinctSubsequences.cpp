/*
 * from oj.leetcode. given a string S and string T, count the number of distinct subsequences of T in S(subsequence in S equals to T)
 * e.g. "ACE" is a subsequence of "ABCDE", while "AEC" is not
 * S = "rabbbit", T="rabbit", count is 3
 *
 * */
#include "../include/preliminary.h"

/*
 * solution DP:
 * dp[m][n], dp[i][j] means count of distinct subsequences of T.substr(0,i) in S.substr(0,j)
 * dp[i][j] = dp[i][j-1]      //count of distinct subsequences of T.substr(0,i) in S.substr(0,j-1)
 *          + dp[i-1][j-1]    //if T[i-1] == S[j-1]; the base value is always from initialized dp[0][x] == 1
 *          + 0               //else
 * */
int numDistinct_01(const string& S, const string& T){
    int m = T.length(), n = S.length();
    if(m > n)    return 0;
    int **dp = new int*[m+1];
    for(int i=0; i<=m; ++i){
        dp[i] = new int[n+1]();
    }
    for(int i=0; i<=n; ++i){
        dp[0][i] = 1;
    }
    for(int j=1; j<=n; ++j){
        for(int i=1; i<=m; ++i){
            if(i>j)        break;
            dp[i][j] = dp[i][j-1] 
                     + (T[i-1] == S[j-1] ? dp[i-1][j-1] : 0);    //dp[i][j] is updated only once, depending on dp[i][j-1] and dp[i-1][j-1]
        }
    }
    int res = dp[m][n];
    
    for(int i=0; i<=m; ++i){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp=0;
    return res;
}

/*
 * optimization, reduce space from O(m*n) to O(m)
 * */
int numDistinct_02(const string& S, const string& T){
    int m = T.length(), n = S.length();
    if(m > n)    return 0;
    int *dp = new int[m+1]();
    dp[0] = 1;
    for(int j=1; j<=n; ++j){
        for(int i = m; i>=1; --i){   //traverse reversely to use dp[i-1] as last step 
            if(i>j)        continue;
            dp[i] += (T[i-1] == S[j-1] ? dp[i-1] : 0);
        }
    }
    int res = dp[m];
    delete[] dp;
    dp=0;
    return res;
}

void test_01(){
    while(1){
        printf("please input target string T:\n");
        string t;
        if(getline(cin, t)==0 || t.empty())        break;
        printf("please input source string S:\n");
        string s;
        if(getline(cin, s)==0 || s.empty())        break;
        printf("solution 1 result: %d \n", numDistinct_01(s, t));
        printf("solution 2 result: %d \n", numDistinct_02(s, t));
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
