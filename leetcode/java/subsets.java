/*
 * given a set of distinct integers S,  return all possible subsets.
 * e.g. S = [1,2,3]
 * output: 
 * [], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3] 
 *
 * */
import java.io.*;
import java.util.*;
import java.util.Collections;
import java.util.Arrays;
import java.util.Scanner;

public class subsets{
    public List<List<Integer>> subsets(int[] S){
        Arrays.sort(S);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Stack<Integer> pipe = new Stack<Integer>();
        helper(S, 0, pipe, result);
        return result;
    }

    private void helper(int[] src, int i, Stack<Integer> pipe, List<List<Integer>> res){
        if(i<0)     return;
        res.add(new ArrayList<Integer>(pipe));     // !!! as pipe is a referecne, so the saved one must be new ArrayList<>() initialized of current pipe  
        for(; i<src.length; ++i){
            pipe.push(src[i]);
            helper(src, i+1, pipe, res);
            pipe.pop();
        }
        return;
    }

    private void output(List<List<Integer>> res){
        for(int i=0; i<res.size(); ++i){
            System.out.println(res.get(i).toString());
        }
        return;
    }

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

    public static void main(String[] args){
        subsets ss = new subsets();
        ss.test_01();
        return;
    }
}

