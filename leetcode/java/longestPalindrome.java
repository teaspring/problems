/*
 * given a String S, find the longest palindrome substring in it. assume the length of string is less than  1000 and there only one unique
 * result of longest palindrome substring
 * */
import java.io.*;
import java.util.*;
import java.lang.Math;

public class longestPalindrome{
    /*
     * Manacher algorithm, time O(n), space O(n), very smart and elegent
     * */
    public String Manacher(String S){
        if(S == null || S.isEmpty())    return new String();

        final int n = S.length();
        final int N = 2*n + 1;

        char[] pMix = new char[N]; // a mixed char array with dummy delimeter '#' inserted
        pMix[0] = '#';
        for(int i = 0, k = 1; i < n || k < N; k++){
            if(pMix[k-1] == '#'){
                pMix[k] = S.charAt(i++);
            }else{
                pMix[k] = '#';
            }
        }

        int[] p = new int[N]; // radius of palindrome substr which centre is [i], the radius including center
        p[0] = 1;
        int id = 0; // center of longest palindrome substr
        int mx = id + p[id]; // mx is the exclusive edge of it

        for(int i = 1; i < N; i++){
            if(mx > i){ // if mx > i stands, 2*id > i definitely
                p[i] = Math.min(p[2*id - i], mx - i);
            }else{
                p[i] = 1;
            }

            while(i - p[i] >= 0
                  && i + p[i] < N
                  && pMix[i - p[i]] == pMix[i + p[i]]){
                p[i]++;
            }

            if(p[i] > p[id]){
                id = i;
            }
            mx = id + p[id];
        }

        char[] res = new char[2 * p[id]];
        int k = 0;  // get the valid char array length
        for(int i = id - p[id] + 1; i < id + p[id]; i++){
            if(pMix[i] == '#')    continue;
            res[k++] = pMix[i];
        }

        return new String(Arrays.copyOfRange(res, 0, k));
    }
}

/* unit test is in ../java_unit/longestPalindrome_junit */
