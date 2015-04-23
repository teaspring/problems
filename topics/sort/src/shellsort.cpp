/*
 * shell sort:
 * one progression sort based on insertion sort. in-place, not stable
 * generally it is thought to be better than direct insert sort, around time O(n(lgn)^2)
 *
 * different implementation differs in choice of group step only
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
    * D.Shell initial version
    * */
    void shellSort_Sh(int *p, int n){
        for(int h = n/2; h > 0; h /= 2){ // different h is used from large to small
            /* h = n/2, n/4, n/8, ... 1 */
            insertionSortInStep(p, n, h);
        }
        return;
    }

    /*
    * Lazarus-Frank, 1960'
    * */
    void shellSort_LF(int *p, int n){
        for(int h = n/2; h > 0; h /= 2){ // different group step
            if(h % 2 == 0)    h--;
            insertionSortInStep(p, n, h);
        }
        return;
    }

    /*
    * Hibband, 1963
    * */
    void shellSort_Hb(int *p, int n){
        int h;
        for(h = 1; h <= n/4; h = h*2 + 1);

        for(; h > 0; h = (h-1)/2){
            /* h = 1,3,7,15,31,...2^i-1*/
            insertionSortInStep(p, n, h);
        }
        return;
    }

    /*
    * Papernov-Stasevich, 1965. this is nearly reach the performance of Knuth's
    * */
    void shellSort_PS(int *p, int n){
        int h;
        for(h = 2; h <= n/4; h = h*2 - 1);

        for(; h > 1;){  // different group step
            h = (h == 3) ? 1 : (h+1)/2;
            /* h = 1,3,5,9,17,33...2^i+1 */
            insertionSortInStep(p, n, h);
        }
        return;
    }

    /*
    * Knuth, suggest in case n<1000. till now, this is nearly the best
    * */
    void shellSort_Kn(int *p, int n){
        int h;
        for(h = 1;h <= n/9; h = h*3 + 1);

        for(; h > 0; h = h/3){ // different group step
            /* h = 1,4,13,40,121,364...3^h+1*/
            insertionSortInStep(p, n, h);
        }
        return;
    }

    /*
    * Gonnet's, 1991
    * */
    void shellSort_Go(int *p, int n){
        int h;
        for(h = n; h > 1;){ // different group step
            h = (h < 5) ? 1 : (h*5 - 1) / 11;

            insertionSortInStep(p, n, h);
        }
        return;
    }

private:
    /*
     * @param h is step, n is total size of A[]
     * */
    void insertionSortInStep(int *A, int n, int h){
        for(int i = h; i < n; i++){
            int tmp = A[i];
            int j = i-h;
            /*
             * insert A[i] to right place in sub array which is made up of {A[0],..A[i-2h], A[i-h], A[i]}
             * */
            for(; j >= 0 && A[j] > tmp; j -= h){
                A[j+h] = A[j];
            }
            A[j+h] = tmp;
        }
    }
};

/* unit test is in ../unittest/shellsort_unittest/ */
