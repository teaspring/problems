/*
 * problem on Aug07.
 * given an integer array, and an integer as sum. ask the composition of whatever elements in array which sum equals to given value
 * typical dynamic programming
 *
 * test data:
 * {5,5,10,2,3,}, sum=15.
 * count = 4, {5,10},{5,10},{5,5,2,3},{10,2,3}
 *
 * */
#include "../header/preliminary.h"

/*
 * calculate the count and output
 * */
int compositions(int* arr, int n, int sum){
    int** dp = new int*[n+1];        // dp[i][m] means for last i elements, count of compositions which sum equals to m
    for(int i=0;i<n+1;i++){
        dp[i] = new int[sum+1]();
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int m=0;m<=sum;m++){
            dp[i][m] = dp[i-1][m];
            if(m>=arr[n-i]){
                dp[i][m] += dp[i-1][m-arr[n-i]];        //[n-i] is head of the last i elements !!! 
            }
        }
    }

    int res = dp[n][sum];
    for(int i=0;i<n+1;i++){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp=0;
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int* num = new int[str.size()]();
        int n = splitStr2IntArray(str, num);
        
        if(getline(cin, str)==0 || str.empty())
          break;
        int s = atoi(str.c_str());
        int count = compositions(num, n, s);
        printf("count of compositions: %d\n", count);

        delete[] num;
        num=0;
    }
    return 0;
}
