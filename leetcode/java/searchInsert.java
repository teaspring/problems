/*
 * given a sorted array and a target value, return index if it is found. Or else, return index where it would be inserted in order.
 * assume the array is sorted in ascending order without duplicates.
 * */
import java.io.*;
import java.util.*;

public class searchInsert{
    public int search(int[] A, int x){
        int n = A.length;
        int v=0, u=n, m;
        while(v<u){
            m = (v+u)/2;
            if(A[m]==x){
                return m;
            }else if(A[m] > x){
                if(m==0 || A[m-1] < x){
                    return m;
                }else{
                    u=m;
                }
            }else{
                if(m==n-1 || A[m+1] >= x){
                    return m+1;
                }else{
                    v = m+1;
                }
            }
        }
        return v;
    }

    public static void main(String[] args){
        return;
    }
}
