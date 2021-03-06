/*
 * given an array of non-negative integers, you are initially at [0] of array. each element means your maximum
 * jump length from that position. your goal is to reach [n-1] in minimum jumps. if no path available, return -1
 * 
 * the idea is greedy algorithm, with an arry of furthest preceding index.
 *
 * test data:
 * 0,             res = 0
 * 1 2,           res = 1
 * 2 3 1 1 4,     res = 2
 * 3 4 3 2 5 4 3, res = 3
 * 5 4 0 1 3 6 8 0 9 4 9 1 8 7 4 8,    res = 3
 * 1 1 0 0, res = -1
 * 0 1 1,   res = -1
 * */
#include "../include/preliminary.h"

class Solution{
public:
    /*
    * using simple DP, in time O(n^2), and it has bug!
    * */
    int jump_1(int A[], int n){
        if(n<2)        return 0;
        int *dp = new int[n]();  //dp[i] means minimum jumps from [i] to [n-1]
        int forward=0;
        for(int i=n-2;i>=0;--i){
            int bound = min(i + A[i], n-1);
            for(int t=bound; t>forward; --t){
                //if(dp[t] >= dp[i]-1)     continue;
                dp[i] = dp[i]==0 ? 1+dp[t] : min(dp[i], 1+dp[t]);
            }
            forward = max(forward, bound);
        }
        int res = dp[0];
        delete[] dp;
        return res;
    }

    /*
    * create B[] to facilitate minimum jumps calculation
    * */
    int jump_2(int A[], int n){
        if(n < 2)        return 0;
        int B[n];  //B[i] means the furthest predecessor to [i]
        for(int i=0; i<n; ++i){
            B[i] = i;
        }
        B[0] = -1;
        int pre = 0;
        for(int i=0; i<n-1; ++i){
            int bound = min(n-1, i+A[i]);
            if(bound <= pre)    continue;
            for(int j = bound; j > pre; --j){
                B[j] = i;
            }
            pre = bound;  //forward is the furthest jumping cursor till now
        }

        int res = 0, i = n-1;
        for(i=n-1; i>0 && B[i]<i;){
            ++res;
            i = B[i];
        }
        if(B[i] == i)    res = -1; // impossible to jump from preceding to [i]
        return res;
    }

    void test(){
        string str;
        while(1){
            printf("please input jump length integer array:\n");
            if(getline(cin, str)==0 || str.empty())        break;
            int *arr = new int[str.size()]();
            int n = splitStr2IntArray(str, arr);
            //printf("method1: %d\n", jump_1(arr, n));
            printf("method2: %d\n", jump_2(arr, n));
        }
    }
};

/*
int main(int, char**){
    Solution s;
    s.test();
    return 0;
}
*/
