/*
 * from oj.leetcode. given a string S and string T, count the number of distinct subsequences of T in S(subsequences in S equals to T)
 * e.g. "ACE" is a subsequence of "ABCDE", while "AEC" is not
 * S="rabbbit", T="rabit", count is 3
 *
 * */

import java.io.*;
import java.util.*;

public class distinctSubsequences{
    public int numDistinct_02(String S, String T){    //optimized solution
        int m = T.length(), n = S.length();
        if(m > n)    return 0;
        int dp[] = new int[m+1];
        dp[0] = 1;
        for(int j=1; j<=n; ++j){
            for(int i=m; i>=1; --i){
                if(i>j)        continue;
                dp[i] += (T.charAt(i-1) == S.charAt(j-1) ? dp[i-1] : 0);
            }
        }
        return dp[m];
    }

    private void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input target string T:");
            String t = scan.nextLine().trim();
            if(t.isEmpty())        break;
            System.out.println("please input source string S:");
            String s = scan.nextLine().trim();
            if(s.isEmpty())        break;
            System.out.println("distinct subsequences is " + numDistinct_02(s, t));
        }
        return;
    }

    public static void main(String[] args){
        distinctSubsequences ds = new distinctSubsequences();
        ds.test_01();
    }
}

