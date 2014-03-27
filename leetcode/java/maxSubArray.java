/*
 * find the contiguous subarray within an array (containing at least one number) which has the largest sum
 * best is linear algorithm in O(n), 2nd is divide-and-conquer in O(nlgn)
 *
 * test cases:
 * [-1], -1
 * [-2, -3, -4, -1, -2], -1
 * [-1, 4, -2, 3, 1, -2], 6
 * [2, 2, -4, 1, 2, -1], 4
 * */
import java.io.*;
import java.util.*;
import java.lang.*;  // Math.*

public class maxSubArray{
    public int maxSubArray_01(int[] A){
        if(A.length == 0)    return 0;
        if(A.length == 1)    return A[0];
        int curr = A[0], best = A[0];
        for(int i=1; i < A.length; ++i){
            curr = Math.max(curr, 0) + A[i];
            best = Math.max(best, curr);
        }
        return best;
    }

    public static void main(String[] args){
        return;
    }
}
