/*
 * given an unsorted integer array, find the first missing positive integer
 *
 * test case:
 * [1,2,0], return 3
 * [3,4,-1,1], return 2
 * */
#include "../header/preliminary.h"

int findMissingPositive(int A[], int n){
    int *B = new int[n]();
    for(int i=0; i<n; ++i){
        if(A[i]>n || A[i]<1)    continue;
        B[A[i]-1] = 1;
    }
    int t=0;
    for(;t<n && B[t]!=0; ++t);
    return t+1;  //if t==n, return n+1
}

int main(int, char**){
    string str;
    while(1){
        printf("please input integer array:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        printf("missing: %d\n", findMissingPositive(arr, n));
        delete[] arr;
    }
    return 0;
}
