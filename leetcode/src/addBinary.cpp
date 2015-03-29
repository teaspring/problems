/*
 * given two binary number in string, get their plus sum
 *
 *   '1001'
 * +  '100'
 * ----------
 * = '1101'
 */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    string addBinary(string a, string b){
        const int la = a.size();
        const int lb = b.size();

        char reversed[max(la, lb) + 2];   // maximum length of sum is max(la,lb)+1, plus '\0'
        int i = la - 1, j = lb - 1, k = 0;
        int over = 0;

        while(i >= 0 || j >= 0){
            int ca = (i < 0 || a[i] == '0') ? 0 : 1;
            int cb = (j < 0 || b[j] == '0') ? 0 : 1;
            int cr = ca + cb + over;
            over = cr >> 1;
            reversed[k++] = '0' + cr % 2;
            --i;
            --j;
        }
        if(over){
            reversed[k++] = '1';    // k is length
        }

        for(int i = 0; i < (k >> 1); ++i){
            swapInt(reversed + i, reversed + k-1-i);
        }
        reversed[k] = '\0';
        return string(reversed);
    }

private:
    void swapInt(char *pa, char *pb){
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;
    }
};

