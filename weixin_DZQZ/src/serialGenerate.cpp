/* 
 * question on Aug08
 * generate a serial of digital: 2^i+5^j in ascending
 * 1,2,4,5,8,10,16,20,25,32,40,50,64,80,100,125,128,160,200,250,256,320,400,500,512
 * method1 and method2 is my own, method3 is by author. Unfortunately, method1 and method2 are incorrect.
 * */
#include "stdio.h"
using namespace std;

void generate3(int n){
    int* arr = new int[n]();
    int i2=0,i5=0;
    int m=1;
    int x2=m, x5=m;
    for(int i=0;i<n;++i){
        m = (x2<x5) ? x2:x5;
        arr[i] = m;
        printf("%d,", m);
        
        if(x2==m){            
            x2 = arr[i2]*2;
            ++i2;
        }
        if(x5==m){
            x5 = arr[i5]*5;
            ++i5;
        }
    }
    printf("\n");
    
    delete[] arr;
    arr = 0;
    return;
}

/*
 * abandoned. this method is wrong.
 * */
int func_serial(int n){
    if(n<1)    return 0;
    int I[5]={0,3,1,4,2};
    int J[5]={1,0,1,0,1};
    int i=0,j=0;
    switch(n){
        case 1:
        case 2:
        case 3:
            i = n-1;
            break;
        default:
            i = I[(n-4)%5];
            j = (n-4)/5 + J[(n-4)%5];
            break;
    }
    int res = 1;
    for(;i>0;i--)
      res*=2;
    for(;j>0;j--)
      res*=5;
    return res;
}

/*
 * abandoned. the method is wrong
 * */
void generate1(int n){
    int i=0,j=0;
    int res=1;
    printf("%d", res);
    n--;
    while(n>0){
        if(i>1){                    //increase by 5/4, but this is not the least increasement, as there is 128/125
            i-=2;
            res /= 4;
            ++j;
            res *= 5;
        }else if(j>1){                //increase by 32/25
             j-=2;
             res /= 25;
             i+=5;
             res *= 32;
        }else if(j>0){                //increase by 8/5
            --j;
            res /= 5;
            i+=3;
            res *= 8;
        }else {                        //increase by 2, but it not be here. there are 25/16, 125/64...
            i++;
            res *= 2;
        }
        printf(",%d",res);
        n--;
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    int n=0;
    while(scanf("%d", &n)!= EOF){
        printf("method1: ");
        generate1(n);
        printf("method3: ");
        generate3(n);
    }
    return 0;
}
