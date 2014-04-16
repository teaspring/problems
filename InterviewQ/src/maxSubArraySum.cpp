/*
 * <Beauty Of Programming>
 * 2.14, input an array of negagtive/0/non-negative, calcualte the max sub array sum
 * question2: return the max subarray range
 * question1: if allow the subarray follow head from tail(that becomes a loop), calculate the max sub array sum
 * */
#include "stdio.h"

int calculateMaxSubArraySum(int* arr, int length, int& start, int& subLength){
    int nStart  = arr[length-1];
    int nAll    = arr[length-1];
    start = length-1;
    subLength = 1;
    for(int i=length-2;i>-1;i--){
        if(nStart<0)    nStart=0;
        nStart += arr[i];
        if(nStart>nAll){
            if(nStart==arr[i]){
                subLength = 1;
                start = i;
            }else{
                subLength += (start-i);
                start = i;
            }
            nAll = nStart;
        }
    }
    return nAll;
}

void test_01(){
    int begin=0;
    int resLength=1;
    int sum=0;
    int a[6]={9,-8,3,5,-3,2};
    sum = calculateMaxSubArraySum(a,6,begin,resLength);
    for(int i=0;i<resLength;i++){
        printf("%d ", a[i+begin]);
    }
    printf(": sum=%d\n", sum);

    int b[6]={1,-3,3,5,-2,1};
    sum = calculateMaxSubArraySum(b,6,begin,resLength);
    for(int i=0;i<resLength;i++){
        printf("%d ", b[i+begin]);
    }
    printf(": sum=%d\n", sum);

    int c[6]={2,-1,3,5,-1,2};
    sum = calculateMaxSubArraySum(c,6,begin,resLength);
    for(int i=0;i<resLength;i++){
        printf("%d ", c[i+begin]);
    }
    printf(": sum=%d\n", sum);
    return;
}

int main(int argc, char* argv[]){
    test_01();
    return 0;
}

