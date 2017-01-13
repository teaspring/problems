/*
 * count the number of primes less than a non-negative int n. ps: 1 is not prime, 2 is the smallest prime
 *
 * analysis:
 * 1. the normal definition of prime is any n cannot be divided by 2,3,4,...sqrt(n)
 * 2. if i is prime, i-1 and i+1 will never be prime, so we can iterate i by +=2
 * 3. to determine whether i is prime, try to divide i by primes 3, 5, 7, 11... hwo to do it efficiently?
 * */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
    int countPrimes(int n) {
        if(n <= 2)    return 0;

        int sum = 1; // for prime integer 2
        // 1. as n may be very large, this internal container cannot be bool[] or int[] which is consistent memory
        // 2. passed[] is defined of size n, but inside loop, we do not traverse by 1, instead by 2
        vector<bool> passed(n, false);
        int upper = sqrt(n); // use sqrt(n) as upper bound to prevent overflow of i*i

        for(int i = 3; i < n; i += 2) {
            if(!passed[i]) {
                sum++;
                if(i > upper)    continue;
                for(int j = i*i; j < n; j += i) {
                    passed[j] = true;
                }
            }
        }
        return sum;
    }
};
