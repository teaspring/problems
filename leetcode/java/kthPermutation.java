/*
 * the set [1,2,3,...,n] contains a total of n! unique permutations. by listing and labelling all of the permutations in order.
 * we get the following sequences: for n=3
 * 123
 * 132,
 * 213,
 * 231,
 * 312,
 * 321
 * Q: given n and k, return the kth permutation sequence. n will be between [1,9]
 *
 * Note: normal solution to output all of the permutation will cause Time Limit Exceed exception. Correct solution to this problem is very
 * important which prunes useless branches(剪枝) from sum k. 
 * */
import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.lang.Math;


public class kthPermutation{
    public String getPermutation(int n, int k){
        int[] num = new int[n];
        int count = 1;

        for(int i = 0; i < n; ++i){ // in maximum, count is 9!, not exceed int length yet
            num[i] = i+1;
            count *= num[i];  
        }

        if(k > count)    return null;
        --k;    // k is 1 based

        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < n; ++i){
            count /= (n-i);
            int selected = k / count;
            builder.append(num[selected]);  // selected is 0-based
            
            k = k % count;
            for(int j = selected + 1; j < n-i; ++j){    //reconstruct num[] as one integer is picked up already
                num[j-1] = num[j];
            }
        }
        return builder.toString();
    }
}

/* unit test is in ../java_unittest/kthPermutation_junit */
