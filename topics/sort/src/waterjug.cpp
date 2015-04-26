/*
 * <IntroductionToAlgorithm> exercise 8-4
 * given n red jugs and n blue jugs, all of different shapes and sizes. For each red jug, there is blue jug mapping it with the same
 * capacity of water. Assume you have a unit operation of selecting one red jug and pour its water into another blue jug.
 *
 * Q: group all the red jugs and blue jugs in time O(nlgn)
 *
 * test data:
 * 1,3,10,8,12,5,15,7,2,11
 * 5,2,11,3,8,12,1,15,10,7
 * */
#include <cstdio>
using namespace std;

class Solution{

public:
    /*
     * extended quick sort
     * */
    void sortjugs(int *A, int *B, int n){
        if(n < 2)    return;

        int leftSize1 = quickSortOnce(B, n, A + n-1); // use A[n-1] as sentinel to split A[] and B[]
        quickSortOnce(A, n, B + leftSize1); // leftSize1 must equals to leftSize2

        sortjugs(A, B, leftSize1);
        sortjugs(A + leftSize1 + 1, B + leftSize1 + 1, n-1 - leftSize1);
    }

private:
    // swap values of two int*
    void myswap(int *pa, int *pb){
        int tmp = *pb;
        *pb = *pa;
        *pa = tmp;
    }

    /*
     * use argument sentinel as delimeter, split A[] of length n to two parts
     * return left partition length
     * */
    int quickSortOnce(int *A, int n, int *sentinel){
        int x = *sentinel;
        int *p = A, *q = A-1, *s = NULL;
        while(p < A + n){  // quick sort B[] with sentinel of A[n-1]
            if(*p == x){
                s = p;
            }else if(*p < x){
                q++;
                myswap(p, q);
                if(s == q){ // NOTE: as initial element of *p which is less than x is swpped to *q, keep s pointing to initial value
                    s = p;
                }
            }
            p++;
        }

        /*
         * now s must be ahead of q, q pointing to last element which is less than sentinel
         * if s == q+1, nothing to do, s becomes the delimeter char naturally
         * if s > q+1, insert s to position of q+1
         * */
        q++;
        if(s > q){ // *s = x
            myswap(s, q);
        }
        return q - A;
    }
};

/* unit test in ../unittest/waterjug_unittest */
