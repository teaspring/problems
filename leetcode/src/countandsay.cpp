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

class Solution{
public:
    /*
    * use char* to put sequence instead of integer to avoid integer overflow
    * */
    void getNext(const char *a, char *b){    //b is initiated externally with enough space
        int n = strlen(a);
        int i=0, j=0;
        while(i < n){
            int k = i+1;
            for(; k<n && a[k] == a[k-1]; ++k);
            b[j++] = '0' + (k-i);
            b[j++] = a[i];
            i = k;
        }
        b[j] = '\0';
        return;
    }

    string countAndSay(int n){
        if(n < 1)    return string();
        int l = 1;
        char *pa = new char[2];
        pa[0] = '1';
        pa[1] = '\0';
        char *pb = NULL;

        for(; n > 1; --n){
            l = strlen(pa);
            pb = new char[2*l + 1];

            getNext(pa, pb);

            delete[] pa;
            pa = pb;
            pb = NULL;
        }
        string str(pa);
        delete[] pa;
        return str;
    }
};
/*
int main(int, char**){
    string str;
    while(1){
        printf("please input nth:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int n = atoi(str.c_str());
        printf("sequence is %s\n", countAndSay_02(n).c_str());
    }
    return 0;
}*/
