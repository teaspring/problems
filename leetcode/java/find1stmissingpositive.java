/*
 * Given an unsorted integer array, find the 1st positive integer
 * test case:
 * [1,2,0], return 3
 * */
import java.io.*;
import java.util.*;

public class find1stmissingpositive{
    public int findMissingPositive(int[] A){
        int n = A.length;
        int[] B = new int[n];   //to put [1,n]
        for(int i=0;i<n;++i){
            if(A[i]<1 || A[i]>n)    continue;
            B[A[i]-1] = 1;
        }
        int j=0;
        for(;j<n && B[j]!=0;++j);
        return j+1;
    }
    
    public static void main(String[] args){
        return;
    }
}
