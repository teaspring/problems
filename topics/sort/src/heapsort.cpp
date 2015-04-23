/*
 * "introduction to algorithm" chapter6, heap sort
 * 
 * note: 
 * 0. max-heap can solve k-minimum problem where the maximum(root) can be used as sentinel(any key > root can enter the heap)
 *    min-heap can solve k-maximum heap while the minimum root can be sentinel
 *
 * 1. in native implementaion, index of heap is 1-based
 * 2. heap sort: time O(nlgn), can be in place sort
 * */
#include "../header/preliminary.h"

const int MINUSLIMIT = -0xffff;

template<typename T>
void myswap(T* pa, T* pb){
    T tmp = *pb;
    *pb = *pa;
    *pa = tmp;
    tmp = 0;
}

inline int Left(int i){ // here index is 1-based
    return 2*i;
}

inline int Right(int i){
    return 2*i + 1;
}

inline int Parent(int i){
    return i/2;
}

/*
 * enable [i] is max of subtree as its root, via top-down swap
 * time O(lgn)
 * */
void max_heapify(int *A, const int n, int i){
    if(n == 1)    return;

    int l = Left(i), r = Right(i);
    int largest = i;

    if(l <= n && A[l] > A[i]){
        largest = l;
    }

    if(r <= n && A[r] > A[largest]){
        largest = r;
    }

    if(largest != i){
        myswap(A + largest, A + i);
        max_heapify(A, n, largest);
    }
}

/*
 * build whole tree sorted, ensure A[1...n] are elements in scope
 * time O(nlgn)
 * */
void build_max_heap(int *A, const int n){
    for(int i = n/2; i > 0; i--){
        max_heapify(A, n, i);
    }
}

/*
 * for a max heap(array), return an array in ascending order which is minium N elements
 * time O(nlgn)
 * */
void heap_sort_desc(int *A, const int n){
    build_max_heap(A, n);
    int hsize = n;
    for(int i = n; i > 0; i--){
        myswap<int>(A + i, A + 1);

        hsize--;
        max_heapify(A, hsize, 1);
    }
}

/*
 * operation pop() for priority_queue implemented in max-heap A[1..n]
 * time O(lgn)
 * */
int heap_extract_max(int *A, const int n){ // pop max element(root of max heap)
    if(n < 1)    return -1;

    int max = A[1];
    A[1] = A[n];
    A[n] = MINUSLIMIT;  // A[n] is useless now
    max_heapify(A, n-1, 1);
    return max;
}

/*
 * increase A[i] to k via bottom-up swap
 * time O(lgn)
 * */
void heap_increase_key(int *A, const int n, int i, int key){
    if(i > n || key < A[i])    return;

    A[i] = key;
    while(i > 1 && A[Parent(i)] < A[i]){    //A[1] is root without parent
        myswap<int>(A + Parent(i), A + i);
        i = Parent(i);
    }
}

/*
 * build a priority queue of max-heap via insert
 * precedence: the basic array support [n+1] boundary
 * time O(lgn)
 *
 * note: A[] should be allocated enough space already to afford [n+1]
 * */
void max_heap_insert(int *A, const int n, int key){   //build a priority queue(max heap) via insert
    A[n+1] = MINUSLIMIT;
    heap_increase_key(A, n + 1, n + 1, key);
}
