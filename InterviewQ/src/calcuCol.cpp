/*
 * 20130714, question1 on InterviewStreet, and it was on leetcode in 2010/10 as well:
 * In Excel, the column named as A(1), B(2), Z(26), AA(27), ...AZ
 * test data: 
 * 27(AA), 1378(AZZ), 676(YZ), 702(ZZ)
 * */
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

void numToStr01(int n){
    int index = 0;
    int sum = n;
    while((sum-1)/26){        //analysis 1-A, 26-Z, 26*26-YZ, 27*26-ZZ
        index++;
        sum = (sum-1)/26;
    }
    while(index>-1){            //time O(n^2), n is digits of N
        sum = n;
        for(int i=0;i<index;i++)
            sum = (sum-1)/26;
        printf("%c", 'A'+ (sum-1) % 26);
        index--;
    }
    printf("\n");
}

/*
 * based on method1, reduce internal iteration. time O(n) with n is digits of num
 * */
void numToStr02(int n){
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

/*
 * this problem appears on leetcode as well, below two solutions are its online solutions
 * note: if require A-0, B-1,...Z-25, AA-26, AB-27..., it only differs in the first line is n%26 and n/26 instead of n-1
 * */
void numToStr03(int n){
    string str(1, 'A' + (n-1)%26);
    n = (n-1)/26;
    while(n){
        str = (char)('A' + (n-1)%26) + str;
        n = (n-1)/26;
    }
    printf("%s\n", str.c_str());
    return;
}

/*
 * solution4 is converted from solution3 to recurse
 * */
void numToStrHelper(int n){
    if(n==0)    return;
    numToStrHelper((n-1)/26);
    printf("%c", 'A' + (n-1)%26);
    return;
}

void numToStr04(int n){
    numToStrHelper(n);
    cout<<endl;
}

int main(int argc, char* argv[]){
    string str;
    while(1){    //scanf() == EOF exit
        if(getline(cin, str)==0 || str.empty())
          break;
        int n = atoi(str.c_str());
        numToStr01(n);
        numToStr02(n);
        numToStr03(n);
        numToStr04(n);
    }
    return 0;
}
