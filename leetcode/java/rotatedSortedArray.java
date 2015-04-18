/*
 * search in a rotated sorted array
 *
 * test case
 * 5,1,3   x = 4, return -1
 * 5,4,1,2,3  x = 5, return 0
 * */
import java.io.*;
import java.util.*;

public class rotatedSortedArray{
    /*
     * problem I: search key in a rotated sorted array which has no duplicate
     * */
    public int search(int[] A, int key){
        final int n = A.length;
        int l = 0, r = n-1; // r is inclusive right boundary

        while(l <= r){
            int m = l + (r - l)/2;

            if(key == A[m])    return m;

            if(A[l] < A[m]){  // left half is sorted
                if(A[l] <= key && key < A[m]){ // key is in [l, m)
                    r = m-1;
                }else{ // key is in (m, r]
                    l = m+1;
                }
            }else if(A[l] > A[m]){  // right half is sorted
                if(A[m] < key && key <= A[r]){ // key in (m, r]
                    l = m+1;
                }else{ // key in [l, m)
                    r = m-1;
                }
            }else{ // A[l] == A[] ! since duplicate is not allowed, it must be l == m
                l = m+1;
            }
        }
        return -1;
    }

    /*
     * problem II: search key in a rotated sorted array in which duplicate is allowed
     * */
    public int searchII(int[] A, int key){
        final int n = A.length;
        int l = 0, r = n-1; // r is inclusive right boundary

        while(l <= r){
            int m = l + (r - l)/2;

            if(A[m] == key)    return m;

            if(A[l] < A[m]){    // left half is sorted
                if(A[l] <= key && key < A[m]){ // in [l, m)
                    r = m-1;
                }else{ // in (m, r]
                    l = m+1;
                }
            }else if(A[l] > A[m]){  // right half is sorted
                if(A[m] < key && key <= A[r]){ // in (m, r]
                    l = m+1;
                }else{ // in [l, m)
                    r = m-1;
                }
            }else{ // remember duplicate is allowed
                l++;
            }
        }
        return -1;
    }
}

/* unit test is in ../java_unittest/rotatedSortedArray_junit */
