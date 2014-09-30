/*
 * find the contiguous subarray within an array(containing at least one number) which has the largest product
 *
 * test cases:
 * [-2], return -2
 * [-2,0,-1],  return 0
 * [2,-2,3], return 3
 * [1,-2,2,-3,-2,-3,-3], return 108
 * [2,3,-2,4], return 6
 * [-2,0,2,0,3], return 3
 * [-2, -1, -3], return 3
 * [-2,2,0,0,3,2], return 6
 * */
#include "../include/preliminary.h"

class Solution{
public:
    int maxProduct(int A[], int n){
        if(n==1)    return A[0];
        int i=0;
        while(i<n && A[i]==0)    i++;
        if(i==n)    return 0;
        int result = A[i];
        for(int j=i+1; j <= n; j++){  // [i,j) is the contiguous range without 0
            if(j==n || A[j]==0){
                result = max(0, max(result, maxProductRange(A, i, j))); // not less than delimeter - 0
                i=j+1;
                while(i<n && A[i]==0)    i++;  // A[i] is next non-zero
                j=i;
            }
        }
        return result;
    }

private:
    int maxProductRange(int A[], int l, int r){
        if(l == r-1)    return A[l];
        int prod = 1;
        for(int i=l; i<r; i++){
            prod *= A[i];
        }
        if(prod > 0)    return prod;
        int pl=1, pr=1, i=l, j=r-1;

        while(i < r-1 && A[i] > 0){
            pl *= A[i++];
        }
        if(i == r-1)    return pl;    // A[r-1] < 0

        while(j > l && A[j] > 0){
            pr *= A[j--];
        }
        if(j == l)    return pr;    // A[l] < 0

        if(i==j){
            return max(pl, pr);    // A[i] < 0
        }else{
            return max(prod/(pl * A[i]), prod/(pr * A[j]));
        }
    }

public:
    void test(){
        string str;
        while(1){
            cout << "please input int array" << endl;
            if(getline(cin, str)==0 || str.empty())    break;
            int A[str.size()];
            int n = splitStr2IntArray(str, A);
            cout << maxProduct(A, n) << endl;
        }
        return;
    }
};

/*
 *  apply unittest code instead
int main(){
    Solution s;
    s.test();
    return 0;
}
*/
