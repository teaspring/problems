/*
* integer array A[m], B[n] are sorted in ascending both, find the median of all integers in time O(lg(m+n))
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

import java.util.List;
import java.util.ArrayList;
import java.lang.Math;
import java.lang.Double;

public class findmedian{

    public double findMedianSortedArrays(int[] A, int[] B){
        int m = A.length, n = B.length;
        if(m == 0 && n == 0)    return 0;
        if((m + n) % 2 == 1){  // (m+n) is odd
            int mid = (m + n) >> 1;
            return find(A, 0, m, B, 0, n, mid);
        }else{  // (m+n) is even
            int r = (m + n) >> 1;
            int l = r - 1;
            return (find(A, 0, m, B, 0, n, l)
                    + find(A, 0, m, B, 0, n, r)) / 2.0;
        }
    }

    /*
     * recurse find() does not stop skipping subrange of A[] or B[] until one of them is empty
     * */
    private int find(int[] A, int startA, int lengthA, int[] B, int startB,
            int lengthB, int th){ // th is 0 based index
        if(lengthA == 0)    return B[startB + th];  // please not mistake to return B[th] !
        if(lengthB == 0)    return A[startA + th];

        int midA = (lengthA - 1) >> 1;  // index of 1. mid of odd count array; 2. lower mid of even count array
        int midB = (lengthB - 1) >> 1;

        if(A[startA + midA] < B[startB + midB]){  // lower half 'A[]' has more smaller values than 'B[]'
            return find(B, startB, lengthB, A, startA, lengthA, th);  // ensure greater median is in @param A[]
        }

        if(midA + 1 + midB + 1 <= th + 1){ // skip lower half of B[] of length (midB + 1)
            return find(A, startA, lengthA,
                        B, startB + midB + 1, lengthB - (midB + 1),
                        th - (midB + 1));
        }else{  // skip upper half of A[] of length (midA + 1), meanwhile keeping length midA
            return find(A, startA, midA,
                        B, startB, lengthB,
                        th);
        }
    }
}
