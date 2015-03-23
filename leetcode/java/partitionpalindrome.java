/*
 * given a string s, partition s such that every substring of the partition is a palindrome. return all possible palindrome partition of s.
 * 
 * test data:
 * a
 * aa
 * aba
 * abbaabcba
 * */
import java.util.ArrayList;
import java.util.Stack;
import java.util.Arrays;

public class partitionpalindrome{
    /*
     * get a space O(n^2) structure of all substr palindrome [start, end]
     * */
    private ArrayList<ArrayList<Integer>> make_alpalin(String s){
        ArrayList<ArrayList<Integer>> alpalin = new ArrayList<ArrayList<Integer>>();
        char[] arr = s.toCharArray();
        int n = arr.length;

        for(int i = 0; i < n; i++){  // alpalin[i] has ends of all palindrome which starts at [i]
            alpalin.add(new ArrayList<Integer>());
            alpalin.get(i).add(i + 1); // end is exclusive
        }

        for(int l = 2; l <= n; l++){
            for(int end = n; end - l >= 0; end--){
                if(l < 4 || alpalin.get(end - l + 1).contains(end - 1)){
                    if(arr[end - l] == arr[end - 1]){
                        alpalin.get(end - l).add(end);
                    }
                }
            }
        }
        return alpalin;
    }

    private void partition_palin(ArrayList<ArrayList<String>> res, ArrayList<ArrayList<Integer>> alpalin, 
            String str, int start, Stack<Integer> stk){
        if(start == str.length()){
            ArrayList<String> als  = new ArrayList<String>();
            Integer[] ali = stk.toArray(new Integer[0]); // bottom of Stack is in head of array
            int n = ali.length;
            for(int i = 0; i < n - 1; i++){
                als.add(str.substring(ali[i], ali[i + 1]));
            }
            res.add(als);
            return;
        }

        Integer[] startEnds = alpalin.get(start).toArray(new Integer[0]);
        for(int end : startEnds){  // Arrays has fixed length, so .length can be optimized by compiler
            stk.push(end);
            partition_palin(res, alpalin, str, end, stk); // end of preceding substr is start of next substr
            stk.pop();
        }
        return;
    }

    public ArrayList<ArrayList<String>> partition(String s){
        ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();
        if(s == null || s.isEmpty())    return res;
        int n = s.length();

        ArrayList<ArrayList<Integer>> alpalin = make_alpalin(s);
        Stack<Integer> stk = new Stack<Integer>();
        stk.push(0);
        partition_palin(res, alpalin, s, 0, stk);
        stk.pop();
        return res;
    }

    /* test case is in ../partitionpalindrome_junit/ */
}
