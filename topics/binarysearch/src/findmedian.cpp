/*
* int array A[m], B[n] are sorted already(ascending), find the median of all integers in time O(lg(m+n))
*
* note:
* 1.case of m==n is in <IntroductionToAlgorithm> chapter9 median and order statistics, exercise 9.3-8
* 2.case of m!= n is an interview problem
* 
* test case:
*
* -----single----
* {1}, {1}
* {1}, {2,3,4}
* {1}, {2,3,4,5}
* {2}, {1,3,4}
* {3}, {1,2,4}
* {1,2,3,5,6}, {4}
* {1,2,3,4}, {5}
*
* -----empty-----
* {}, {1,2,3,4}
* {1,2,3}, {}
*
* ---- m == n ----
* {1,2}, {3,4}
* {1,3}, {2,4}
* {1,2}, {1,2}
* {1,4}, {2,3}
*
* ----- m != n -----
* {1,3,5,8}, {2,4,6,7}
* {1,1}, {2,3,4,5}
* {1,2,3}, {4,5}
* {6,7,8}, {1,2,3,4,5}
* {0,1,2}, {4,5,6,7}
* {4,5,6,7}, {3,8,9}
*/

class Solution{

public:
    double findMedianSortedArrays(int *A, int m, int *B, int n){
        if(m == 0 && n == 0)    return 0;

        if((m+n) & 1){  // (m+n) % 2 == 1, including m+n == 1
            int mid = (m+n) >> 1;
            return find(A, m, B, n, mid);
        }else{  // (m+n) % 2 == 0
            int r = (m+n) >> 1;
            int l = r - 1;
            return (find(A, m, B, n, l) + find(A, m, B, n, r)) / 2.0;
        }
    }

private:
    /*
     * @param n, m are sizes, th is 0-based index
     * */
    double find(int *A, int n, int *B, int m, int th){
        if(n == 0)    return (double)B[th];
        if(m == 0)    return (double)A[th];

        int mida = (n-1) >> 1; // upper mid index
        int midb = (m-1) >> 1;
        if(A[mida] < B[midb])    return find(B, m, A, n, th); // ensure greater median is in A[]

        if(mida + 1 + midb + 1 <= th + 1){ // both pre halves sum count is less than total mid, skip pre half of B[]
            int skipped = midb + 1; // skipped size, including B[midb]
            return find(A, n, B + skipped, m - skipped, th - skipped);
        }else{  // total mid (th) should be in sum set of both pre halves, skip latter half of A[] which includes A[mida]
            return find(A, mida, B, m, th);
        }
    }
};

/* unit test is in ../unittest/findmedian_unittest */
