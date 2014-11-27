#include "rotatedSortedArray.cpp"
#include "gtest/gtest.h"

// Test case: rotatedSortedArrayTest
// Test name: positive
TEST(rotatedSortedArrayTest, Positive){
    Solution s;
    int arr1[] = {1,3,3,3};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    EXPECT_EQ(1, s.findMinII(vec1));

    int arr2[] = {2,2,2,1,1};
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    EXPECT_EQ(1, s.findMinII(vec2));

    int arr3[] = {1,1,3};
    vector<int> vec3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    EXPECT_EQ(1, s.findMinII(vec3));
}

// Test case: rotatedSortedArrayTest
// Test name: edge
TEST(rotatedSortedArrayTest, Edge){
    Solution s;
    int arr1[] = {1,1};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    EXPECT_EQ(1, s.findMinII(vec1));

    int arr2[] = {1,2,2,0,1,1};
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    EXPECT_EQ(0, s.findMinII(vec2));

    int arr3[] = {3,1};
    vector<int> vec3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    EXPECT_EQ(1, s.findMinII(vec3));
}
