/*
 * Problem I:
 * given an integer array of size n, find the majority element. In concept, majorith element is the one that appears more than n/2 times.
 * assume the array is non empty and there is always a mojority element.a
 *
 * Problem II:
 * if given even sized array, there is one majority element appears exactly n/2 times, how to find it?
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    /*
     * this solution utilize the condition 'more than n/2 times'
     * */
    int majorityElementI(vector<int>& nums) {
        const int n = nums.size();
        int major = nums[0], cnt = 1;
        for(int i = 1; i < n; i++) {
            if (cnt == 0) {
                major = nums[i];
                cnt++;
            } else if (major == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return major;
    }
};
