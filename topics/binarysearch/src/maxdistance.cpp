/*
* from leetcode. given an integer array A, find maximum j-i subjected to the constraint of A[i] < A[j]
* solution 1: binary search with linear scan
* solution 2: twice linear scan, key is the Rmax[]
* 
* test data:
* 1 4 3 5 2 7 5 4
* 6 5 4 3 2 1
* 1 2 3 4 5 6
*/

#include <cstring>
using namespace std;

class Solution{
public:
    /*
    * achieve linear search, time O(n) and space O(n)
    * */
    int maxDistance(int *A, int n, int& left){
        if(n < 2)    return 0;

        int Rmax[n];  // Rmax[i] is the maximum value on right side of A[i], inclusive of A[i]
        memset(Rmax, 0, sizeof(Rmax));

        Rmax[n-1] = A[n-1];
        for(int i = n-2; i >= 0; i--){ // once scan
            Rmax[i] = max(A[i], Rmax[i+1]);
        }
 
        int i = 0, j = 1, maxDiff = 0;
        while(j < n){ // once more scan
            if(A[i] < Rmax[j]){ // index x exists in range [j, n) that A[i] < A[x] and i < x
                if(maxDiff < j-i){
                    maxDiff = j-i;
                    left = i;
                }
            }else{
                ++i;
            }
            ++j; // j moves no matter whether i moves, ensure j > i stands
        }

        return maxDiff;
    }
};
