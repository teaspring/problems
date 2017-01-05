/*
 * Two Sum II - input array is sorted
 * given an array of integers sorted in ascending order, find two nums such that they add up to a target num.
 * note: returned index are not 0-based; index1 must be less than index2; and each input would have exactly one solution
 * e.g. input: {2, 7, 11, 15}, target = 9
 *      output: index array: {1, 2} which means {2} and {7}
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    /**
     * e.g. {2,4,5,8,12,17,24}
     * 2 sum matrix:
     *    2+2, 2+4, 2+5, 2+8, 2+12,  2+17,  2+24
     *         4+4, 4+5, 4+8, 4+12,  4+17,  4+24
     *              5+5, 5+8, 5+12,  5+17,  5+24
     *                   8+8, 8+12,  8+17,  8+24
     *                        12+12, 12+17, 12+24
     *                               17+17, 17+24
     * firstly binary search along the diagonal
     * secondly, binary search vertically in each column from left to right
     * time in O(lgn*lgn)
     * */
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;

        const int n = numbers.size();
        int ui = 0, uj = 1, vi = n-2, vj = n-1; // vi and vj are inclusive edge
        int mi = 0, mj = 1;
        // firstly binary search along the diagonal
        while(ui <= vi && uj <= vj) {
            mi = (ui + vi)/2;
            mj = mi + 1;
            if(get2Sum(numbers, mi, mj) == target) {
                res.push_back(mi + 1);
                res.push_back(mj + 1);
                return res;
            } else if(get2Sum(numbers, mi, mj) > target) {
                vi = mi;
                vj = mj;
            } else if(get2Sum(numbers, mi+1, mj+1) <= target) {
                ui = mi+1;
                uj = mj+1;
            } else {
                break;
            }
        }

        // secondly vertical binary search in columns
        while(uj < n) {
            uj = vj = mj + 1;
            ui = 0;
            vi = mi;

            mj = uj;
            while(ui <= vi) {
                mi = (ui + vi)/2;
                if (get2Sum(numbers, mi, mj) == target) {
                    res.push_back(mi + 1);
                    res.push_back(mj + 1);
                    return res;
                } else if (get2Sum(numbers, mi, mj) > target) {
                    vi = mi;
                } else if (get2Sum(numbers, mi+1, mj) <= target) { // note it is "<="
                    ui = mi + 1;
                } else {
                    break;
                }
            }

            // regress to horizontal binary search in row0
            if (vi == 0) {
                vj = n-1;
                mi = ui = 0;
                while(uj <= vj) {
                    mj = (uj + vj)/2;
                    if (get2Sum(numbers, mi, mj) == target) {
                        res.push_back(mi + 1);
                        res.push_back(mj + 1);
                        return res;
                    } else if (get2Sum(numbers, mi, mj) > target) {
                        vj = mj;
                    } else {
                        uj = mj+1;
                    }
                }
                break;  // no need to enter vertical binary search again
            }
        }
        return res;
    }

private:
    inline int get2Sum(const vector<int>& nums, int i, int j) {
        const int n = nums.size();
        int a = (i >= 0 && i < n) ? nums[i] : 0;
        int b = (j >= 0 && j < n) ? nums[j] : 0;
        return a+b;
    }
};
