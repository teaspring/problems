/*
 * given a sorted array and a target value, return index if it is found.
 * if not, return the index where it would be inserted in order. as to invoke vector.insert()
 * assume array is in ascending order without duplicates.
 * */

using namespace std;

class Solution{

public:
    /*
     * it must be binary search
     * */
    int searchInsert(int A[], int n, int x){
        int v = 0, u = n;  // u is exclusive upper bound
        while(v < u){
            int m = (v+u) >> 1;

            if(A[m] == x)    return m;

            if(A[m] > x){
                if(m == 0 || A[m-1] < x){
                    return m;
                }else{
                    u = m;
                }
            }else{
                if(m == n-1 || A[m+1] > x){
                    return m+1;
                }else{
                    v = m+1;
                }
            }
        }
        return v;
    }
};

/* unit test is in ../cpp_unittest/searchInsert_unittest */
