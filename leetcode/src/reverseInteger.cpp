/*
 * reverse digits of an integer
 * ie, 123 => 321,
 * -123 => -321
 * */

#include <climits>

using namespace std;

class Solution{

public:
    int reverse(int x){  // take care of positive and negative overflow
        if(x == 0)    return 0;

        int y = 0;

        while(x != 0){
            int resi = x % 10;

            if(x > 0){
                if(y >= INT_MAX / 10 || INT_MAX < resi + y * 10)    return INT_MAX;
            }else{
                if(y <= INT_MIN / 10 || INT_MIN > resi + y * 10)    return INT_MIN;
            }

            y = y * 10 + resi;

            x /= 10;
        }

        return y;
    }
};
