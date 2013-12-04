/*
 * <IntroductionToAlgorithm> chapter15 DynamicProgramming, exercise 15-9, breaking a string
 * given a string of n chars. every time breaking a string of size n, the cost is n. now with several required positions to break, calcualute the minimum total cost
 * 
 * e.g. for a string of size 20, we want to break string after char 2,8,10, which means it must be broken after it 
 * if cut in left-to-right, the cost is 20+18+12=50; 
 * if in right-to-left, the cost is 20+10+8=38;
 * if break 8 first, the cost is 20+8+12=40.
 *
 * */

#include "../header/preliminary.h"

const int LIMIT = 0xffff;
/*
 * not easy to find the optimal substructure
 * dp[f,e] = e-f+1 + min{dp[f,i]+dp[i+1][e], f<i<e}     if there is break point occur among [f,e]; 
 *         = 0                                          if no break point occurs among [f,e]
 * @param:  
 *        m is size of broken, n is size of whole string. m < n
 *        arr[i] means breaking after xth char, in our array [1,n), it will be minus 1
 * */
int breakingstring(int* broken,int m, int n){
    int** dp = new int*[n];             //dp[f][e] means cost of substring of [f,e]
    for(int i=0;i<n;++i){
        dp[i] = new int[n]();
    }
    for(int k=2;k<=n;++k){              //length of k
        for(int f=0;f+k<=n;++f){        //staring at f
            int minsub = LIMIT;
            for(int i=0;i<m;++i){
                if(broken[i]-1 <= f || broken[i]-1 >= f+k-1){
                    continue;
                }
                int tmp = dp[f][broken[i]-1] + dp[broken[i]][f+k-1];
                if(minsub==LIMIT || minsub > tmp){
                    minsub = tmp;
                }
            }
            if(minsub != LIMIT){
                dp[f][f+k-1] = k + minsub;
            }                            //else no break point occurs among [f,f+k-1], it takes no cost(0)
        }
    }
    int sum = dp[0][n-1];
    /*
    for(int i=0;i<n;++i){                //output for debug 
        for(int j=0;j<n;++j){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    for(int i=0;i<n;++i){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp=0;
    return sum;
}

int main(int, char**){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())        //input 2 8 10 20, the last one is total size of string
          break;
        int* arr= new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int res = breakingstring(arr, n-1, arr[n-1]);
        printf("the minimum cost of breaking string is %d\n", res);
    }
    return 0;
}
