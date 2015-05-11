/*
 * given an array of non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 * */

class Solution{

public:
    /*
     * one-pass solution: scan leftward and rightward depending on which of left/right wall is lower
     * */
    int trapWater(int A[], int n){
        if(n <= 2)    return 0;

        int l = 0, r = n-1;  // cursors
        int sum = 0;

        while(l < r){

            int w = 0;

            if(A[l] < A[r]){ // scan from lower wall of left/right walls
                int h = A[l++];  // left wall height

                while(h > A[l]){
                    w += h - A[l];
                    ++l;
                }
            }else{
                int h = A[r--]; // right wall height

                while(h > A[r]){
                    w += h - A[r];
                    --r;
                }
            }

            sum += w;
        }

        return sum;
    }
};

/* unit test is in ../cpp_unittest/trapWater_unittest */
