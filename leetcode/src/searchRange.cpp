/*
 * given a sorted array of integers, find the starting and ending position of a given target
 *
 * test case:
 * 1,1   x=1, return [0, 1]
 * 1,2,2,3,4,4  x=4, return [4, 5]; x=1 return [0,0]
 * 1,2,2  x=3, return [-1, -1]
 * */

#include <vector>

using namespace std;

class Solution{

public:
    /*
     * find two index:
     * left bound: A[ld-1] < x && A[ld] == x
     * right bound: A[rd+1] > x && A[rd] == x
     * */
    vector<int> searchRange(int A[], int n, int x){
        vector<int> result;

        if(n == 0 || A[0] > x || A[n-1] < x){
            invalidResult(result);
            return result;
        }

        // find if x exists in A[]
        int l = 0, r = n, lx = -1;
        while(l < r){
            int m = (l + r) >> 1;

            if(A[m] == x){
                lx = m;
                break;
            }

            if(A[m] > x){
                r = m;
            }else{
                l = m+1;
            }
        }

        if(lx == -1){  // x is not found in A[]
            invalidResult(result);
            return result;
        }

        // x exists in A[], find ld
        l = 0, r = lx;  // remember A[lx] == x
        int ld = lx;

        while(l < r){
            int m = (l + r) >> 1;

            if(A[m] == x && (m == 0 || A[m-1] < x)){
                ld = m;
                break;
            }

            if(A[m] < x){
                l = m + 1;
            }else{
                r = m;
            }
        }

        // find lr
        l = lx + 1, r = n;  // remember A[lx] == x
        int rd = lx;

        while(l < r){
            int m = (l + r) >> 1;

            if(A[m] == x && (m == n-1 || A[m+1] > x)){
                rd = m;
                break;
            }

            if(A[m] > x){
                r = m;
            }else{
                l = m + 1;
            }
        }

        result.push_back(ld);
        result.push_back(rd);
        return result;
    }

private:
    inline void invalidResult(vector<int>& list){
        list.clear();
        list.push_back(-1);
        list.push_back(-1);
    }
};

/* unit test is in ../cpp_unittest/searchRange_unittest */
