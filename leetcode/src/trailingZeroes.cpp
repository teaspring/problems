/*
 * give an integer n, return the number of trailing zeroes in n!
 * time complexity must be in O(lgn)
 * */
#include <iostream>

using namespace std;

class Solution{
public:
    // the trailing zeroes count in n! is dependent on count of 5 among the n!
    int trailingZeroes(int n) {
        int res = 0;
        int d = n;
        while(d > 0) {
            res += d/5;
            d /= 5;
        }
        return res;
    }
};

