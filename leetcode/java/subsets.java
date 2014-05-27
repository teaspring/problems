/*
 * problem 1:
 * given a set of distinct integers S,  return all possible subsets.
 * e.g. S = [1,2,3]
 * output: 
 * [], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3] 
 *
 * problem 2:
 * given a set with duplicate integers S, return all unique subsets
 * e.g. S = [1,2,2]
 * output:
 * [], [1], [1,2], [1,2,2], [2], [2,2]
 * */
import java.io.*;
import java.util.*;
import java.util.Collections;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class subsets{
    /*
     * problem 1, given S of distinct integers
     * */
    public List<List<Integer>> subsets(int[] S){
        Arrays.sort(S);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Stack<Integer> pipe = new Stack<Integer>();
        helper(S, 0, pipe, result);
        return result;
    }

    private void helper(int[] src, int i, Stack<Integer> pipe, List<List<Integer>> res){
        if(i<0)     return;
        res.add(new ArrayList<Integer>(pipe));  // !!! as pipe is referecne, the added one must be new ArrayList<>() obj initialized by current pipe  
        for(; i<src.length; ++i){
            pipe.push(src[i]);
            helper(src, i+1, pipe, res);
            pipe.pop();
        }
        return;
    }

    /*
     * problem 2, given S with duplicate integers
     * */
    public List<List<Integer>> subsetsWithDup(int[] num){
        Arrays.sort(num);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Stack<Integer> stk = new Stack<Integer>();
        helper_II(num, 0, stk, res);
        return res;
    }

    private void helper_II(int[] num, int i, Stack<Integer> stk, List<List<Integer>> res){
        res.add(index2Value(num, stk));
        for(; i<num.length; ++i){
            int m = stk.size();
            if(i>0 && (m==0 || i > stk.peek() + 1) && (num[i-1] == num[i]))        continue;
            stk.push(i);
            helper_II(num, i+1, stk, res);
            stk.pop();
        }
        return;
    }
    
    private List<Integer> index2Value(int[] num, List<Integer> indexes){
        List<Integer> values = new ArrayList<Integer>();
        for(int i : indexes){
            values.add(num[i]);
        }
        return values;
    }

    /*************test************/
    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input integer between [1,9]:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int n = Integer.parseInt(str);
            int[] S = new int[n];
            for(int i=0; i<n; ++i){
                S[i] = n-i;
            }
            output(subsets(S));
        }
    }

    public void test_02(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input integers in array:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())        break;
            StringTokenizer st = new StringTokenizer(str, " ,");
            int[] num = new int[st.countTokens()];
            int i = 0;
            while(st.hasMoreTokens()){
                num[i++] = Integer.parseInt(st.nextToken());
            }
            output(subsetsWithDup(num));
        }
    }

    private void output(List<List<Integer>> res){
        for(int i=0; i<res.size(); ++i){
            System.out.println(res.get(i).toString());
        }
        return;
    }

    public static void main(String[] args){
        subsets ss = new subsets();
        ss.test_02();
        return;
    }
}

