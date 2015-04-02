/*
 * we have n gas statioin composing a loop.  gas[i] means the gas can be charged in station i, and cost[i] means the gas cost in the 
 * distance from [i] to [i+1](for [n-1], the next is [0])
 * assume our car has unlimited gas tank, ask whether can start from one station to run all of them
 *
 * test data:
 * gas{1,2,3,4,5}, cost{3,4,5,1,2}, n = 5, start = 3
 * */
#include "../include/preliminary.h"

class Solution{

public:
    int gasstation(vector<int>& gas, vector<int>& cost){
        const int n = gas.size();
        if(n < 1)    return -1;

        int start = 0; // start station
        int i = 0; // passed station
        int tank = gas[i] - cost[i];

        while(1){
            if(tank < 0){ // current start station is not qualified, move it backward
                while(tank < 0){
                    --start;
                    if(start < 0)     start += n;
                    if(start == i)    break;
                    tank += gas[start] - cost[start];
                }
                if(start == i)    return -1;
            }

            ++i; // move forward
            if(i >= n)    i -= n;

            if(i == start)    break;
            tank += gas[i] - cost[i];
        }
        return start;
    }
};

/* unit test is in ../cpp_unittest/gasstation_unittest */
