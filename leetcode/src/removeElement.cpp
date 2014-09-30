/*
 * given an array and a value, remove all instances of that value in place and return the new length
 * */
#include "../include/preliminary.h"

int removeElement(int A[], int n, int elem){
    int i=-1, j=0;
    for(; j<n; ++j){
        if(A[j] == elem)    continue;
        A[++i] = A[j];
    }
    return i+1;
}

int main(int, char**){
    return 0;
}
