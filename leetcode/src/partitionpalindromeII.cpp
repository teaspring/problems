/*
 * given a string s, partition s such that every substring of partition is a palindrome
 * return the minimum cuts needed for a palindrome partitioning of s
 *
 * test data:
 * cbbcc
 * aaaaaaaaaab
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int minCut(const string& s){
    int n = s.size();
    if(n<2)        return 0;
    int **dp = new int*[n];    //dp[start][end] ==1 means substring [) is palindrome
    for(int i=0;i<n;++i){
        dp[i] = new int[n+1]();
        dp[i][i+1] = 1;
    }
    for(int len=2;len<=n;++len){
        for(int start=0;start+len<=n;++start){
            if(len<4 || dp[start+1][start+len-1]==1){
                if(s[start] == s[start+len-1]){
                    dp[start][start+len] = 1;
                }
            }
        }
    }
    int *mc = new int[n+1]();    //mc[i] means min cuts of substring [0,i) of length i
    for(int i=2;i<=n;++i){
        if(dp[0][i]==1){
            mc[i] = 0;
        }else{
            int ic = i-2;        //minimize ic and mc[i] is ic+1 at least
            for(int j=i-1;j>0;--j){
                if(dp[j][i]==1){
                    ic = min(ic, mc[j]);
                }
            }
            mc[i] = ic + 1;
        }
    }
    for(int i=0;i<=n;++i){
        printf("%d ", mc[i]);
    }
    printf("\n");
    int res = mc[n];
    
    for(int i=0;i<n;++i){
        delete[] dp[i];
        dp[i]=0;
    }
    delete[] dp;
    dp=0;
    delete[] mc;
    mc=0;
    return res;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input string: \n");
        if(getline(cin, str)==0 || str.empty())        break;
        printf("min cuts is %d\n", minCut(str));
    }
    return 0;
}
