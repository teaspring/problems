/*
 * from oj.leetcode
 * problem 1: given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or
 * more dictionary words.
 * brute force is recursion, better solution is dynamic programming in time O(n^2)
 * test data:
 * s=leetcode, dict={lee, leet, tcod, code}, true
 * s=leetcode, dict={lee, tco, d, leet, cod}, false
 * s=leetcode, dict={lee, cod, de, leetcode}
 * */

import java.io.*;
import java.util.*;

public class wordbreak{
    public boolean canBreak(String s, Set<String> dict){
        final int n = s.length();
        if(n==0)    return true;
        boolean[] inDict = new boolean[n];
        for(int i=0;i<n;++i){
            inDict[i] = false;
        }
        for(int i=0;i<n;++i){
            if(!inDict[i] && dict.contains(s.substring(0,i+1)))        inDict[i] = true;
            if(inDict[i]){
                for(int j=i+1;j<n;++j){        //str.substring(i,j) means [i,j) in str
                    if(!inDict[j] && dict.contains(s.substring(i+1,j+1))){
                        inDict[j]=true;
                    }
                }
                if(inDict[n-1])        return true;
            }
        }
        return inDict[n-1];
    }

    static int parseIntArray(String s, int[] arr){
        int i=0;
        int len=s.length();
        StringTokenizer t = new StringTokenizer(s, " ,");
        while(t.hasMoreTokens()){
            arr[i++] = Integer.parseInt(t.nextToken().toString());
        }
        return i;
    }

    static HashSet<String> parseStrArray(String str){
        HashSet<String> st = new HashSet<String>();
        StringTokenizer t = new StringTokenizer(str, " ,");
        while(t.hasMoreTokens()){
            String s = t.nextToken().toString();
            if(!st.contains(s)){
                st.add(s);
            }
        }
        return st;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        wordbreak wb = new wordbreak();
        while(true){            
            System.out.println("input dictionary strings:");
            String s = scan.nextLine();
            if(s.length()==0)        break;
            HashSet<String> dict = parseStrArray(s);
            
            System.out.println("input string to break:");
            String str = scan.nextLine();
            if(str.length()==0)        break;
            System.out.println(wb.canBreak(str, dict) ? "true" : "false");
        }
    }
}

