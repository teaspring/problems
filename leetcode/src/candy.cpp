/*
 * there are N children standing in a line. Everyone is assigned a rating value.
 * you are giving candies to these children subjectd to the following requirements:
 * 1.each child must have at least one candy
 * 2.children with a higher rating get more candies than their neighbors.
 * what is the minimum candies you must give?
 *
 * hidden point: for 4 4 3, the minimum candies can be 1+2+1 = 4 
 *
 * test data:
 * 2 4 2 3 1 2
 * 4 2 3 4 1
 * */
#include "../include/preliminary.h"

class Solution{

public:
/*
 * idea: 
 * 1. do not start backtrack until the decending range closes
 * 2. if [i]=[i-1], neighbor's candy can be 1 in minimum
 * */
    int candy_1(vector<int>& ratings){
        int n = ratings.size();
        if(n < 2)    return n;  // 0 or 1
        int *candies = new int[n]();
        candies[0] = 1;
        int sum = 1, ki = -1;
        for(int i = 1; i < n; ++i){
            if(ratings[i] == ratings[i-1]){
                if(ki > -1)    continue;  // within decending range
                candies[i] = 1;
            }else if(ratings[i] > ratings[i-1]){
                if(ki > -1){  // [i-1] is start of previous preceding range
                    sum += backtrack(ratings, ki, i-1, candies);
                    ki = -1;
                }
                candies[i] = candies[i-1] + 1;
            }else{
                if(ki == -1)    ki = i-1; // [i-1] is start of preceding range
            }
            sum += candies[i];
        }
        if(ki > -1){
            sum += backtrack(ratings, ki, n-1, candies);
        }
        delete[] candies;
        candies = NULL;
        return sum;
    }
/*
 * idea:
 * forward and backward iterate to assign the ascending range in their eyes
 * compared to method1, method2 is better to read with less time complexity
 * */
    int candy_2(vector<int>& ratings) {
        const int n = ratings.size();
        if (n < 2)    return n; // 0 for 0, 1 for 1
        int *candies = new int[n]();
        
        candies[0] = 1;
        int sum = candies[0];
        for(int i = 1; i < n; i++){  // forward iterate
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }else{  // either [i]==[i-1] or [i]<[i-1], candies[i] has 1 at least
                candies[i] = 1;
            }
            sum += candies[i];
        }

        for(int i = n-2; i >= 0; i--){  // backward iterate to modify reversely ascending ones
            if(ratings[i] > ratings[i+1]){
                if (candies[i] < candies[i+1] + 1){
                    sum -= candies[i];
                    candies[i] = candies[i+1] + 1;
                    sum += candies[i];
                }
            }
        }

        delete[] candies;
        candies = NULL;
        return sum;
    }

private:
    /*
     * note:
     * 1. candies[l] > [r], while [r-1] >= [r]
     * 2. candies[l] has been set already
     * */
    int backtrack(vector<int>& ratings, int l, int r, int *candies){
        if(l >= r)    return 0;
        candies[r] = 1;
        int sum = 1;
        for(int i = r-1; i > l; --i){ // process candies[l] later
            candies[i] = (ratings[i] > ratings[i+1] ? candies[i+1] : 0) + 1;
            sum += candies[i];
        }
        int tmp = candies[l+1] + 1;
        if(tmp > candies[l]){    // complement candies[l]
            sum += tmp - candies[l];
            candies[l] = tmp;
        }
        return sum;
    }
};
/* unit test code is in ../cpp_unittest/candy_unittest */
