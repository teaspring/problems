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
    public int search(int[] A, int key){  // problem I: no duplicate
        int n = A.length;
        int l=0, r=n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(key == A[m])    return m;
            if(A[l] < A[m]){  // left half is sorted
                if(A[l] <= key && key < A[m]){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }else if(A[l] > A[m]){  // right half is sorted
                if(A[m] < key || key <= A[r]){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }else{  // l == m
                l = m+1;
            }
        }
        return -1;
    }

    public int searchII(int[] A, int key  // problem II: duplicate is allowed
        int n = A.length;
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(A[m] == key)    return m;
            if(A[l] < A[m]){    // left half is sorted
                if(A[l] <= key && key < A[m]){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }else if(A[l] > A[m]){  // right half is sorted
                if(A[m] < key && key <= A[r]){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }else{    // e.g. {1,1,5,1,1,1} with key is 5, no sense it is in which side
                l++;
            }
        }
        return -1;
    }

    public static void main(String[] args){
        return;
    }
}
