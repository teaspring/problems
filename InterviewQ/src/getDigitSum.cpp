/*
 * @input param: a, b, n
 * 0 2 2 4 6 1 0 1 1 2 3 5 8 1 3 4 7 1 1 2 3 5 8...
 * 3 4 7 1 1 2 3 5 8 1 3 4 7 1 1 2 3 5 8 1 3 4 7...
 * 6 8 1 4 5 9 1 4 5 9 1 4 5 9...
 * 6 6 1 2 3 5 8 1 3 4 7 1 1 2 3 5 8 1 3 4 7 1 1...
 * 6 7 1 3 4 7 1 1 2 3 5 8 1 3 4 7 1 1 2 3 5 8 1 3...
 * 6 9 1 5 6 1 1 2 3 5 8 1 3 4 7 1 1 2 3 5 8 1 3 4
 * @output: the nth number
 * 
 * date: Jan29, 2013
 * */

#include <stdio.h>

/*
 * assume a>=0, b>=0, n>=1 
 * */
int GetSumNum(int a, int b, int n){
    if(a<0 || b<0 || n<1){
        printf("Invalid input parameter!!!");
        return -1;
    }
    if(a==0 && b==0)        return 0;
    
    while(n>2){
        int c = a+b;
        if(c > 9){
            a = 1;
            b = c - 10;
            n-=2;
        }else{
            a=b;
            b=c;
            n--;
        }
    }

    switch(n){
        case 2:
            return b;
        case 1:
            return a;
        default:
            return -1;
    }
}

int main(int, char*){
    int a=0, b=0, c=0, n=0;
    while(scanf("%d%d%d", &a, &b, &c) != 0){
        printf("The result  is %d \n", GetSumNum(a,b,n));
    }
    return 0;
}
