/*
 * search in a rotated sorted array
 *
 * test case
 * 5,1,3   x=4, return -1
 * 5,4,1,2,3  x=5, return 0
 * */
import java.io.*;
import java.util.*;

public class rotatedSortedArray{
    public int search(int[] A, int x){
        int n = A.length;
        int v=0, u=n-1;
        while(v <= u){
            int m = (v+u)/2;
            if(x == A[m]){
                return m;
            }
            if(A[v] <= A[m]){
                if(x > A[m]){
                    v = m+1;
                }else if(x >= A[v]){
                    u = m-1;
                }else{
                    v = m+1;
                }
            }else{
                if(x < A[m] || x > A[v]){
                    u = m-1;
                }else if(x <= A[u]){
                    v = m+1;
                }else{
                    u = m-1;
                }
            }
        }
        return -1;
    }
    public static void main(String[] args){
        return;
    }
}
