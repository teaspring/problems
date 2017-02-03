/*
 * given an array of n positive(unsorted) integers and a positive integer s, find the minimal length of a contiguous subarray of which the
 * sum >= s; if there is no answer, return 0
 * E.g [2,3,1,2,4,3], 7 => 2, as sub array [4,3] meets the requirment
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // idea of sliding window, time in O(n)
    int minSubArrayLen_01(int s, vector<int>& nums) {
        const int n = nums.size();
        int begin = 0, end = 0, sum = 0;
        int res = 0;
        while(begin < n && end < n) {
            for(;sum < s && end < n; ++end) {  // move end index
                sum += nums[end];
            }
            if(sum < s)    break; // else, end == n

            for(; sum - nums[begin] >= s; ++begin) {  // move begin index in case if we meets a very big nums[end-1]
                sum -= nums[begin];
            }
            int diff = end - begin;
            res = (res == 0 ? diff : min(res, diff));
            
            int offset = diff - res + 2; // +2 is better than +1
            for(int i = begin; i < n && i < begin + offset; ++i) {  // move begin index by offset to find the next less length
                sum -= nums[i];
            }
            begin += offset;
        }
        return res;
    }

    // another solution, time in O(nlgn)
    int minSubArrayLen_02(int s, vector<int>& nums) {
        int u = 1, v = nums.size() + 1; // [u,v)
        while(u < v) {
            int m = (u + v) >> 1;
            int sum1 = maxSubArrayFixedLen(nums, m);
            int sum2 = maxSubArrayFixedLen(nums, m-1); // sum2 <= sum1 definitely
            if(sum2 < s && s <= sum1)    return m;

            if(s <= sum2) {
                v = m;
            } else { // sum1 <= s
                u = m+1;
            }
        }
        return 0;
    }

private:
    int maxSubArrayFixedLen(vector<int>& nums, const int len) {
        const int n = nums.size();
        int sum = 0;
        for(int i = 0; i < len && i < n; ++i) {
            sum += nums[i];
        }
        if(len < 1)    return 0;
        if(len >= n)    return sum;

        int res = sum;
        for(int i = len; i < n; ++i) {
            sum -= nums[i - len];
            sum += nums[i];
            res = max(res, sum);
        }
        return res;
    }
};
