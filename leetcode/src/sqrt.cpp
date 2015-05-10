/*
 * sqrt(1)           = 1     , N = 1
 * sqrt(10)          = 3     , N = 2
 * sqrt(100)         = 10    , N = 3
 * sqrt(1000)        = 31    , N = 4
 * sqrt(10000)       = 100   , N = 5
 * sqrt(100000)      = 316   , N = 6
 * sqrt(1000000)     = 1000  , N = 7
 * sqrt(10000000)    = 3162  , N = 8
 * sqrt(100000000)   = 10000 , N = 9
 * sqrt(1000000000)  = 31622 , N = 10
 * 2^31    = 2147483648,
 * 46340^2 = 2147395600
 * 2^30 = 1073741824
 * 2^15 = 32768
 */

using namespace std;

class Solution{

public:
    int sqrt(int x){
        if(x <= 0)    return 0;

        if(x >= 2147395600)    return 46340;

        int a = 1, b = 2;

        while(b * b < x){
            a = b;
            b *= 2;

            if(b > 46340){    // it has to code hard :(
                b = 46340;
                break;
            }
        }

        if(b * b == x)    return b;

        // now a*a < x && b*b > x while b = 2*a
        // find suitable int between a and b by binary search
        while(a < b){
            int m = (a + b) >> 1;

            if(m * m == x){
                return m;
            }else if(m * m < x){
                if(m == b-1)    return m;
                a = m;
            }else{
                b = m;
            }
        }

        return a;
    }
};

/* unit test is in ../cpp_unittest/sqrt_unittest */
