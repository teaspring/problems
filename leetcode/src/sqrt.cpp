/*
 * sqrt(1)           = 1     , N = 1
 * sqrt(10)          = 3     , N = 2
 * sqrt(100)         = 10    , N = 3
 * sqrt(1000)        = 31    , N = 4
 * sqrt(10000)       = 100   , N = 5
 * sqrt(100000)      = 316   , N = 6
 * sqrt(1000000)     = 1000  , N = 7
 * sqrt(10000000)    = 3162  , N = 8
 * sqrt(100000000)   = 10000 , N = 9
 * sqrt(1000000000)  = 31622 , N = 10
 * 2^31    = 2147483648,
 * 46340^2 = 2147395600
 * 2^30 = 1073741824
 * 2^15 = 32768
 */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include "stdlib.h"
#include <algorithm>
using namespace std;

class Sqrt{
public:
    int mysqrt(int x){
        if(x <= 0)    return 0;
        if(x >= 2147395600)    return 46340;
        int a = 1, b = 2;
        while(b * b < x){
            a = b;
            b *= 2;
            if(b > 46340){    // it has to code hard :(
                b = 46340;
                break;
            }
        }
        if(b * b == x)    return b;
        int m = 0;
        while(a < b){
            m = (a+b)/2;
            if(m * m == x){
                return m;
            }else if(m * m < x){
                if(m == b-1)    return m;
                a = m;
            }else{
                b = m;
            }
        }
        return a;
    }

    void test_01(){
        string str;
        while(1){
            cout << "please input integer x:" << endl;
            if(getline(cin, str)==0 || str.empty())    break;
            int x = atoi(str.c_str());
            printf("sqrt is %d\n", mysqrt(x));
        }
        return;
    }
};

int main(){
    Sqrt *st = new Sqrt();
    st->test_01();
    delete st;
    st = 0;
    return 0;
}
