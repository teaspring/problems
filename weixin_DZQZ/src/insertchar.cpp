/*
* problem on Oct15,2013
* given a string, how many chars need to insert to transfer it to palindrome in minimum?
* a good dynamic programming
* 
* test data:
* bcddefa
* bcdefd
* dcfd
*/

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

inline int max(int a, int b){
    return a>b ? a : b;
}

int turn2palindrome(const string& str){
    int s = str.size();
    int ** dp = new int*[s];
    for(int i=0;i<s;++i){        //dp[i][j] means for str starting at [i] with size j, the length of internal palindrome
        dp[i] = new int[s+1]();
    }
    for(int i=0;i<s;++i){
        dp[i][1] = 1;            //any char is palindrome naturally
    }
    for(int j=2;j<=s;++j){
        for(int i=0;i+j-1<s;++i){
            if(str[i] == str[i+j-1]){
                dp[i][j] = 2 + dp[i+1][j-2];
            }else{
                dp[i][j] = max(dp[i+1][j-1], dp[i][j-1]);
            }
        }
    }
    int res = s - dp[0][s];
    
    for(int i =0;i<s;++i){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp = 0;
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
            break;
        int res = turn2palindrome(str);
        printf("to be palindrome: insert %d chars in minimum\n", res);
    }
    return 0;
}
