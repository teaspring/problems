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
    * with KMP algorithm, perform preprocess pattern P to get int prefix[P]
    * prefix[i] = l means prefix with length l of s can be suffix of s, while s is prefix with length i+1 of pattern
    * */
    void setPrefix(const char *pattern, int *prefix){ // prefix should be [n]
        const int n = strlen(pattern);
        prefix[0] = 0;
        for(int i = 1; i < n; i++){
            int k = prefix[i-1]; // index is 0-based, and length is 1-based. so k = prefix[i-1] is the next char index to compare
            for(; pattern[k] != pattern[i] && k > 0; k = prefix[k-1]);

            if(pattern[k] == pattern[i]){
                prefix[i] = k + 1;
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

        int i = 0, s = 0; // i is cursor offset in str while s is pattern offset in str
        bool bfind = false;
        while(i < n){
            if(i < s){
                ++i;
                continue;
            }else if(i - s == m){
                bfind = true;
                break;
            }

            int k = i - s; // k is prefix length inside pattern which has been compared equal already
            if(pattern[k] == str[i]){
                ++i;  // pattern stays while cursor moving
            }else{
                s += (k == 0)? 1 : k - prefix[k-1];  // pattern move
            }
        }

        if(bfind || i - s == m){ // detect i-s if it reaches tail of str
            return str + s;
        }
        return NULL;
    }

    /* uint test is in ../cpp_unittest/strStr_unittest */
};
