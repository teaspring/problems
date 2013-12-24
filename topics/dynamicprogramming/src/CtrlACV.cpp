/*
* from leetcode
* a keyboard has 4 buttons: A, Ctrl+A, Ctrl+C, Ctrl+V. if you can only press the keyboard for n times, write program to produce maximum numbers of A. print out the sequence of keys
*/

#include "stdio.h"
#include <iostream>
#include <string>
#include "stdlib.h"

using namespace std;

void outputActions(int *A, int n, int k){
    if(k<1 || k>=n)     return;
    if(A[k] == 1){
        outputActions(A, n, k-3);
        cout<<"Ctrl+A Ctrl+C Ctrl+V ";
    }else{
        outputActions(A, n, k-1);
        cout<<"A ";
    }
    return;
}

int ctrlACV(int n){
    int *dp = new int[n+1]();   //dp[i] means max count of 'A' for length i
    int *actions = new int[n+1]();      //1 for "CtrlA, CtrlC, CtrlV", 0 for just 'A' by default
    for(int i=0;i<n+1;++i){
        if(i<6){
            dp[i] = i;
        }else{
            dp[i] = 2*(dp[i-3]);
            actions[i] = 1;
        }
    }
    int res = dp[n];
    outputActions(actions, n+1, n);
    cout<<endl;

    delete[] dp;
    dp=0;
    delete[] actions;
    actions=0;
    return res;
}
int main(int,char**){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
            break;
        int n = atoi(str.c_str());
        int k = ctrlACV(n);
        printf("for pressing keyboard %d times, the maximum count of A is %d\n", n, k);
    }
    return 0;
}

