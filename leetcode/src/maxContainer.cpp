/*
 * given n non-negative integers a1,a2...an, where each represents a point at (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at(i, ai) and (i,0).
 * Find two lines , which together with x-axis forms a container, such that this container has the maximum capacity of water
 *
 * |
 * | |
 * | | |
 * */
#include "../include/preliminary.h"

class Solution{

public:
    int maxWater(vector<int> &height){
        int s = 0, e = height.size() - 1;
        if(e < 1)    return 0;

        int water = 0;

        while(s < e){
            int tmp = min(height[e], height[s])*(e - s);
            water = max(water, tmp);

            int maxL = height[s];
            int maxR = height[e];

            if(height[s] < height[e]){ // move from lower wall
                do{
                    s++;
                }while(s < e && height[s] <= maxL); // skip hopeless points
            }else{
                do{
                    e--;
                }while(s < e && height[e] <= maxR);
            }
        }
        return water;
    }
};

/* unit test is in ../cpp_unittest/maxContainer_unittest */
