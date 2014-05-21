/*
 * the set [1,2,3,...,n] contains a total of n! unique permutations. by listing and labelling all of the permutations in order.
 * we get the following sequences: for n=3
 * 123
 * 132,
 * 213,
 * 231,
 * 312,
 * 321
 * Q: given n and k, return the kth permutation sequence. n will be between [1,9]
 * */
#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include "stdlib.h"
using namespace std;

string getPermutation(int n, int k){
    char *num = new char[n];
    int count = 1;
    for(int i=0; i<n; ++i){
        num[i] = '0' + (i+1);
        count *= (i+1);
    }
    if(k > count)    return NULL;
    --k;    // argument k is 1-based which is used here as 0-based
    char *cstr = new char[n+1];
    for(int i=0; i<n; ++i){
        count /= (n-i);
        int selected = k/count;
        cstr[i] = num[selected];  // selected is 0-based
        
        k %= count;
        for(int j=selected+1; j < n-i; ++j){  // reconstruct num[] because one element is picked up already
            num[j-1] = num[j];
        }
    }
    cstr[n] = '\0';
    string str(cstr);

    delete[] num;
    num=0;
    delete[] cstr;
    cstr=0;
    return str;
}

void test_01(){
    string str;
    while(1){
        printf("please input integer n which can be [1,9]:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int n = atoi(str.c_str());
        
        printf("please input integer k which can be [1, n!]:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int k = atoi(str.c_str());
        printf("the kth permutation is %s\n", getPermutation(n, k).c_str());
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
