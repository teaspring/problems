/*
 * Gray code is a binary numeral coding algorithm. Its two successive integers differ in one bit, and the ith just dependent on (i-1)th 
 * Note for given integer n(bits), its Gray code output are not unique. Whatever, the 1st must be 0000...
 * 
 * one optional method to generate gray code is:
 * 1. odd indexed is flip 0 bit of last code
 * 2. even indexed is flip next bit after the first 1 from low to high.  
 *
 * test case:
 * n=3,
 * 000
 * 001
 * 011
 * 010
 * 110
 * 111
 * 101
 * 100
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include "stdlib.h"
using namespace std;

/*
 * @parameters:
 *        n: digit count of Gray Code
 *        return: vector of gray code
 * */
vector<int> grayCode_01(int n){
    vector<int> res;
    if(n<1)    return res;
    int x=0, bin=0;
    res.push_back(x);
    while(1){
        bin = 1-bin;
        if(bin==1){    //odd indexed
            x ^= 1;
        }else{         //even indexed
            int a=1, i=0;
            while(i<n-1 && !(x & a)){  //find the first 1 bit from low to high on
                a = a << 1;
                ++i;
            }
            if(i==n-1)    break;
            x ^= (a<<1);
        }
        res.push_back(x);
    }
    return res;
}

void show(const vector<int>& vec){
    int n = vec.size();
    for(int i=0;i<n;i++){
        printf("%d , ", vec[i]);
    }
    printf("\n");
}

/*
 * method 2, find gray code by index
 * */
int indexedGrayCode(int k){
    return k ^ (k >> 1);
}

vector<int> grayCode_02(int n){
    vector<int> res;
    res.push_back(0);
    for(int i=1;i < (1 << n);i++){
        res.push_back(indexedGrayCode(i));
    }
    return res;
}

int main(int, char**){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())    break;
        int n = atoi(str.c_str());
        show(grayCode_01(n));
        show(grayCode_02(n));
    }
    return 0;
}

