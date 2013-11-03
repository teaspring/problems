/*
 * question on Aug19. 
 * give a digit number x, get its brother number y, which is the least of those that greater than x
 *
 * test data:
 * 1234, 1243
 * 432, 0
 * 1522, 2125
 * 2521, 5122
 * */
#include "stdio.h"
using namespace std;

/*
 * the logic is: 
 * 1. iterate from low to high digit, stop when high digit is less than low digit. return 0 if not find.
 * 2. now the low digit range must be ascending. reverse the range
 * 3. iterate the reverted low digit range, find the least digit greater than high digit, swap it with high digit.
 * */
int reversedigit(int x){
    int r = 0;
    int y = x;
    while(y != 0){
        r *= 10;
    r += y % 10;
    y /= 10;
    }
    return r;
}

int getBrotherNum(int x){
    int y = x;
    int b = 10;
    int h = (y/b)%10;
    int l = y%10;
    while(h != 0 && h >= l){
        l = h;
        b *= 10;
        h = (y/b)%10;
    }
    if(h==0)    return 0;
    int rev = y % b;
    y = y  - rev + reversedigit(rev);            //reverse the low range
    
    int order = 1;
    l = y % 10;
    while(order <= b && h < l){                    //iterate the low range to find the least digit just greater than high digit
        order *= 10;
    l = (y/order)%10;
    }
    order /= 10;                    //get the digit just lower than l
    int s = (y / order) % 10;
    return y - h * b - s * order + h * order + s * b;    //swap digit h and s
}

int main(int argc, char* argv[]){
    int x=0;
    while(scanf("%d", &x) != EOF){
        int y = getBrotherNum(x);
        printf("brother number is %d\n", y);
    }
    return 0;
}
