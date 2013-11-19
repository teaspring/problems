/*
 * <BeatyOfProgramming> problem2.4
 * given N, among all the integers from 1,2,3...N, 
 * 1. appearance count of 1
 * 2. appearance count of 2
 **/

#include "stdio.h"
typedef unsigned long ulong;

long sum1s(ulong n){
    ulong iCount = 0;
    ulong iFactor = 1;
    ulong iLowerNum = 0;
    ulong iCurrNum = 0;
    ulong iHigherNum = 0;
    while(n/iFactor != 0){
        iLowerNum = n - (n/iFactor) * iFactor;
        iCurrNum = (n/iFactor) % 10;
        iHigherNum = n/(iFactor * 10);
        switch(iCurrNum){
            case 0:
                iCount += iHigherNum * iFactor;
                break;
            case 1:
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
    ulong iCount = 0;
    ulong iFactor = 1;
    ulong iLowerNum = 0;
    ulong iCurrNum = 0;
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
            case 2:                    //for sum2(),0/1 is same, 2 differs
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

int main(int argc, char* argv[]){
    ulong x=0;
    while(scanf("%li", &x) != EOF){
        long res = sum1s(x);
        printf("from 1 to %li, appearance of 1 is %li\n", x, res);
        res = sum2s(x);
        printf("from 1 to %li, appearance of 2 is %li\n", x, res);
    }
    return 0;
}
