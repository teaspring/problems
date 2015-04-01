/*
 * given an unsorted integer array, find the first missing positive integer
 *
 * test case:
 * [1,2,0], return 3
 * [3,4,-1,1], return 2
 * */
#include "../include/preliminary.h"

class Solution {

public:

    int findMissingPositive(int A[], int n){
        int B[n];
        memset(B, 0, sizeof(B));

        for(int i = 0; i < n; ++i){
            if(A[i] > n || A[i] < 1)    continue;
            B[A[i] - 1] = 1;
        }

        int t = 0;
        for(; t < n && B[t] != 0; ++t);

        return t+1;  // if t == n, return n+1
    }
};
