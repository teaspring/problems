/*
 * given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * */
import java.io.*;
import java.util.*;

public class triangle{
    private int min(int a, int b){
        return a<b ? a : b;
    }
    public int minimumTotal(ArrayList<ArrayList<Integer>> tri){
        int n = tri.size();
        int[][] dp = new int[2][n];
        int last=0;
        dp[0][0] = tri.get(0).get(0);
        for(int i=1;i<n;i++){
            int now = 1-last;
            dp[now][0] = tri.get(i).get(0) + dp[last][0];
            dp[now][i] = tri.get(i).get(i) + dp[last][i-1];
            for(int j=1;j<i;j++){
                dp[now][j] = tri.get(i).get(j) + min(dp[last][j-1], dp[last][j]);
            }
            last = now;
        }
        int res = dp[last][0];
        for(int i=1;i<n;i++){
            res = min(res, dp[last][i]);
        }
        return res;
    } 

    public void test_01(){
        ArrayList<ArrayList<Integer>> tri = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> arr0 = new ArrayList<Integer>();
        arr0.add(2);
        tri.add(arr0);
        ArrayList<Integer> arr1 = new ArrayList<Integer>();
        arr1.add(3);
        arr1.add(4);
        tri.add(arr1);
        ArrayList<Integer> arr2 = new ArrayList<Integer>();
        arr2.add(6);
        arr2.add(5);
        arr2.add(7);
        tri.add(arr2);
        ArrayList<Integer> arr3 = new ArrayList<Integer>();
        arr3.add(4);
        arr3.add(1);
        arr3.add(8);
        arr3.add(3);
        tri.add(arr3);
        System.out.println(minimumTotal(tri));
    }

    public static void main(String[] args){
        triangle t = new triangle();
        t.test_01();
    }
}
