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
                for(int j=i+1;j<n;++j){        //str.substring(i,j) means [i,j), both i and j are index
                    if(!inDict[j] && dict.contains(s.substring(i+1,j+1))){
                        inDict[j]=true;
                    }
                }
                if(inDict[n-1])        return true;
            }
        }
        return inDict[n-1];
    }

    /*
     * correct but less efficient solution to problem 2. 
     * first, a traverse of O(n^2) is necessary; second, as this problem needs to output all contained substring composition, dp[i][j]
     * storing substr [i,j) whether contained is less efficient, some structure storing which substr stopping at j for those starting at i
     * is contained is better.
     * */
    public ArrayList<String> wordbreakall_01(String s, Set<String> dict){
        final int n = s.length();
        ArrayList<String> res = new ArrayList<String>();
        if(n==0 || dict.size()==0)    return res;
        
        int[][] dp = new int[n][n+1];    //dp[i][j] means substr among [i,j) whether is contained in dict
        for(int i=0;i<n;++i){
            for(int j=0;j<=n;++j){
                dp[i][j] = 0;
            }
        }
        Stack<Integer> stk1 = new Stack<Integer>();
        Stack<Integer> stk2 = new Stack<Integer>();
        int i=1,j=0;
        try{
        while(i<=n || !stk1.empty()){
            j = stk1.empty()  ? 0 : stk1.peek();
            if(i>n){
                if(stk1.empty())    break;
                i = stk1.pop() + 1;
                continue;
            }
            if(dp[j][i]==0){
                dp[j][i] = dict.contains(s.substring(j,i)) ? 1 : -1;
            }
            if(dp[j][i] == -1){
                ++i;
                continue;
            }           
            stk1.push(i);
            j=i;
            int t=i;
            ++i;
            while(i<=n){
                if(dp[t][i]==0){
                    dp[t][i] = dict.contains(s.substring(t,i)) ? 1 : -1;
                }
                if(dp[t][i]==1){
                    stk1.push(i);
                    t=i;
                }
                ++i;
            }
            if(stk1.peek()==n){
                StringBuilder strBuilder = new StringBuilder();
                while(!stk1.empty()){    //in help of stk2, output the elements in stk1 in order
                    stk2.push(stk1.pop());
                }
                t=0;
                while(!stk2.empty()){
                    stk1.push(stk2.pop());
                    strBuilder.append(s.substring(t, stk1.peek()));
                    strBuilder.append(" ");
                    t=stk1.peek();
                }
                res.add(strBuilder.toString().trim());
                t = stk1.pop();        //n
                if(stk1.empty())    break;
            }
            i = stk1.pop()+1;
        }
        }
        catch(Exception exp){
            System.out.println(exp.toString());
        }
        return res;
    }

    /*
     * efficient solution to problem 2.
     * 1. a traverse of O(n^2) is necessary and a ArrayList<ArrayList<Integer>> is used for the traverse result; 
     * 2. utilize the structure to find all consecutive composition
     *
     * test data:
     * dict={a,aa,aaa,aaaa,aaaaa...}, str=aaaaaaaaaaaaaaab
     * dict={a,aa,aaa,aaaa,aaaaa...}, str=baaaaaaaaaaaaaaa
     * think about how to skip as much useless clauses as possible during preparement(fill the ArrayList<ArrayList<Integer>>)
     * 
     * why it can skip some steps in traverse? because this problem asks to find "word break" instead of "word occurance", any word
     * occurance which cannot contribute to a complete breaking option does not need to cover
     * */
    public ArrayList<String> wordbreakall_02(String s, Set<String> dict){
        ArrayList<String> res = new ArrayList<String>();
        int n = s.length();
        if(n==0 || dict.size()==0)    return res;
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>(n);
        for(int i=0;i<n;++i){
            arr.add(i, new ArrayList<Integer>());            
        }
        for(int stop=n;stop>0;--stop){ //as collect() start from [0] later, here traverse from [n-1] will skip more clauses?
            if(stop<n && arr.get(stop).isEmpty())
                continue;   //key and most smart statement, skip the index which can not arrive in end
            for(int start = stop-1;start>=0;--start){
                if(dict.contains(s.substring(start,stop))){
                    arr.get(start).add(stop);
                }
            }
        }      
        collect(arr, 0, s, "", res);
        return res;
    }

    protected void collect(ArrayList<ArrayList<Integer>> arr, int start, String str, String prev, ArrayList<String> res){
        if(start >= arr.size())    return;
        for(int stop : arr.get(start)){
            String prefix = prev;
            prefix += start==0 ? str.substring(start, stop) : " "+str.substring(start, stop);
            if(stop==str.length()){
                res.add(prefix);
            }else{ 
                collect(arr, stop, str, prefix, res);
            }
        }
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
            String dictStr = scan.nextLine();
            if(dictStr.length()==0)        break;
            HashSet<String> dict = parseStrArray(dictStr);
            
            System.out.println("input string to break:");
            String str = scan.nextLine();
            if(str.length()==0)        break;
            ArrayList<String> result = wb.wordbreakall_02(str, dict);
            for(String s : result){
                System.out.println(s);
            }
        }
    }
}

