/*
 * <IntroductionToAlgorithm> chapter15 dynamic programming, exercise 15-2, get longest palindrome
 *
 * it is suggested to use dynamic programming here, in time O(n^2) 
 * another algorithm (Manache) can achieve O(n)
 * */

#include "stdio.h"
#include <iostream>
#include <string>

using namespace std;

inline int max(int a, int b){
    return a>b ? a : b;
}

int maxpalindrome(const string& str, int& begin){
    int n=str.size(), sum=1;
    int** dp = new int*[n];            //dp[i][j] means palindrome length of str starting at i with length of j
    for(int i=0;i<n;++i){
        dp[i] = new int[n+1]();
    }
    for(int i=0;i<n;++i){
        dp[i][1] = 1;
    }
    for(int j=2;j<=n;++j){
        for(int i=0;i+j<=n;++i){
            if(dp[i+1][j-2] == j-2){
                if(str[i] == str[i+j-1]){
                    dp[i][j]=j;
                    if(sum < j){
                        sum=j;
                        begin=i;
                    }
                }else{
                    dp[i][j] = j-2;
                }
            }else{
                dp[i][j] = max(dp[i+1][j-1], dp[i][j-1]);
            }
        }
    }

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
        if(getline(cin, str)==0 || str.empty())
          break;
        int b = 0;
        int res = maxpalindrome(str, b);
        printf("the longest palindrome is %s\n", str.substr(b, res).c_str());
    }
    return 0;
}
