/*
 * given an array of n, integers 0,1,2 for color red, white, and blue. sort it in order 0/1/2 in one-pass with space O(1)
 * 
 * */
#include "../include/preliminary.h"

class Solution{

public:
    void sortColors_1(int A[], int n){
        if(n <= 1)    return;

        int *p = A-1; // to put element 0
        int *q = A;   // cursor
        int *t = A + n;  // to put element 2

        while(q != t){
            if(*q == 2){
                t--;
                swap(q, t);
                continue;   // NOTE: value swapped from [t] is at right of q which has not been checked yet
            }else if(*q == 0){
                p++;
                if(q > p)    swap(q, p);
            }
            q++;
        }
    }

    void sortColors_2(int A[], int n){
        if(n <= 1)    return;

        int *p = A-1; // to put element 0
        int *q = A;   // cursor
        int *t = A + n; // to put element 2

        while(q != t){
            if(*q == 0){
                p++;
                if(q > p)    swap(q, p);
            }else if(*q == 2){
                t--;
                swap(q, t);
                continue;   // NOTE: recheck of the swapped value from [t] is necessary
            }
            q++;
        }
    }

private:
    void swap(int *pa, int *pb){
        int tmp = *pa;
        *pa = *pb;
        *pb = tmp;
    }
};

/* unit test is in ../cpp_unittest/sortColor_unittest */
