/**
 * reverse bits of given 32 bits unsigned integer,
 * e.g. given: 43261596 (0b00000010100101000001111010011100),
 *     return: 964176192(0b00111001011110000010100101000000)
 *
 * the point is: bitwise is very sharp in bit move, so it is not for in-place process, use an int32 or 64 to be the base
 * */
#include <iostream>

using namespace std;


class Solution {

public:
    uint32_t reverseBits(uint32_t num) {
        uint32_t res = 0;
        for(int i = 0; i < 16; ++i) {
            uint32_t h = (num >> (31 - i)) & 1;
            uint32_t l = (num >> i) & 1;

            res |= l << (31 - i);
            res |= h << i;
        }
        return res;
    }
};
