/*
 * problem1:
 * given n, how many structurally unique BST's(binary search tree) that store values 1...n?
 * e.g. n=3, there are a total of 5 unique BST's
 * */
import java.io.*;
import java.util.*;

public class uniqueBST{
    public int numTrees(int n){
        if(n<1)        return 0;
        int[] subs = new int[n+1];
        subs[0] = subs[1] = 1;
        for(int i=2; i<=n; ++i){ //i is 1-based
            for(int r=1; r<=i; ++r){ //r is root of i numbers
                subs[i] += subs[r-1] * subs[i-r];
            }
        }
        return subs[n];
    }

    public static void main(String[] args){
        return;
    }
}
