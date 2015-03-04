/*
 * max-heap implementation for searchImages.cpp
 * to solve K-minimum problem, we need a max-heap
 * */
#include "stdio.h"
#include <cstring>

using namespace std;

const double eps = 1e-5;

class Utility{
public:
    void quick_sort(double* values, int n, char** names);  // recurse method should not be static

    static void swap_cstr(char** pcstr1, char** pcstr2){
        char* tmp = *pcstr2;
        *pcstr2 = *pcstr1;
        *pcstr1 = tmp;
        tmp = NULL;
        return;
    }

    static void swap_double(double* pd1, double* pd2){
        double tmp = *pd2;
        *pd2 = *pd1;
        *pd1 = tmp;
        return;
    }
};

    /*
     * quick sort char*[] and double[] with key of double[]
     * */
    void Utility::quick_sort(double* values, int n, char** names){
        if(n < 2)    return;
        double *p = values, *q = values - 1, *t = values + n-1;
        while(p < t){
            if((*p - *t) < eps){
                q++;
                swap_double(q, p);
                swap_cstr(names + (q - values), names + (p - values));
            }
            p++;
        }
        q++;
        swap_double(q, t);
        swap_cstr(names + (q - values), names + (t - values));

        quick_sort(values, (q - values), names);
        quick_sort(q + 1, n - 1 - (q - values), names + (q + 1 - values));
    }

class MaxHeap{
public:
    MaxHeap(double* keys, char** values, int n){
        Keys = keys;
        Values = values;
        N = n;
        sorted = false;
    }
    virtual ~MaxHeap(){
        Keys = NULL;
        Values = NULL;
    }

    void heap_build();

    void heap_insert(double nkey, char* nval);

    void heap_sort_asce();

private:
    void max_heapify(int idx, int length);

    inline int Left(int i){
        return 2*(i + 1) - 1;
    }

    inline int Right(int i){
        return 2*(i + 1);
    }

private:
    double* Keys;  // double[N] in use for invoker
    char** Values; // char*[N] in use for invoker
    int N;
    bool sorted;
};

    /*
     * enable [i] is maximum of subtree with root of [i]
     * */
    void MaxHeap::max_heapify(int i, int length){
        if(length <= 1)    return;
        int l = Left(i), r = Right(i);
        int largest = i;
        if(l < min(N, length) && Keys[l] - Keys[i] > eps){
            largest = l;
        }
        if(r < min(N, length) && Keys[r] - Keys[largest] > eps){
            largest = r;
        }
        if(largest != i){
            Utility::swap_double(Keys + largest, Keys + i);
            Utility::swap_cstr(Values + largest, Values + i);
            max_heapify(largest, length);
        }
    }

    /*
     * build whole heap sorted
     * */
    void MaxHeap::heap_build(){
        for(int i = N >> 1; i >= 0; i--){
            max_heapify(i, N);
        }
        sorted = true;
    }

    /*
     * attempt to insert a new key/value to a sorted heap
     * */
    void MaxHeap::heap_insert(double nkey, char* nval){
        if(!sorted)        heap_build();
        if(nkey - Keys[0] >= eps)    return;

        Keys[0] = nkey;
        Values[0] = nval;
        max_heapify(0, N);
    }

    /*
     * sort the heap(array) in ascending order in place
     * after that, [0] is NOT the max of whole tree
     * */
    void MaxHeap::heap_sort_asce(){
        if(!sorted)    heap_build();
        int hsize = N;
        for(int i = N-1; i >= 0; i--){
            Utility::swap_double(Keys + i, Keys + 0);
            Utility::swap_cstr(Values + i, Values + 0);
            hsize--;
            max_heapify(0, hsize);
        }
        sorted = false;  // donot forget
    }

