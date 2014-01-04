/*
 * problem on Dec 31,2013. given n(n<=9), find all numbers of n digits while its digits in ascending. e.g. n=3, 123,124,125,,,,,789
 * 
 * test data: n is [1,9]
 * note: count of such numbers for n=8 equals the one for n=1, because 1 and 23456789 is in pair
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

void outputNum(int *A, int n){
    int s = A[0];
    for(int i=1;i<n;++i)
      s = 10 * s + A[i];
    cout<<s<<", ";
    return;
}

/*
 * solution 1: my own solution without recurse
 * */
int findAllNumbers_01(int n){
    if(n>9 || n <1)        return 0;
    int *num = new int[n]();
    num[0] = 1;
    int i=1;
    while(i<n){
        num[i] = num[i-1] + 1;
        ++i;
    }
    int count=0;
    while(1){
        count++;
        outputNum(num, n);    //now i==n
        i--;
        while(i>=0 && num[i]+1 > 10-n+i){  //key constraint for either digit: number[i] <= 10-n+i
            i--;
        }
        if(i<0)        break; //complete search, we can return
        num[i]++;   //this digit +1
        i++;
        for(;i<n;++i){
          num[i] = num[i-1] + 1;    //following digits in tight ascending
        }
    }
    cout<<endl;
    delete[] num;
    return count;
}

/*
 * solution 2: recursion
 * */
void print(int *A, int n, int index, int& cnt){   //A[index] is the next element to set
    if(index == n){     //size of A[] is n
        ++cnt;
        outputNum(A, n);
        return;
    }
    for(int i=A[index-1]+1;i<10;++i){
        A[index] = i;
        print(A, n, index+1, cnt);
    }
    return;
}

int findAllNumbers_02(int n){
    if(n<1 || n>9)        return 0;
    int count=0;
    int *arr = new int[n]();
    for(int i=1; i<=10-n; ++i){
        arr[0] = i;
        print(arr, n, 1, count);
    }
    cout<<endl;
    return count;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input n:\n");
        if(getline(cin, str)==0 || str.empty())
          break;
        int n = atoi(str.c_str());
        if(n>9 || n<1)    continue;
        int cnt = findAllNumbers_01(n);
        printf("solution 1: numbers in total: %d\n", cnt);
        cnt = findAllNumbers_02(n);
        printf("solution 2: numbers in total: %d\n", cnt);
    }
    return 0;
}
