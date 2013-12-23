 /*
  * regressive problem of Painter's partition problem on leetcode. Actually, it appears on topcoder as "fair work load"
  */
#include "../header/preliminary.h"

const int UNLIMIT = 0xffff;

inline int max(int a, int b){
    return a>b ? a : b;
}

/*
 * dp[i][j] = min{max{dp[i-1][j-t],t}, t=A[n-1], +A[n-2], +A[n-3],...+A[0]}
 */
int fairworkload(int *A, int n, int k){         //work list of A, with n tasks, divide to k partitions
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
                    break;        //search the bottom
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
        int res = fairworkload(arr, n, k);
        printf("the minimum total work load is %d\n", res);

        delete[] arr;
        arr=0;
    }
    return 0;
}



