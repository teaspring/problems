/**
 * rotate an array of n elements to the right by k steps
 * E.g. for n=7, k=3, [1,2,3,4,5,6,7] => [5,6,7,1,2,3,4]
 * */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution{
public:
    void rotateArray(vector<int>& nums, int k) {
        const int n = nums.size();
        k %= n;
        if(k == 0)    return;

        int arr[n];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; ++i) {
            int idx = (i + k) % n;
            arr[idx] = nums[i];
        }
        nums = vector<int>(arr, arr + n);
        return;
    }
};
