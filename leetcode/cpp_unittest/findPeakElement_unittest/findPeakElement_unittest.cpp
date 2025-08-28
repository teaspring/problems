#include "findPeakElement.cpp"
#include "gtest/gtest.h"

/*
 * facilitate methods
 * */
vector<int> findAllPeaks(const vector<int>& nums) {
    vector<int> res;
    const int n = nums.size();
    if(n == 1) {
        res.push_back(0);
        return res;
    }

    for(int i = 0; i < n; i++) {
        if((i == n-1 || nums[i] > nums[i+1])
            && (i == 0 || nums[i] > nums[i-1])) {
            res.push_back(i);
        }
    }

    return res;
}

bool isContained(vector<int>& nums, int idx) {
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        if (*it == idx)    return true;
    }
    return false;
}

/*
 * int findPeakElement(vector<int>&)
 * */
TEST(findPeakElementTest, Positive01){
    vector<int> nums{5, 4, 3, 2, 1};
    Solution s;
    EXPECT_EQ(0, s.findPeakElement(nums));
    nums.clear();
}

TEST(findPeakElementTest, Positive02){
    vector<int> nums{4, 3, 2, 1};
    Solution s;
    EXPECT_EQ(0, s.findPeakElement(nums));
    nums.clear();
}

TEST(findPeakElementTest, Positive03){
    vector<int> nums{1, 2, 3, 4};
    Solution s;
    EXPECT_EQ(3, s.findPeakElement(nums));
    nums.clear();
}

TEST(findPeakElementTest, Positive04){
    vector<int> nums{1, 2, 3};
    Solution s;
    EXPECT_EQ(2, s.findPeakElement(nums));
    nums.clear();
}

TEST(findPeakElementTest, Positive05){
    vector<int> nums{5, 3, 2, 1, 4};
    vector<int> allPeaks = findAllPeaks(nums);

    Solution s;
    int idx = s.findPeakElement(nums);
    EXPECT_TRUE(isContained(allPeaks, idx));
    nums.clear();
}

TEST(findPeakElementTest, Positive06){
    vector<int> nums{1, 5, 1};
    Solution s;
    EXPECT_EQ(1, s.findPeakElement(nums));
    nums.clear();
}

TEST(findPeakElementTest, Positive07){
    vector<int> nums{1, 1, 5, 1};
    Solution s;
    EXPECT_EQ(2, s.findPeakElement(nums));
    nums.clear();
}

TEST(findPeakElementTest, Positive08){
    vector<int> nums{1, 5, 1, 1};
    Solution s;
    EXPECT_EQ(1, s.findPeakElement(nums));
    nums.clear();
}

TEST(findPeakElementTest, Edge01){
    vector<int> nums{1};
    Solution s;
    EXPECT_EQ(0, s.findPeakElement(nums));
    nums.clear();
}
