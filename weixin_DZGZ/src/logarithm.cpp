/*
 * just for test some functions in other file
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "math.h"
#include "stdlib.h"
using namespace std;

/*
 * bug for 1234567891, correct answer is 9, but it returns 12. maybe the value type overflow
 * */
int log_1(long num, long& t, int e =10){
    int m=1, pre_m=0;
    long pre_t=1;
    t=e;
    while(num/t == 0 || num/t > e-1){
        if(num/t > e-1){
            if(t/pre_t >= pre_t){
                pre_t = t;
                t *= t;
                pre_m = m;
                m *= 2;
            }else{
                t = t * (long)sqrt(t/pre_t);
                m = m + (m-pre_m)/2;
            }
        }else{
            t = pre_t * (long)sqrt(t/pre_t);
            m = pre_m + (m-pre_m)/2;
        }
    }
    return m;
}

int log_2(long num, long& t, int e=10){
    int vm=0, um=1, m=0;
    long vt=1, ut=e;
    while(num/ut > e-1){
        vt = ut;
        ut *= ut;
        vm = um;
        um *= 2;
    }
    if(num/ut > 0 && num/ut<10){
        t = ut;
        return um;
    }

    while(1){                            //bi-search
        m = vm + (um-vm)/2;
        t = vt * sqrt(ut/vt);
        if(num/t > e-1){
            vm = m;
            vt = t;
            continue;
        }else if(num/t == 0){
            um = m;
            ut = t;
            continue;
        }else
          break;
    }
    return m;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        long d = 1;
        int res = log_1(atoi(str.c_str()), d, 2);
        printf("method 1: %d\n", res);
        res = log_2(atoi(str.c_str()), d, 2);
        printf("method 2: %d\n", res);
    }
    return 0;
}
