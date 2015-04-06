/*
 * merge sort, "IntroductionToAlgorithm chapter2"
 * divide-and-conquer
 * */

#include "../header/preliminary.h"
const int MAXIM = 0xffff;

/*
 * trick: use one appendix sentinel at tail to avoid checking which sub array is empty
 * */
void merge(int *A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int AL[n1 + 1];
    memset(AL, 0, sizeof(AL));

    for(int i = p; i <= q; i++){
        AL[i - p] = A[i];
    }
    AL[q - p + 1] = MAXIM;

    int AR[n2 + 1];
    memset(AR, 0, sizeof(AR));

    for(int i = q + 1; i <= r; i++){
        AR[i - q - 1] = A[i];
    }
    AR[r - q] = MAXIM;

    int i = 0, j = 0;
    for(int k = p; k <= r; k++){
        if(AL[i] <= AR[j]){
            A[k] = AL[i];
            i++;
        }else{
            A[k] = AR[j];
            j++;
        }
    }
}

/*
 * how to use: for A[] of n elements, call mergesort(A, 0, n-1)
 * */
void mergesort(int *A, int p, int r){  // p,r are inclusive
    if(p < r){
        int q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);

        merge(A, p, q, r);
    }
}
