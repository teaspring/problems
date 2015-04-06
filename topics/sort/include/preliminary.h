/******************preliminary.h**************************/
#include "stdio.h"
#include "stdlib.h"
#include <cstring>
#include <string>
#include <cctype>    
#include <iostream>
#include "math.h"

using namespace std;


/*
* time O(lgm) to get index m == lgn
*
int getindex(int num, int& t, int e =10){
    int m=1, pre_m=0, pre_t=1;
    t=e;
    while(num/t < 1 || num/t > 9){
        if(num/t > 9){
            pre_t = t;
            t *= t;
            pre_m = m;
            m *= 2;
        }else{
            t = pre_t * (int)sqrt(t/pre_t);
            m = pre_m + (m-pre_m)/2;
        }
    }
    return m;
}
*/
