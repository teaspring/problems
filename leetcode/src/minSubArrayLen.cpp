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
            while(sum < s && end < n) {  // move end index
                sum += nums[end];
                ++end;
            }
            if(sum < s)    break; // else, end == n

            for(; sum - nums[begin] >= s; ++begin) {  // move begin index in case if we meets a very big nums[end-1]
                sum -= nums[begin];
            }
            int diff = end - begin;
            res = (res == 0 ? diff : min(res, diff));
            
            int offset = diff - res + 1;
            for(int i = begin; i < begin + offset; ++i) {  // move begin index by offset to find the next less length
                sum -= nums[i];
            }
            begin += offset;
        }
        return res;
    }
};
