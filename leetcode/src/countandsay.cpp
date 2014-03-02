/*
 * given count-and-say sequence: 1, 11, 21, 1211, 111221
 * 1 is read off as "one 1" or 11
 * 11 is read off as "two  1" or 21
 * 21 ->  1211 -> 111221 -> 312211 -> 13112221 ...
 * given integer n, ask the nth sequence in string. n is 1-based
 *
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

/*
 * len: input is digits length of a, output is that of returned value
 * input: should be string instead of integer because integer will be overflow
 * */
int getNext(int a, int& len){
    int l=len, d=1, currLen=0, b=0;
    for(int i=0;i<l-1;++i){
        d *= 10;
    }
    while(l>0 && d>0){
        int r1 = a/d;
        int r2 = d>=10 ?  (a - r1*d)/(d/10) : -1;  //-1 is an invalid value which is never equals to r1
        printf("r2=%d\n", r2);
        if(r1==r2){
            a -= r1*d + r1*(d/10);
            b = b*10 +2;
            b = b*10 + r1;
            l-=2;
            d /= 100;
        }else{
            a -= r1*d;
            b = b*10 + 1;
            b = b*10 + r1;
            l-=1;
            d /= 10;
        }
        currLen += 2;
    }
    printf("b=%d\n", b);
    len = currLen;
    return b;
}

string countAndSay_01(int n){
    if(n<1)        return string();
    int a=1, len=1;
    for(;n>1;--n){
        a = getNext(a, len);
    }
    printf("number is %d\n", a);
    
    char *cstr = new char[len+1];
    int b=a;
    for(int i=len-1; b>0 && i>=0; --i){
        cstr[i] = '0' + b%10;
        b /= 10;
    }
    cstr[len] = '\0';
    string str(cstr);
    delete[] cstr;
    return str;
}

/*
 * version 2, use char* to put sequence instead of integer to avoid integer overflow
 * */
void getNext(const char *a, char *b){    //b is initiated externally with enough space
    int n = strlen(a);
    int i=0, j=0;
    while(i<n){
        int k=i+1;
        for(;k<n && a[k]==a[k-1];++k);
        b[j++] = '0' + (k-i);
        b[j++] = a[i];
        i=k;
    }
    b[j] = '\0';
    return;
}

string countAndSay_02(int n){
    if(n<1)    return string();
    int l=1;
    char *pa = new char[2];
    pa[0] = '1';
    pa[1] = '\0';
    char *pb;
    for(; n>1; --n){
        l = strlen(pa);
        pb = new char[2*l+1];
        getNext(pa, pb);
        char *tmp = pb;  //swap pb and pa to enable pa to be the new one
        pb = pa;
        pa = tmp;
        delete[] pb;
    }
    string str(pa);
    delete[] pa;
    return str;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input nth:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int n = atoi(str.c_str());
        printf("sequence is %s\n", countAndSay_02(n).c_str());
    }
    return 0;
}
