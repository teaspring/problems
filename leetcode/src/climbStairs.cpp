/*
 * given a stair of n steps, every time you can climb 1 or 2 steps, ask how many ways to climb the n steps.
 */

#include "stdio.h"
#include <iostream>
using namespace std;

class ClimbStairs{
public:
    /*
     * recurse is avoided as it has too much redundancy
     * the state transfer is s[i] = s[i-1] + s[i-2], Fibonacci serial
     * */
    int climbStairs(int n){
        if(n <= 0)    return 0;
        int a = 1, b = 1, c=0;
        for(int i = 2; i<=n; ++i){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    void test_01(){
        cout << "for 3 steps:  " << climbStairs(3)  << " ways" << endl;
        cout << "for 10 steps: " << climbStairs(10) << " ways" << endl;
    }
};

int main(){
    ClimbStairs *cs = new ClimbStairs();
    cs->test_01();
    delete cs;
    cs = 0;
    return 0;
}
