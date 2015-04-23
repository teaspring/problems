/*
 * countsort: not in place. 
 * assumption: input elements land in a range [0,k)
 * time O(n), space O(n)
 *
 * radix sort: in place
 * assumption: elements are integer, which values do not differ too much
 * time O(n), space O(n)
 * 
 * MSD: maximum significant digit
 * LSD: least significant digit
 *
 * test data:
 * 329, 457, 657, 839, 436, 720, 355, 41
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     * standard implementation of count sort
     * */
    int* countSort(int *A, int n){
        int k = 0; // max of A[]
        for(int i = 0; i < n; i++){
            k = max(A[i], k);
        }

        int C[k + 1]; // index of C[] is value of A[]
        memset(C, 0, sizeof(C));

        for(int i = 0; i < n; i++){
            C[A[i]] += 1;  // C[A[i]] is count of integer A[i] appearance in A[]
        }
        for(int v = 1; v <= k; v++){
            C[v] += C[v-1]; // C[v] is count of all integers in A[] which <= v
        }

        int *B = new int[n](); // array to return, create a new array instance

        for(int i = n-1; i > -1; i--){ // reverse scan to keep stable sort
            int v = A[i];
            B[C[v] - 1] = v; // C[v] is the position where v should be, 1-based
            C[v]--;
        }

        return B;
    }

    /*
     * radix sort, scan from LSD to MSD using count sort for every digit.
     * as count sort is stable, radix sort is stable as well
     * */
    void radixSort(int *A, int n){
        int digits = 1;
        int key[n];
        while(1){
            memset(key, 0, sizeof(key)); // clear key[]
            bool done = true;

            for(int i = 0; i < n; i++){
                key[i] = (A[i] / digits) % 10;
                if(key[i] > 0)    done = false;
            }

            if(done)     break; // all A[i] are less than digits
            radixOnce(A, n, key);
            digits *= 10;
        }
        return;
    }

private:
    /*
     * extented count sort to sort values[] dependent on key[].
     * */
    void radixOnce(int *values, int n, int *key){ // sort on one digit can use linear sort like count
        int C[10];
        memset(C, 0, sizeof(C));

        for(int i = 0; i < n; i++){    
            C[key[i]] += 1;
        }

        for(int i = 1; i < 10; i++){
            C[i] += C[i-1];
        }

        int B[n]; // to store sorted values[] elements
        memset(B, 0, sizeof(B));

        for(int i = n-1; i > -1; i--){ // reverse scan to keep sort stable
            int k = key[i];
            B[C[k] - 1] = values[i];
            C[k]--;
        }

        for(int i = 0; i < n; i++){ // put sorted elements in argument array
            values[i] = B[i];
        }
        return;
    }
};

/* unit test is in ../unittest/radixsort_unittest */
