/*
 * bubble sort, inefficient sort algorithm
 * selection sort, a bit better 
 * */
#include "../header/preliminary.h"

void myswap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * bubble method, time O(n^2), with excessive use of swap in each internal iteration
 */
void bubblesort(int *A, int n){  //in descending order
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j > i; j--){ // bottom up, compare two adjacent elements and swap
            if(A[j-1] > A[j]){
                myswap(A[j-1], A[j]); //the minimum during [i,n) rises to [i] like bubble
            }
        }
    }
    return;
}

/*
 * improvement is to reduce swap() to once in each internal iteration. 
 * its average efficiency is a little worse than insertionsort
 * */
void selectionsort(int *A, int n){
    for (int i = 0; i < n-1; i++){
        int sel = i;
        for(int j = n-1; j > i; j--){
            if(A[j] < A[sel]){  //find the minimum [sel] among (i,n)
                sel = j;
            }
        } 
        if(sel != i){   //swap [sel] and [i] if in need 
            myswap(A[i], A[sel]);
        }
    }
    return;
}

/*
 * basic insertion sort. in internal iteration, stops till finding its correct postion.
 * optimize selection sort, copy rest elements instead of swap.
 * high efficient to sort linked list
 * */
void insertionsort(int *A, int n){
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
