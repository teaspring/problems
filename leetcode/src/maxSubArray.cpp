/*
 * find the contiguous subarray within an array(containing at least one number) which has the largest sum.
 * Furthermore, if you have figured out O(n) solution, try coding another using divide-and-conquer approach.
 *
 * test case:
 * [-1], -1
 * [-2, -3, -4, -1, -2], -1    //as subsrray has one element at least, test case of all negative elements needs careful process
 * [-1, 4, -2, 3, 1, -2], 6
 * [2, 2, -4, 1, 2, -1], 4
 * */
#include <algorithm>

using namespace std;

class Solution{

public:
    /*
     * time O(n) but a little complex
     * */
    int maxSubArray_01(int A[], int n){
        int sum = 0; // max sum of sub array including A[i]
        int mx = A[n-1]; // max element in A[]
        int msm = 0; // max sum of sub array in whole A[]

        for(int i = n-1; i >= 0; --i){
            mx = max(mx, A[i]);  // max element of all, used to alert if all are negative

            if(A[i] <= 0){
                if(A[i] + sum <= 0){
                    sum = 0;
                }else{
                    sum += A[i];
                }
            }else{
                sum += A[i];
                msm = max(msm, sum); // msm can only be updated when A[i] > 0 because sum = 0 may be invalid
            }
        }

        return mx < 0 ? mx : msm;  // msm is 0 at least, return value depends on mx
    }

    /*
     * time O(n)
     * */
    int maxSubArray_02(int A[], int n){
        int mSum = A[0];   // max sum
        int cSum = max(A[0], 0);  // current sum

        for(int i = 1; i < n; ++i){
            cSum += A[i];
            mSum = max(mSum, cSum);
            cSum = max(cSum, 0);  // reset if negative currently
        }

        return mSum;
    }

    /*
     * time O(n), less variabls than solution2
     * */
    int maxSubArray_03(int A[], int n){
        int best = A[0];    // max sum
        int curr = A[0];    // current sum

        for(int i = 1; i < n; ++i){
            curr = max(curr, 0) + A[i];
            best = max(curr, best);
        }

        return best;
    }

    /*
     * divide-and-conquer, time O(nlgn)
     * */
    int maxSubArray_04(int A[], int n){  // return max sum among the range of A[]
        if(n == 1)    return A[0];

        int l = n >> 1;

        int lmx = maxSubArray_04(A, l);
        int rmx = maxSubArray_04(A+l, n-l);

        // lhalf and rhalf must be initialized as bounds A[l-1] and A[l], avoiding returning 0 when negative !
        int lhalf = A[l-1], rhalf = A[l];
        int tmp = lhalf;

        for(int i = l-2; i >= 0; --i){  // leftward from middle bound
            tmp += A[i];
            lhalf = max(lhalf, tmp);
        }

        tmp = rhalf;

        for(int i = l+1; i < n; ++i){  // rightward from middle bound
            tmp += A[i];
            rhalf = max(rhalf, tmp);
        }

        return max(max(lmx, rmx), lhalf + rhalf);
    }
};

/* unit test is in ../cpp_unittest/maxSubArray_unittest */
