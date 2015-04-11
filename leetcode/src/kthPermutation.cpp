/*
 * the set [1,2,3,...,n] contains a total of n! unique permutations. by listing and labelling all of the permutations in order.
 * we get the following sequences: for n = 3
 * 123
 * 132,
 * 213,
 * 231,
 * 312,
 * 321
 * Q: given n and k, return the kth permutation sequence. n will be between [1,9]
 * */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

class Solution{

public:
    /*
     * n is [1, 9], while k is 1-based, in [1, n!]
     * this method does not use recursion
     *
     * but there should be recursion implementation for this problem
     * */
    string getPermutation(int n, int k){
        char num[n];
        memset(num, 0, sizeof(num));

        int count = 1;
        for(int i = 0; i < n; ++i){
            num[i] = '0' + (i+1);
            count *= (i+1);
        }

        if(k > count)    return NULL;
        --k;    // argument k is 1-based

        char cstr[n+1];
        memset(cstr, 0, sizeof(cstr));

        for(int i = 0; i < n; ++i){
            count /= (n-i);
            int selected = k / count;
            cstr[i] = num[selected];  // selected is 0-based

            k %= count;
            for(int j = selected + 1; j < n-i; ++j){  // reconstruct num[]
                num[j-1] = num[j];
            }
        }
        cstr[n] = '\0';
        string str(cstr);

        return str;
    }
};

/* unit test is in ../cpp_unittest/kthPermutation_unittest */
