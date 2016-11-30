/*
 * Problem I: given a list of non-negative integers representing the amount of money of each house. determine the max amount of money you
 * can rob tonight without alerting the police via robbing two adjacent houses.
 * */

#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int rob(const vector<int>& nums) {
        const int n = nums.size();
        if(n == 0)    return 0;
        if(n == 1)    return nums[0];
        if(n == 2)    return max(nums[0], nums[1]);

        int robbery[n];
        memset(robbery, 0, sizeof(robbery));
        robbery[0] = nums[0];
        robbery[1] = nums[1];

        int maxRob[n];
        memset(maxRob, 0, sizeof(maxRob));
        maxRob[0] = robbery[0];
        maxRob[1] = max(robbery[0], robbery[1]);

        for(int i = 2; i < n; ++i) {
            robbery[i] = maxRob[i-2] + nums[i];
            maxRob[i] = max(robbery[i-1], robbery[i]);
        }
        return maxRob[n-1];
    }
};
