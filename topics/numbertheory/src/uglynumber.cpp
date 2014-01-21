/*
 * Ugly numbers are numbers whose only prime factors are 2,3 or 5. the sequence 1,2,3,4,5,8,9,10,12,15,.... shows
 * the first 11 ugly numbers. 
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include "stdlib.h"

using namespace std;

inline int min(int a, int b){
    return a<b ? a : b;
}

int findUglyNumber(int n){
    if(n<1)        return 0;
    int *num = new int[n]();
    num[0] = 1;
    int m2=0, m3=0, m5=0;
    for(int i=1;i<n;i++){
        int x2 = num[m2] * 2;
        int x3 = num[m3] * 3;
        int x5 = num[m5] * 5;
        int tmp = min(x2, min(x3, x5));
        num[i] = tmp;
        if(tmp == x2)   m2++;    //note this is not if-else clause because 2*3 == 3*2
        if(tmp == x3)   m3++;
        if(tmp == x5)   m5++;
    }
    int res = num[n-1];
    delete[] num;
    return res;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input Nth for ugly number while N is 1-based:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int n = atoi(str.c_str());
        printf("%d\n", findUglyNumber(n));
    }
    return 0;
}

