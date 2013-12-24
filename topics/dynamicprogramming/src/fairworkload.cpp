 /*
  * regressive problem of Painter's partition problem on leetcode. Actually, it appears on topcoder as "fair work load"
  * 
  * test data:
  * {1,2,3,4,5,6,7,8,9}, k=3, res = 17
  * {1,3,5,5,4,7,2}, k=3, res = 9
  */
#include "../header/preliminary.h"

const int UNLIMIT = 0xffff;

inline int max(int a, int b){
    return a>b ? a : b;
}

/*
 * dp[i][j] = min{max{dp[i-1][j-t],t}, t=A[n-1], +A[n-2], +A[n-3],...+A[0]}
 */
int fairworkload_01(int *A, int n, int k){         //work list of A, with n tasks, divide to k partitions
    int sum = 0;
    for(int i=0;i<n;++i){
        sum += A[i];
    }
    int **dp = new int*[k+1];
    for(int i=0;i<k+1;++i){
        dp[i] = new int[sum+1]();
    }
    for(int j=0;j<sum+1;++j){
        dp[1][j] = j;
    }
    
    for(int i=2;i<=k;++i){
        int t=0;
        for(int j=0;j<n;++j){
            t += A[j];
            int prev = UNLIMIT, q=0;
            for(int d=j;d>=0;--d){
                q += A[d];
                int tmp = max(dp[i-1][t-q], q);
                if(prev >= tmp){
                    prev = tmp;
                }else{
                    break;        //break if bottom is confirmed
                }
            }
            dp[i][t] = prev;
        }
    }
    int res = dp[k][sum];
    for(int i=0;i<k+1;++i){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp = 0;

    return res;
}

/*
 * alternative algorithm make use of binary search!!!
 * in opposite, it considers constraint of given total cost, the best(minimum) partition count x which is easy to get
 * in time O(k*lg(sum)) where sum is sum of integer array, and in space O(1)
 */
int partitionInCost(int sum, int *A, int n){
    int t=1, acc=0;
    for(int i=0;i<n;++i){
        if(acc + A[i] <= sum){
            acc += A[i];
        }else{
            ++t;
            acc = A[i];
        }
    }
    return t;
}

int fairworkload_02(int *A, int n, int k){
    int sum=0, maxel=0;
    for(int i=0;i<n;++i){
        sum += A[i];
        if(maxel < A[i])
            maxel = A[i];
    }
    int u=sum, v=maxel;
    while(v < u){
        int m=(u+v)/2;
        int x = partitionInCost(m, A, n);
        if(x >k){
            v = m+1;    //enlarge m to reduce x
        }else{
            u = m;      //reduce m, to see if x will increase
        }
    }
    return v;      //choose v instead of m
}

int main(int, char**){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);

        if(getline(cin, str)==0 || str.empty())
          break;
        int k = atoi(str.c_str());
        int res = fairworkload_01(arr, n, k);
        printf("solution1: the minimum total work load is %d\n", res);

        res = fairworkload_02(arr, n, k);
        printf("solution2: the minimum total work load is %d\n", res);
        delete[] arr;
        arr=0;
    }
    return 0;
}
