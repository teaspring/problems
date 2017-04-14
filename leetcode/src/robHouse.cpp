/*
 * Problem I: given a list of non-negative integers representing the amount of money of each house. determine the max amount of money you
 * can rob tonight without alerting the police via robbing two adjacent houses.
 *
 * Problem II: extension of Problem I, all houses are placed in circle.
 * */

#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int rob(const vector<int>& nums) {
        return robFromTo_02(nums, 0, nums.size());
    }

    int robII(const vector<int>& nums) {
        const int n = nums.size();
        if(n == 0)    return 0;
        if(n == 1)    return nums[0];
        return max(robFromTo_02(nums, 0, n-1), robFromTo_02(nums, 1, n)); // smart process of the two options
    }

private:
    /*
     * start is inclusive, end is exclusive
     * */
    int robFromTo_01(const vector<int>& nums, int start, int end) {
        const int n = nums.size();
        if(n == 0 || start < 0 || start >= n || end <= start || end > n)
          return 0;

        vector<int> robbery(n, 0); // robbery[i] means max robbery among nums[0..j], no matter nums[i] is held or not
        robbery[start] = nums[start];

        for(int i = start; i < end; ++i) {
            int tmp = (i - start > 1 ? robbery[i-2] : 0) + nums[i];
            robbery[i] = max((i > start ? robbery[i-1] : 0), tmp);
        }
        return robbery[end-1];
    }

    /*
     * more simple and more concise
     * it can be extracted from _01 by using two int var instead of int[]
     * */
    int robFromTo_02(const vector<int>& nums, int start, int end) {
        int include = 0, exclude = 0; // exclude means max robbery without nums[i]
        for(int i = start; i < end; i++) {
            int inc = include;
            include = exclude + nums[i];
            exclude = max(exclude, inc);
        }
        return max(include, exclude);
    }
};
