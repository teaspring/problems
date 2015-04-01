/*
 * divide two integers without using multiplication, division and mod operator
 * 
 * brace method is to use minus which will be in time O(n)
 * actually, expected method is binary search in time O(lgn)
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "stdlib.h"

using namespace std;

class Solution{

public:
    /*
    * failure version with Time Limit Exceed Error due to linear search
    * */
    int divide_01(int n, int m){    // n/m
        if(m == 0)    return 0;
        if(n == 0)    return 0;

        bool minus = false;
        if((n > 0 && m < 0) || (n < 0 && m > 0))    minus = true;

        n = max(n, -n);
        m = max(m, -m);
        int i=0;

        for(; n > 0; ++i){
            n -= m;
        }
        if(n == 0)    return minus ? -i : i;
        if(n < 0)     return minus ? -(i-1) : (i-1);
        return 0;
    }

    /*
    * accepted version, binary search
    * */
    int divide_02(int dividend, int divisor){
        int sa = dividend, sb = divisor;
        int a = 0;
        if(sa < 0){
            a = 1;
            sa = -sa;
        }

        int b = 0;
        if(sb < 0){
            b = 1;
            sb = -sb;
        }

        int ret = divide_posi(sa, sb);
        return a^b ? -ret : ret;
    }

private:
    /*
     * used by divide_02, process positive int divide via binary search
     * */
    int divide_posi(int a, int div){
        if(a == 0)    return 0;

        int v = 0, u = a, mid = 0;
        while(v <= u){
            mid = (v + u) >> 1;

            if(mid * div == a)    return mid;

            if(mid * div > a){
                u = mid - 1;
            }else{
                v = mid + 1;
            }
        }

        return (v + u) >> 1;
    }
};
/* unit test is in ../cppp_unittest/divideInteger_unittest */
