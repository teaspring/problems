/*
 * Problem Description: in a Rectangle of N*N(length), how many rectangles among it
 * time:20130306
 * Compile error: for loop declarations are allowed only in c99.
 * solution: add -std=c99 in compile
 * */
#include <stdio.h>

int RectangleCount(int length, int width){
    if(length < 0 || width < 0){
        printf("Non-negtive argument! \n");
        return 0;
    }

    int sum = 0;
    for(int i=length; i>0;i--){
        for(int j=width; j>0; j--){
            sum += i*j;
        }
    }
    return sum;
}

int OutputRectangle(int length, int width){
    if(length < 0 || width < 0){
        printf("Non-negtive argument! \n");
        return 0;
    }

    int sum = 0;
    for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
            for(int p=i+1; p<length+1; p++){
                for(int q=j+1; q<width+1; q++){
                    printf("[%d, %d], [%d, %d]\n", i, j, p, q);
                    sum++;
                }
            }
        }
    }
    return sum;    
}

void test_01(){
    int Length = 3, Width = 3;
    int sum1 = RectangleCount(Length, Width);
    int sum2 = OutputRectangle(Length, Width);
    printf("sum1=%d, sum2=%d\n", sum1, sum2);
    return;
}

int main(int argc, char** argv){
    test_01();
    return 0;
}
