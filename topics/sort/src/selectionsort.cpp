/*
 * bubble sort:
 * time O(n^2), in place. excessive swap in every time internal iteration
 *
 * selection sort:
 * time O(n^2), in place
 * improvement on bubble sort by reducing swap to once in each internal iteration.
 * its average efficiency is a little worse than insertionsort
 *
 * insertion sort:
 * in internal iteration, stops till finding its correct postion.
 * improvement on selection sort with copy instead of swap.
 * for linked list sort, it is very efficient.
 *
 * merge sort:
 * divide-and-conquer
 *
 * */
#include "../include/preliminary.h"

static const int MAXIM = 0xffff;

class Solution{

public:
    void bubbleSort(int *A, int n){  //in descending order
        for(int i = 0; i < n-1; i++){
            for(int j = n-1; j > i; j--){ // bottom up, compare two adjacent elements and swap
                if(A[j-1] > A[j]){
                    swapInt(A[j-1], A[j]); // the minimum during [i,n) rises to [i] like bubble
                }
            }
        }
        return;
    }

    void selectionSort(int *A, int n){
        for (int i = 0; i < n-1; i++){
            int sel = i;
            for(int j = n-1; j > i; j--){
                if(A[j] < A[sel])    sel = j; // find the minimum [sel] among (i,n)
            }

            if(sel != i)    swapInt(A[i], A[sel]); // only swap in need
        }
        return;
    }

    void insertionSort(int *A, int n){
        for(int i = 1; i < n; i++){
            int temp = A[i];
            int j = i-1;
            for(; j >= 0 && A[j] > temp; j--){
                A[j+1] = A[j];
            }
            A[j+1] = temp;
        }
        return;
    }

    void mergeSort(int *A, int n){
        mergesort(A, 0, n-1);
    }

private:
    /*
     * divide-and-conquer
     * */
    void mergesort(int *A, int p, int r){  // p,r are inclusivea
        if(p < r){
            int q = (p + r) / 2;
            mergesort(A, p, q);
            mergesort(A, q + 1, r);

            merge(A, p, q, r);
        }
    }

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

    void swapInt(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};
