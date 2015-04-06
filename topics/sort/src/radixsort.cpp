/*
 * radix sort: in place, time O(n), space O(n)
 * assumption: elements are integer, which values do not differ too much
 * 
 * MSD: maximum significant digit
 * LSD: least significant digit
 *
 * test data:
 * 329, 457, 657, 839, 436, 720, 355, 41
 * */
#include "../header/preliminary.h"

/*
 * radix sort start from LSD to MSD
 * it uses count sort for once sort on digit because 
 * 1.time O(n) 
 * 2.stable sort
 */
void radixonce(int *A, int n, int *key){ // sort on one digit can use linear sort like count
    int C[10];
    memset(C, 0, sizeof(C));

    for(int i = 0; i < n; i++){
        C[key[i]] += 1;
    }

    for(int i = 1; i < 10; i++){
        C[i] += C[i-1];
    }

    int B[n];
    memset(B, 0, sizeof(B));

    for(int i = n-1; i > -1; i--){  // key of the descending iteration: stable
        int k = key[i];
        B[C[k] - 1] = A[i];
        C[k]--;
    }

    for(int i = 0; i < n; i++){ // put sorted elements in argument array
        A[i] = B[i];
    }
    return;
}

void radixsort(int* A, int n){
    int digits = 1;
    int key[n];
    while(1){
        memset(key, 0, sizeof(key)); // clear key[]
        bool end = true;

        for(int i = 0; i < n; i++){
            key[i] = (A[i] / digits) % 10;
            if(key[i] > 0)    end = false;
        }
        if(end)    break; // all A[i] are less than digits

        radixonce(A, n, key);
        digits *= 10;
    }

    return;
}

