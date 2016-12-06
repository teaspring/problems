/*
 * one copy of implementation of KMP string match algorithm
 * for string match problem that match a string T with pattern P, the KMP(Knuth-Morris-Pratt) algorithm is popular at its linear time O(n)
 * 
 * test data:    pattern/string
 * abab/abbaabbaabab
 * ababa/abaaba
 * aaaaa/aabaaaabaaaaa
 * */
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution{

public:
    /*
    * in total, KMP is in time O(n+m) while n is length of string to match, m is length of pattern
    * */
    bool isMatchKMP(const string& str, const string& pattern){
        const int n = str.size();
        const int m = pattern.size();
        if(n < m)    return false;
        if(n == 0 && m == 0)    return true;
        if(m == 0)    return false;

        int prefix[m];
        memset(prefix, 0, sizeof(prefix));

        setPrefix(pattern, prefix);  // get prefix[]

        int i = 0, s = 0; // s is start of substr, i is cursor to iterate
        while(i <= n){
            int k = i-s;  // k is 0-based
            if(k < 0|| (k < m && i < n && pattern.at(k) == str.at(i))){
                ++i;
            }else if(k == m){
                return true;
            }else {  // prefix[k] <= k
                s += (k < 1) ? 1 : k - prefix[k-1];  // shift pattern either 1 or k-prefix[k-1] !!!
            }
        }
        return false;
    }

private:
    /*
    * for KMP algorithm, the most important part is the preprocess of pattern P
    * prefix[i] means for substr pattern[0...i], the maximum length that prefix of length k matches suffix of it with length k
    * the problem is: based on prefix[i-1] is ready, how to get prefix[i] ?
    * time in O(m)!
    * */
    void setPrefix(const string& pattern, int *prefix){ // assume prefix has been reset to all 0
        const int n = pattern.size();
        for(int i = 1; i < n; ++i) {  // prefix[0] = 0 surely
            prefix[i] = 0; // k = prefix[i-1] means it means pattern[k-1] == pattern[i-1]
            for(int k = prefix[i-1]; k > 0; k = prefix[k-1]) { // reduce k quickly. as pattern[0..k-1] matches pattern[i-k...i-1], if q = prefix[k-1], pattern[0..q-1] must match pattern[i-q...i-1]
                if (pattern[k] == pattern[i]) {
                    prefix[i] = k+1;
                    break;
                }
            }
        }
        return;
    }
};

/**** unit test is in ../cpp_unittest/ */
