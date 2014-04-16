
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

long sum1s(ulong n){
    ulong iCount     = 0;
    ulong iFactor    = 1;
    ulong iLowerNum  = 0;
    ulong iCurrNum   = 0;
    ulong iHigherNum = 0;
    while(n/iFactor != 0){
        iLowerNum = n - (n/iFactor) * iFactor;
        iCurrNum = (n/iFactor) % 10;
        iHigherNum = n/(iFactor * 10);
        switch(iCurrNum){
            case 0:
                iCount += iHigherNum * iFactor;
                break;
            case 1:                                    //if want sum2(), here case0 and case1 is same, seperate at case 2
                iCount += iHigherNum * iFactor + iLowerNum + 1;
                break;
            default:
                iCount += (iHigherNum + 1) * iFactor;
                break;
        }
        iFactor *= 10;
    }
    return iCount;
}

long sum2s(ulong n){
    ulong iCount     = 0;
    ulong iFactor    = 1;
    ulong iLowerNum  = 0;
    ulong iCurrNum   = 0;
    ulong iHigherNum = 0;
    while(n/iFactor != 0){
        iLowerNum = n - (n/iFactor) * iFactor;
        iCurrNum = (n/iFactor) % 10;
        iHigherNum = n/(iFactor * 10);
        switch(iCurrNum){
            case 0:
            case 1:
                iCount += iHigherNum * iFactor;
                break;
            case 2:                            //for sum2(), here case0 and case1 is same, seperate at case 2:
                iCount += iHigherNum * iFactor + iLowerNum + 1;
                break;
            default:
                iCount += (iHigherNum + 1) * iFactor;
        }
        iFactor *= 10;
    }
    return iCount;
}

int main(int, char**){
    return 0;
}
