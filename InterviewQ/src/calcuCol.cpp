/*
 * 20130714, question1:
 * In Excel, the column named as A(1), B(2), Z(26), AA(27), ...AZ
 * test data: 
 * 27(AA), 1378(AZZ), 676(YZ), 702(ZZ)
 * */
#include <iostream>
#include "stdio.h"
using namespace std;

void columnName01(int n){
    const int unit = 26;
    int index = 0;
    int sum = n;
    while((sum-1)/unit){        //analysis 1-A, 26-Z, 26*26-YZ, 27*26-ZZ
        index++;
        sum = (sum-1)/unit;
    }
    while(index>-1){            //time O(n^2), n is digits of N
        sum = n;
        for(int i=0;i<index;i++)
            sum = (sum-1)/unit;
        printf("%c", 'A'+(sum-1) % unit);
        index--;
    }
    printf("\n");
}

/*
 * based on method1, reduce internal iteration. time O(n) with n is digits of num
 * */
void columnName02(int n){
    const int N = 26;
    int order=1, offset=0;
    int m = (n-1)/N;
    while(m>0){
        offset += order;            // offset exists because of it needs to minus 1 on each decimal bit when calculating
        order *= N;                 // order=N^index
        m = (m-1)/N;
    }
    m = n;
    while(order>0){
        int x = (m - offset)/order;        // x is value on decimal bit of m
        printf("%c", 'A' + (x-1)%N);
        m -= order * x;
        offset -= order/N;
        order /= N;
    }
    printf("\n");   
}

int main(int argc, char* argv[]){
    int N=0;
    while(scanf("%d", &N) != EOF){    //scanf output
        if(N<1){
          printf("none\n");
          break;
        }
        columnName01(N);
        columnName02(N);
    }
    return 0;
}
