/*
 * some classical bit manipulation problem solutions
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
 * given a and b, find count of bits which can be converted from one to another
 * */
int convertBits(int a, int b){
    int count = 0;
    /*
    for(int c=a^b; c!=0; c = c>>1){
        count += c&1;
    }
    */
    for(int c=a^b; c!=0; c &= (c-1)){
        count++;
    }
    return count;
}

void test_01(){
    int a=0, b=0;
    scanf("%x,%x", &a, &b);
    printf("%d\n", convertBits(a,b));
    return;
}

/*
 * swap odd and even bits in an integer with as few instructions as possible
 * a typical bit manipulation problem. use mask of 10101010 and 01010101, leftwise and rightwise;
 * note: integer, 32 bit mask
 * */
int swapOddEvenBits(int x){
    return (((x & 0xaa)>>1) | ((x & 0x55)<<1));
}

void test_02(){
    int a=0;
    scanf("%x", &a);   //must be %x
    printf("%x\n", swapOddEvenBits(a));
    return;
}

/*
 * given two 32-bit numbers, N and M, and two bit positions, i and j. give a method to set all bits between i and j in N equal to M
 * e.g.
 * input:  N=100000000, M=10101, i=2, j=6
 * output: N=101010100 
 * 
 * solution:make a mask to OR with M from i to j
 * how to make the mask: a all 1's of N length minus all 1's of j length, OR a all 1's of i length
 * 
 * assume the position i starts from 0
 * */
int updateBits(int n, int m, int i, int j){
    int max = ~0;                         // all 1's
    int left = max - ((1<<(j+1)) - 1);    // j bit should be 0
    int right = (1<<i)-1;                 // i bit should be 0
    int mask = left | right;
    printf("mask is %x \n", mask);
    return (mask & n) | (m<<i);    
}

void test_03(){
    int n = 0,  m = 0, i=0, j=0;
    scanf("%x,%x,%d,%d", &n, &m, &i, &j);
    int result = updateBits(n,m,i,j);
    printf("n=%x, m=%x,result=%x \n",n,m,result);
    return;
}

/*
 * an array A[0..n] contains all the integers from 0 to n except for one number which is missing. The elements of A are represented in binary,and the only operations we can use to access them is "fetch jth bit of A[i]",which takes constant time. write code to find the missing integer, enable the time complexity in O(n)
 * */

/*
 *great observe and thinking!
 look at sequential list of integer
 00000000
 00000001
 00000010
 00000011
 00000100
 00000101...
 for the least significant bit(LBS, 0th bit) of all elements, count(0)>=count(1) (minus is 1,0)
 *(1)for a group of integer from 0 to n of binary without missing.
 if LBS of missing is 0, count(0) <= count(1); if LBS of missing is 1, count(0) > count(1)
 *(2)for the next iteration, we can remove all the elements which LBS is not what we want, focus on the second LBS etc.
 finally, we need O(n) + O(n/2) + O(n/4) + ... = O(n)

 * */

int main(int, char**){
    return 0;
}

