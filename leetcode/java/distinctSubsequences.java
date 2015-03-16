/*
 * from oj.leetcode. given a string S and string T, count the number of distinct subsequences of T in S(subsequences in S equals to T)
 * e.g. "ACE" is a subsequence of "ABCDE", while "AEC" is not
 * S="rabbbit", T="rabit", count is 3
 *
 * */
import java.io.*;
import java.util.*;

public class distinctSubsequences{    
    /*
     * raw solution via DP with space complexity O(n * m)
     * */
    public int numDistinct_01(String S, String T){
        int m = T.length(), n = S.length();
        if(m > n)    return 0;
        char[] arrS = S.toCharArray();
        char[] arrT = T.toCharArray();

        int[][] dp = new int[m+1][n+1];
        for(int j = 0; j <= n; j++){
            dp[0][j] = 1;
        }

        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= m; i++){
                if(i > j)     break;
                dp[i][j] = dp[i][j-1];
                if(arrT[i-1] == arrS[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }

    /*
    * optimized solution with space complexity O(m)
    * */
    public int numDistinct_02(String S, String T){ // in time O(n * m)
        int m = T.length(), n = S.length();
        if(m > n)    return 0;
        char[] arrS = S.toCharArray();
        char[] arrT = T.toCharArray();
        int dp[] = new int[m+1]; // dp[i] means distinct subsequences of T[0...(i-1)] in S 
        dp[0] = 1;

        for(int j = 1; j <= n; ++j){
            for(int i = m; i >= 1; --i){
                if(i > j)     continue;
                dp[i] += (arrT[i-1] == arrS[j-1] ? dp[i-1] : 0);
            }
        }
        return dp[m];
    }
}

