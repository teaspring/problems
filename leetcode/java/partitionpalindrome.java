/*
 * given a string s, partition s such that every substring of the partition is a palindrome. return all possible palindrome partition of s.
 * 
 * test data:
 * a
 * aa
 * aba
 * abbaabcba
 * */
import java.io.*;
import java.util.*;

public class partitionpalindrome{
    private ArrayList<ArrayList<Integer>> make_alpalin(String s){
        ArrayList<ArrayList<Integer>> alpalin = new ArrayList<ArrayList<Integer>>();
        int n = s.length();
        for(int i=0;i<n;i++){
            alpalin.add(new ArrayList<Integer>());
        }
        int[][] dp = new int[n][n+1];    //dp[start][length] == 1 means substring is palindrome
        for(int i=0;i<n;i++){
            dp[i][1] = 1;
            alpalin.get(i).add(i+1);
        }
        for(int l=2;l<=n;l++){
            for(int end=n;end-l>=0;end--){
                if(l<4 || dp[end-l+1][l-2]==1){
                    Character ch = new Character(s.charAt(end-l));
                    if(ch.equals(s.charAt(end-1))){
                        dp[end-l][l] = 1;
                        alpalin.get(end-l).add(end);
                    }
                }
            }
        }
        return alpalin;
    }

    private void partition_palin(ArrayList<ArrayList<String>> res, ArrayList<ArrayList<Integer>> alpalin, 
            String s, int start, Stack<Integer> stk){
        if(start == s.length()){
            ArrayList<String> als  = new ArrayList<String>();
            ArrayList<Integer> ali = new ArrayList<Integer>(stk);
            for(int i=1;i<ali.size();i++){
                als.add(s.substring(ali.get(i-1), ali.get(i)));   //subString(s, e);   [s,e)             
            }
            res.add(als);
            return;
        }

        ArrayList<Integer> arr = alpalin.get(start);
        for(int i=0;i<arr.size();i++){
            stk.push(arr.get(i));
            partition_palin(res, alpalin, s, arr.get(i), stk);
            stk.pop();
        }
        return;
    }

    public ArrayList<ArrayList<String>> partition(String s){
        ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();
        if(s==null)        return res;
        int n = s.length();
        if(n==1){
            ArrayList<String> arr = new ArrayList<String>();
            arr.add(s);
            res.add(arr);
            return res;
        }
        ArrayList<ArrayList<Integer>> alpalin = make_alpalin(s);
        Stack<Integer> stk = new Stack<Integer>(); //class Stack<>
        stk.push(0);
        partition_palin(res, alpalin, s, 0, stk);
        stk.pop();
        return res;
    }

    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input String:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())        break;
            ArrayList<ArrayList<String>> res = partition(str);
            for(int i=0;i<res.size();i++){
                System.out.println(res.get(i).toString());
            }
        }
        return;
    }

    /*
     * time Limit exceed as the recurse with stack operation costing too much memory 
     * */
    public int minCut_01(String s){
        if(s==null || s.length()==1)        return 0;
        int n = s.length();
        ArrayList<ArrayList<Integer>> alpalin = make_alpalin(s);
        Stack<Integer> stk = new Stack<Integer>(); //class Stack<>
        stk.push(0);
        int count = partition_count(alpalin, s, 0, stk);
        stk.pop();
        return count;
    }
    private int partition_count(ArrayList<ArrayList<Integer>> alpalin, String s, int start, Stack<Integer> stk){
        if(start == s.length()){
            return stk.size()-2;    //return cut 
        }
        ArrayList<Integer> arr = alpalin.get(start);
        int cut = s.length()-1;
        for(int i=0;i<arr.size();i++){
            stk.push(arr.get(i));
            int tmp = partition_count(alpalin, s, arr.get(i), stk);
            if(tmp < cut){
                cut = tmp;
            }
            stk.pop();
        }
        return cut;
    }

    public static void main(String[] args){
        partitionpalindrome pp = new partitionpalindrome();
        pp.test();
    }
}
