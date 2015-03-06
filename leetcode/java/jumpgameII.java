/*
 * given an array of non-regative integers, you are initially positioned at the first index of array. Each element in the array represents
 * your maximum jump length at that position. Your goal is to reach the last index in the minimum number of jumps. if no path available, return -1
 *
 * it's a greedy problem
 * 
 * test cases:
 * 0   -   0
 * 1 2 -   1
 * 2 3 1 1 4   -   2
 * 3 4 3 2 5 4 3   -   3
 * 5 4 0 1 3 6 8 0 9 4 9 1 8 7 4 8    -    3
 * 1 0 0  -  -1
 * 0 1 1  -  -1
 * */
import java.io.*;
import java.util.*;
import java.lang.Math.*;

public class jumpgameII{
    public int jump(int[] A){
        int n = A.length;
        if(n < 2)    return 0;
        int[] B = new int[n];
        for(int i = 0; i < n; ++i){
            B[i] = i;
        }
        int forward = 0;  
        for(int i = 0;i < n-1; ++i){
            int bound = Math.min(n-1, i + A[i]);  // bound is furthest postition which is jumped from [i]
            if(bound <= forward)    continue;  // forward is the furthest position which is jumped from [i-1]
            for(int j = bound; j > forward; --j){
                B[j] = i;   // B[j] means the furthest predecent position jump to it
            }
            forward = bound;
        }
        int res = 0, i = 0;
        for(i = n-1; i > 0 && B[i] < i;){
            ++res;
            i = B[i];
        }
        return i == 0 ? res : -1;
    }
    /* unittest will be done via junit code in ../java_unittest/[class_name]/ */

    /*
    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input jump array:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            StringTokenizer st = new StringTokenizer(str, " ,");
            int n = st.countTokens();
            int[] A = new int[n];
            int i=0;
            while(st.hasMoreTokens()){
                A[i++] = Integer.parseInt(st.nextToken().trim());
            }
            System.out.println("minimum jumps is " + jump(A));
        }
        return;
    }
    */
}
