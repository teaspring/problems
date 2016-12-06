/**
 * Problem: given an input array where nums[i] != nums[i+1], find a peak element and return its index. Imagin nums[-1] = nums[n] = -episilon
 * time in O(lgn)
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findPeakElement(const vector<int>& nums) {
        const int n = nums.size();
        int u = 0, v = n; // v is exclusive
        while(u < v) {
            int m = (u + v)/2;
            if((m == 0 || nums[m] > nums[m-1])
                && (m == n-1 || nums[m] > nums[m+1])) {
                return m;
            } else if(nums[m] < nums[u]) {
                v = m;
            } else if(nums[m] < nums[v-1]) {
                u = m+1;
            } else {
                u += 1;
            }
        }

        return (u + v)/2;
    }
};
