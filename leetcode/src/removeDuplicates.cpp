/*
 * given a sorted array, remove the duplicates from it in-place, return the new array size.
 *
 * */

#include "../header/preliminary.h"

int removeDuplicates(int A[], int n){
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

int main(int, char**){
    return 0;
}
