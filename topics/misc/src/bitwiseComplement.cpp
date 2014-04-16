
#include "stdio.h"

/*
 * bitwise complement(~) means flip all bits
 * definition: NOT x = -x -1; -x = NOT x + 1. NOT is ~
 * ~(-5) == 4;
 * ~4 == -5
 * x is odd => -x is odd
 *
 * bitwise XOR(^), for signed int(32 bits), -x == Not x + 1.
 * -1 is 0xffffffff, -5 is 0xfffffffb
 * (-5) ^ (-6) == 0xfffffffb ^ 0xfffffffa == b1011 ^ b1010 = 1
 * (-4) ^ (-5) == 0xfffffffc ^ 0xfffffffb == b1100 ^ b1011 = b111 = 7
 * (-3) ^ (-4) == b101 ^ b100 = 1
 * (-2) ^ (-3) == b110 ^ b101 = b11 = 3
 * conclusion: -x and -x-1. if -x is odd(last position is 1), -x-1 is even, ^ concludes 1
 *                          if -x is even, -x-1 is odd, ^ concludes greater than 1
 * */
void bitwiseComplement(){
    for(int i = -5; i < 5; i++){            
        printf("%d Not(~) %d \n", i, ~i);
    }
    printf("----------------------------\n");

    for(int i = -5; i < 5; i++){            
        printf("%d x^(x-1) \n", i^(i-1));
        printf("----------------------------\n");            
        //in C++, if integer is operated with unsigned int, integer will be converted to unsigned
        unsigned int s = 3;
        printf("%u\n", s*(-1));    // -1 will be converted to unsigned 0xffffffff, mutilplied with 3,
        // stack overflow !!!
        //in C#, no such convertion here
    }
}

int main(int, char**){
    bitwiseComplement();
    return 0;
}
