/*
 * write a method to determine if a number is 'happy'
 * Definition:
 * starting from any positive number, replace the number by the sum of the squares of its digits, and repeat the process until
 * the number equals to 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. those numbers for which the
 * process ends in 1 is 'happy numbers'
 * */
#include <iostream>

using namespace std;

class Solution{
public:
    // without container(set), use an automatic 2X accelarator to complete the digit square sum cycling.
    bool isHappyNumber(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while (slow != fast);
        return fast == 1;
    }

private:
    int digitSquareSum(int n) {
        int sum = 0;
        while(n) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
};
