/*
 * remove duplicates from sorted array in place, return the modified array size.
 * */
import java.io.*;
import java.util.*;

public class removeDuplicates{
    public int remove(int[] A){
        int n = A.length;
        if(n<2)        return n;
        int i=1;
        while(i<n && A[i] != A[i-1]){
            ++i;
        }
        if(i==n)    return n;
        for(int j=i+1; j<n; ++j){
            if(A[j] == A[j-1])        continue;
            A[i++] = A[j];
        }
        return i;
    }

    public static void main(String[] args){
        return;
    }
}
