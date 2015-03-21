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

#include "../include/preliminary.h"

class Solution{

    double find(int *a, int n, int *b, int m, int th){ // th is 0-based
        if(n == 0)    return (double)b[th];
        if(m == 0)    return (double)a[th];
    
        int mida = (n-1) >> 1;
        int midb = (m-1) >> 1;
        if(a[mida] < b[midb])    return find(b, m, a, n, th); //ensure greater median in a[]
        if(mida + 1 + midb + 1 <= th + 1){ // case 1: skip half of b[]
            return find(a, n, b + (midb + 1), m - (midb + 1), th - (midb + 1));
        }else{  // case 2: skip half elements in a[], it always happens after case 1
            return find(a, mida, b, m, th);
        }
    }

public:
    double findMedianSortedArrays(int *A, int m, int *B, int n){
        if(m == 0 && n == 0)    return 0;
        if((m+n) & 1){  // (m+n)%2 == 1, including m+n == 1
            int mid = (m+n) >> 1;
            return find(A, m, B, n, mid);
        }else{  // (m+n)%2 == 0
            int r = (m+n) >> 1;
            int l = r - 1;
            return (find(A, m, B, n, l) + find(A, m, B, n, r)) / 2.0;
        }
    }
};

