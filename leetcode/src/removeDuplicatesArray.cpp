/*
 * given a sorted array, remove the duplicates from it in-place, return the new array size.
 *
 * */

#include "../header/preliminary.h"

/*
 * problem I: every value is allowed to appear only once
 * input:  1,1,2,2
 * output: 1,2
 * */
int remove(int A[], int n){
    if(n<2)        return n;
    int i=1;
    while(i<n && A[i] != A[i-1]){
        i++;
    }
    if(i==n)    return n;
    for(int j=i+1; j<n; ++j){
        if(A[j] == A[j-1])        continue;
        A[i++] = A[j];
    }
    return i;
}

/*
 * problem II: every value is allowed to appear twice at most.
 * input:  1,1,1,2,2,3
 * output: 1,1,2,2,3
 * */
int removeII(int A[], int n){    // really elegent solution!!! 
    if(n <= 2)    return n;
    int len = 2, itor = 2;
    while(itor < n){
        if(A[itor] != A[len-2]){
            if(len < itor)    A[len] = A[itor];
            len++;
        }
        itor++;
    }
    return len;
}

void test_02(){
    int arr[] = {1,1,2,3,3,3,4,5,5,5,6};
    int m = sizeof(arr) / sizeof(int);
    showarray(arr, removeII(arr, m));
}

int main(int, char**){
    test_02();
    return 0;
}
