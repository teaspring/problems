/*******************chapter 5 recursion, exercise 10  ***********************
* calculate sum of n items in one series
* 1 + 1/2 - 1/3 + 1/4 - 1/5 + 1/6 - 1/7...
*/

/*
 * for n > 2, f(n) = f(n-1) + (-1)^(n%2)*(1/n)
 * if n==2, f(n) = 1+1/2 
 * */
#include <iostream>
using namespace std;

float recurSeries(unsigned int n){
    switch(n){
        case 0:
        case 1:
            return n;
        default:
            return recurSeries(n-1) + (n%2 ? -1.0 : 1.0)*(float)1/n;
    }
}

int main(int argc, char* argv[]){
    while(1){
        unsigned int x;
        cin >> x;
        cout << recurSeries(x)<<endl;
    }
    return 0;
}

        
