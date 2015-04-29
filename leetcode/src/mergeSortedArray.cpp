/*
 * given two sorted integer arrays A and B, merge B into A as one sorted array
 * assume A has enough space with size of m+n at least
 *
 * test case:
 * 3,4,5 | 1, 2
 * 1,2,2,5 | 0,2,3
 * */
#include <cstring>

using namespace std;

class Solution{

public:
    /*
     * in array, [0, m) and [m, m+n) are sorted separately
     * */
    void merge(int A[], int m, int B[], int n){
        if(n == 0)    return;

        for(int i = 0; i < n; ++i){
            A[m+i] = B[i];
        }

        if(m == 0)    return;

        int *p = A, *q = A + m;
        while(p < q && q < A+m+n){
            if(*p > *q){
                swap(p, q);
                sortHead(q, A+m+n - q);
                continue;
            }
            ++p;
        }
    }

private:
    void swap(int *pa, int *pb){
        int tmp = *pb;
        *pb = *pa;
        *pa = tmp;
    }

    /*
     * A[] is sorted in order initially, replace a new int to A[0], it keeps it sorted in order
     * and A[0] remains minium of A[]
     * */
    void sortHead(int A[], int n){
        if(n < 2)    return;

        for(int *p = A+1; p < A+n; ++p){
            if(*(p-1) > *p){
                swap(p-1, p);
            }
        }
    }
};

/* unit test is in ../cpp_unittest/mergeSortedArray_unittest */
