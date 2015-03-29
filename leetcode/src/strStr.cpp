/*
 * implement strStr(), using KMP string match algorithm
 * to match string T with pattern P, the KMP(Knuth-Morris-Pratt) algorithm is in time O(n)
 * 
 * test data:    pattern/string
 * abab/abbaabbaabab
 * ababa/abaaba
 * aaaaa/aabaaaabaaaaa
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution{
    /*
    * for KMP algorithm, the most important part is the preprocess of pattern P, to get int prefix[P]
    * it means for P[0...i], the greatest k that prefix of P(P[0..k-1]) matches suffix of P(P[i-k+1, i])
    * generally, this pattern preprocess is in time O(P)
    * */
    void setPrefix(const char *pattern, int *prefix){ // prefix should be [n]
        const int n = strlen(pattern);
        prefix[0] = 0;
        for(int i = 1; i < n; i++){
            int k = prefix[i-1]; // index is 0-based, and length is 1-based. so k=prefix[i-1] is just the next potential matched char
            for(; pattern[k] != pattern[i] && k > 0; k = prefix[k-1]);

            if(pattern[k] == pattern[i]){
                prefix[i] = k+1;    //k is index of 0-based, prefix[i] should be 1-based, prefix[i]<=i
            }else{
                prefix[i] = 0;
            }
        }
        return;
    }

public:
    /*
    * in total, KMP is in time O(n+m) while n is length of string to match, m is length of pattern
    * return pointer to first occurance of pattern in str
    * */
    const char* strStr(const char *str, const char *pattern){
        const int n = strlen(str);
        const int m = strlen(pattern);
        if(m == 0)    return str;
        if(n < m || n == 0)    return NULL;

        int prefix[m];
        memset(prefix, 0, sizeof(prefix)/sizeof(int));
        setPrefix(pattern, prefix); // get prefix array

        int i = 0, s = 0;
        bool bfind = false;
        while(i < n){
            int k = i-s; // k is 0-based
            if(k < 0||(k < m && pattern[k] == str[i])){
                ++i;
            }else if(k == m){
                bfind = true;
                break;
            }else{    // prefix[k] <= k
                s += (k < 1)? 1 : k - prefix[k-1];  // shift pattern either 1 or k-prefix[k-1] !!!
            }
        }

        if(bfind || i-s == m){ // detect i-s if it reaches tail of str
            return str + s;
        }
        return NULL;
    }

    /* uint test is in ../cpp_unittest/strStr_unittest */
};
