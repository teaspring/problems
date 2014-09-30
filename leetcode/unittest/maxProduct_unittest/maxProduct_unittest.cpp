#include "maxProduct.cpp"
#include "gtest/gtest.h"

// Test case: maxProductTest
// Test name: negative
TEST(maxProductTest, Negative){
    Solution s;
    int arr1[] = {-2};
    EXPECT_EQ(-2, s.maxProduct(arr1, sizeof(arr1)/sizeof(int)));
    int arr2[] = {2,-2,3};
    EXPECT_EQ(3, s.maxProduct(arr2, sizeof(arr2)/sizeof(int)));
    int arr3[] = {2, 3, -2, 4};
    EXPECT_EQ(6, s.maxProduct(arr3, sizeof(arr3)/sizeof(int)));
    int arr4[] = {-2, -1, -3};
    EXPECT_EQ(3, s.maxProduct(arr4, sizeof(arr4)/sizeof(int)));
}

// Test case: maxProductTest
// Test name: Zero
TEST(maxProductTest, Zero){
    Solution s;
    int arr1[] = {-2, 0, -1};
    EXPECT_EQ(0, s.maxProduct(arr1, sizeof(arr1)/sizeof(int)));
    int arr2[] = {-2, 0, 2, 0, 3};
    EXPECT_EQ(3, s.maxProduct(arr2, sizeof(arr2)/sizeof(int)));
    int arr3[] = {-2, 2, 0, 0, 3, 2};
    EXPECT_EQ(6, s.maxProduct(arr3, sizeof(arr3)/sizeof(int)));
}

// Test case: maxProductTest
// Test name: Positive
TEST(maxProductTest, Positive){
    Solution s;
    int arr1[] = {2,2,3};
    EXPECT_EQ(12, s.maxProduct(arr1, sizeof(arr1)/sizeof(int)));
    int arr2[] = {1, -2, 2, -3, -2, -3, -3};
    EXPECT_EQ(108, s.maxProduct(arr2, sizeof(arr2)/sizeof(int)));
}
