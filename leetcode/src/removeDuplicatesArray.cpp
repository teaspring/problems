/*
 * given a sorted array, remove the duplicates from it in-place, return the new array size.
 * */
#include <cstring>

using namespace std;

class Solution{

public:
    /*
     * problem I: every value is allowed to appear only once
     * input:  1,1,2,2
     * output: 1,2
     *
     * this solution is the best
     * */
    int remove(int A[], int n){
        if(n < 2)    return n;

        int len = 1, itor = 1;
        while(itor < n){
            if(A[itor] != A[len-1]){ // compare new value - A[itor] and the last verified value - A[len-1]
                if(len < itor)    A[len] = A[itor];
                len++;
            }
            itor++;
        }
        return len;
    }

    /*
     * problem II: every value is allowed to appear twice at most.
     * input:  1,1,1,2,2,3
     * output: 1,1,2,2,3
     *
     * this solution is the best
     * */
    int removeII(int A[], int n){
        if(n <= 2)    return n;

        int len = 2, itor = 2;
        while(itor < n){
            if(A[itor] != A[len - 2]){ // compare new value - A[itor] and one to last verified one - A[len-2]
                if(len < itor)    A[len] = A[itor];
                len++;
            }
            itor++;
        }
        return len;
    }
};

/* unit test is in ../cpp_unittest/removeDuplicatesArray_unittest */
