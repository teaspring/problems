/*
 * problem 1:
 * given n, how many structurally unique BST's(binary search tree) that store values 1...n?
 * e.g. n=3, there are a total of 5 unique BST's
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

int numTrees(int n){
    if(n<1)        return 0;
    int *subs = new int[n+1]();
    subs[0] = subs[1] = 1;
    for(int i=2; i<=n; ++i){   // i is 1-based
        for(int r=1; r<=i; ++r){  // r is root of the i numbers
            subs[i] += subs[r-1] * subs[i-r];
        }
    }
    int total = subs[n];
    delete[] subs;
    subs=0;
    return total;
}

void test_01(){
    string str;
    while(1){
        printf("please input positive integer n:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int n = atoi(str.c_str());
        printf("total count of unique BST is %d\n", numTrees(n));
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
