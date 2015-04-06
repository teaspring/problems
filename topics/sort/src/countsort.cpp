/*
 * "IntroductionToAlgorithm" chapter8    
 * countsort: not in place, 
 * assumption: input elements land in a range [0,k)
 * time O(n), space O(n)
 *
 * point: since it is stable sort in O(n), it can be used by radix sort
 * test data:
 * 0,2,3,2,1,5,3,4
 */
#include "../header/preliminary.h"

int* countsort(int *A, int n){
    int k = 1;
    for(int i = 0; i < n; i++){
        k = max(A[i] + 1, k); // k is maximum A[] + 1
    }

    int C[k]; // index of C[] is value of A[]
    memset(C, 0, sizeof(C));

    for(int i = 0; i < n; i++){
        C[A[i]] += 1;  // C[A[i]] is count of integer A[i] appearance in A[]
    }
    for(int i = 1; i < k; i++){
        C[i] += C[i-1]; // C[i] is count of all int [0, i] appearance in A[]
    }

    int B[n]; // to place sorted A[]
    memset(B, 0, sizeof(B));
    for(int i = n-1; i > -1; i--){ // reverse scan to keep stable sort
        int v = A[i];
        B[C[v] - 1] = v;
        C[v]--;
    }

    return B;
}
