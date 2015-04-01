/*
 * max-heap implementation for searchImages.cpp
 * to solve K-minimum problem, we need a max-heap
 *
 * */
#include "stdio.h"
#include <cstring>

using namespace std;

const float eps = 1e-5;  // for float type compare

class Utility{
public:
    void quick_sort(int *values, int n, char **names);  // recurse method should not be static

    static void swap_cstr(char **pcstr1, char **pcstr2){
        char *tmp = *pcstr2;
        *pcstr2 = *pcstr1;
        *pcstr1 = tmp;
        tmp = NULL;
        return;
    }

    static void swap_int(int *pd1, int *pd2){
        int tmp = *pd2;
        *pd2 = *pd1;
        *pd1 = tmp;
        return;
    }
};

/*
* quick sort values of char*[] with key of int[]
* */
void Utility::quick_sort(int *values, int n, char **names){
    if(n < 2)    return;
    int *p = values, *q = values - 1, *t = values + n-1; // *t as sentinel
    while(p < t){
        if(*p < *t){ // element less than *t is put ahead
            q++;
            swap_int(q, p);
            swap_cstr(names + (q - values), names + (p - values));
        }
        p++;
    }

    q++;
    swap_int(q, t);
    swap_cstr(names + (q - values), names + (t - values));

    quick_sort(values, (q - values), names);
    quick_sort(q + 1, n - 1 - (q - values), names + (q + 1 - values));
}

/*
 * Maximum Heap to get top N minimum elements
 * */
class MaxHeap{
public:
    MaxHeap(int *keys, char **values, int n){
        Keys = keys;
        Values = values;
        N = n;
        heapified = false;
    }
    virtual ~MaxHeap(){
        Keys = NULL;
        Values = NULL;
    }

    void heap_build();

    void heap_insert(int nkey, char *nval);

    void heap_sort();

private:
    void max_heapify(int idx, int length);

    inline int Left(int i){
        return 2*(i + 1) - 1;
    }

    inline int Right(int i){
        return 2*(i + 1);
    }

private:
    int* Keys;  // float[N] managed by invoker
    char** Values; // char*[N] managed by invoker
    int N;
    bool heapified;
};

/*
* enable [i] is maximum of subtree with root of [i]
* */
void MaxHeap::max_heapify(int i, int length){
    if(length <= 1)    return;
    int l = Left(i), r = Right(i);
    int largest = i;

    if(l < min(N, length) && Keys[l] > Keys[i]){
        largest = l;
    }

    if(r < min(N, length) && Keys[r] > Keys[largest]){
        largest = r;
    }

    if(largest != i){
        Utility::swap_int(Keys + largest, Keys + i);
        Utility::swap_cstr(Values + largest, Values + i);
        max_heapify(largest, length);
    }
}

/*
* build whole heap heapified
* */
void MaxHeap::heap_build(){
    for(int i = N >> 1; i >= 0; i--){
        max_heapify(i, N);
    }
    heapified = true;
}

/*
* attempt to insert a new key/value to a heapified heap
* */
void MaxHeap::heap_insert(int nkey, char *nval){
    if(!heapified)    heap_build();

    if(nkey >= Keys[0])    return;

    Keys[0] = nkey;

    delete Values[0]; // this char* will be replaced, so delete it to avoid memory leak
    Values[0] = nval;

    max_heapify(0, N);
}

/*
* sort the heap(array) in ascending order in place
* after that, [0] is NOT the max of whole tree
* */
void MaxHeap::heap_sort(){
    if(!heapified)    heap_build();
    int hsize = N;
    for(int i = N-1; i >= 0; i--){
        Utility::swap_int(Keys + i, Keys + 0);
        Utility::swap_cstr(Values + i, Values + 0);

        hsize--;
        max_heapify(0, hsize);
    }
    heapified = false;  // donot forget
}
