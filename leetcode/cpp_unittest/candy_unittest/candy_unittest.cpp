#include "candy.cpp"
#include "gtest/gtest.h"

/* int Solution::candy(vector<int>&) */

// Test case: candyTest
// Test name: Positive
TEST(candyTest, Positive01){
    Solution s;

	int arr[]     = {1, 2, 4, 4, 4, 2, 2, 2, 1};
	int candies[] = {1, 2, 3, 1, 2, 1, 1, 2, 1};
	int expected = 0;
	int n = sizeof(arr) / sizeof(int);
	for(int i=0; i < n; i++){
		expected += candies[i];
	}

	vector<int> ratings(arr, arr + n);
	EXPECT_EQ(expected, s.candy(ratings));
}
