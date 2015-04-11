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
#include <cmath>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     * n is [1, 9], while k is 1-based, in [1, n!]
     * this method does not use recursion
     *
     * but there should be recursion implementation for this problem
     * */
    string getPermutation_1(int n, int k){
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

    /*
     * efficient solution, in time O(n)
     * */
    string getPermutation_2(int n, int k){
        if(n == 0)    return string();

        char cstr[n+1];
        memset(cstr, 0, sizeof(cstr));

        vector<int> num;
        for(int i = 0; i < n+1; i++){ // why [0...n] ?
            num.push_back(i);
        }

        for(int i = n-1; i > -1; i--){

            int factorial = nFactorial(i);

            int index = (int)ceil(k / (double)factorial); // ceil() is critical important !

            cstr[n-1 - i] = '0' + num[index];

            num.erase(num.begin() + index);

            k %= factorial;
            if(k == 0)    k = factorial;
        }

        cstr[n] = '\0';
        return string(cstr);
    }

    int nFactorial(int n){
        if(n == 0)    return 1;
        return n * nFactorial(n-1);
    }
};

/* unit test is in ../cpp_unittest/kthPermutation_unittest */
