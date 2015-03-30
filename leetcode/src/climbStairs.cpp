/*
 * given a stair of n steps, every time you can climb 1 or 2 steps, ask how many ways to climb the n steps.
 */

#include "stdio.h"
#include <iostream>
using namespace std;

class Solution{
public:
    /*
     * recurse is avoided as it has too much redundancy
     * the state transfer is s[i] = s[i-1] + s[i-2], Fibonacci serial
     * */
    int climbStairs(int n){
        if(n <= 1)    return n;

        int a = 1, b = 1, c = 0;
        for(int i = 2; i < n+1; ++i){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

