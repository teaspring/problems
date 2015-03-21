/*
 * Given an unsorted integer array, find the 1st missing positive integer
 *
 * test case:
 * [1,2,0], return 3
 * [4,2,3], return 1
 * [1,2,3], return 4
 * [4,1,4,3], return 2
 * */
import java.io.*;
import java.util.*;

public class find1stmissingpositive{
    public int findMissingPositive(int[] A){
        int n = A.length;
        boolean[] B = new boolean[n];   //to put [1,n]
        for(int i = 0; i < n; ++i){
            if(A[i] < 1 || A[i] > n)    continue;
            B[A[i] - 1] = true;
        }
        int j = 0;
        for(; j < n && B[j]; ++j);
        return j + 1;
    }
}
