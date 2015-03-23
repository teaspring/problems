/*
 * given a string s, partition s such that every substring of the partition is a palindrome. 
 * return the minimum cuts needed for a palindrome partition of s.
 * 
 * test data:
 * a
 * abb
 * abad
 * aaaaaaaaa
 * aaaaaaaaaaaaab
 * baaaaaaaaaaaa
 * */
import java.io.*;
import java.lang.Math;
import java.util.Arrays;

public class partitionpalindromeII{
    /*
     * accepted solution on oj.leecode. totally, time O(n^2) and space O(n^2)
     * */
    public int minCut(String s){
        if(s == null || s.length() < 2)    return 0;
        char[] arr = s.toCharArray();
        int n = arr.length;

        boolean[][] dp = new boolean[n][n+1];
        for(int i = 0; i < n; ++i){
            for(int j = i + 2; j <= n; ++j){
                dp[i][j] = false;
            }
            dp[i][i] = true;
            dp[i][i+1] = true;
        }

        for(int l = 2; l <= n; ++l){ // check all substr palindrome information 
            for(int e = n; e - l >= 0; --e){
                if(l < 4 || dp[e - l + 1][e - 1]){
                    if(arr[e - l] == arr[e - 1]){
                        dp[e - l][e] = true;
                    }
                }
            }
        }

        int[] mcl = new int[n + 1]; // mcl[l] means min cut of substring [0, e)
        for(int e = 2; e <= n; ++e){ // index end
            if(dp[0][e]){
                mcl[e] = 0;
            }else{
                int in = e - 2; // init value is maximum cut of l-1 except 1 cut to split [0,j) and [j, e)
                for(int j = e - 1; j > 0; --j){ // j must start from l-1! as dp[l-1][l]==1, only at time, in can be minimized to mcl[l-1]
                    if(dp[j][e])    in = Math.min(in, mcl[j]);
                }
                mcl[e] = in + 1;
            }
        }
        return mcl[n];
    }

    /* test case is in  ../partitionpalindromII_junit/ */
}
