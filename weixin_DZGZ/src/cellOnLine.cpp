/*
 * question on Aug20
 * give two point p1:[x1,y1],p2:[x2,y2]. output the cell points on line p1-p2, and between p1 and p2  
 * 
 * design test cases prior to coding:
 * [1,2],[1,2]    //no
 * [1,2],[1,3]    //no
 * [1,2],[3,5]    //no
 * [1,2],[1,5]    //[1,3],[1,4]
 * [1,2],[3,6]    //[2,4]
 * */
#include "stdio.h"
using namespace std;

void highlow(int& high, int& low){
    if(high < low){
        int tmp = low;
        low = high;
        high = tmp;
    }
}

int getGCD(int x, int y){
    highlow(x, y);
    if (y == 0)    return x;    //on concept, it should return x
    while(x % y != 0){
        int d = x % y;
        x = y;
        y = d;
    }
    return y;
}

void findCellNode(int x1, int y1, int x2, int y2){
    int yLow=y1, yHigh=y2, xLow=x1, xHigh=x2;
    highlow(yHigh, yLow);
    highlow(xHigh, xLow);
    int xDist = xHigh - xLow;
    int yDist = yHigh - yLow;
    int d = getGCD(xDist, yDist);   
    if(d == 1 || d == 0){            //all other exceptional criteria can be merged to this case
        printf("no cell node in line between p1 and p2!\n");
        return;
    }

    int rev = 0;
    if((x1-x2) * (y1-y2) > 0)
        rev = 1;                    //x1>x2,y1>y2 or x1<x2,y1<y2
    for(int i=1;i<d;i++){
        if(rev){
            printf("[%d,%d]  ",    xLow + xDist/d * i, yLow + yDist/d * i);
        }else{
            printf("[%d,%d]  ", xLow + xDist/d * i, yHigh - yDist/d * i);
        }
    }
    printf("\n");
    return;
}

int main(int argc, char* argv[]){
    int x1=0,y1=0,x2=0,y2=0;
    while(scanf("%d%d%d%d", &x1,&y1,&x2,&y2) != EOF){
        findCellNode(x1, y1, x2, y2);
    }
    return 0;
}
