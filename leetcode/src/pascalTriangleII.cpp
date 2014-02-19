/*
 * given an index k, return kth row of Pascal's triangle.
 * e.g, given k=3, return: 1,3,3,1
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"
#include <vector>

using namespace std;

vector<int> getRow(int k){    //kth row, has k+1 elements
    vector<int> res;
    if(k<0)        return res;
    int **dp = new int*[2];
    for(int i=0;i<2;i++){
        dp[i] = new int[k+1]();
    }
    int last = 0;
    dp[last][0] = 1;
    for(int i=1;i<=k;i++){
        int now = 1-last;
        memset(dp[now], 0, sizeof(int)*(k+1));
        dp[now][0] = dp[last][0];
        for(int j=1;j<i;++j){
            dp[now][j] = dp[last][j-1] + dp[last][j];
        }
        dp[now][i] = dp[last][i-1];
        last = now;
    }
    for(int i=0;i<=k;i++){
        res.push_back(dp[last][i]);
    }

    for(int i=0;i<2;i++){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp=0;
    return res;
}

void show(const vector<int>& vec){
    int n = vec.size();
    for(int i=0;i<n;++i){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main(int, char**){
    string str;
    while(1){
        printf("please input numRows:\n");
        if(getline(cin, str)==0 || str.empty())        
          break;
        int n = atoi(str.c_str());
        show(getRow(n));
    }
    return 0;
}

