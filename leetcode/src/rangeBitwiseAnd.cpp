/*
 * given a range [m, n] where 0 <= m <= n <= 2^31, return the bitwise AND of all numbers in this range, inclusive.
 * E.g. given range [5, 7], return 4
 * */
#include <iostream>

using namespace std;

class Solution{
public:
    // Solution:
    // 0101 (5)
    // 0110 (6)
    // 0111 (7) we can find that if the bit of all numbers have '0', the AND result of that bit is 0
    int rangeBitwiseAnd(int m, int n) {
        if(m == n)    return m;

        int res = 0;
        int l = 0;
        while(m > 0) {
            res = res << 1;
            if(n == m) {
                res |= (n & 1);
            }
            m >>= 1;
            n >>= 1;
            ++l;
        }
        return reverseBitwise(res, l); // don't forget to reverse the bits of res
    }

private:
    int reverseBitwise(int num, int length) {
        if(length == 1 || num == 0)    return num;

        int res = 0;
        for(int i = 0; i <= length/2; i++) { // note: the loop should include (length/2)
            int h = (num >> (length - 1 - i)) & 1;
            int l = (num >> i) & 1;

            res |= l << (length - 1 - i);
            res |= h << i;
        }
        return res;
    }
};
