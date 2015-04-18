#include "rotatedSortedArray.cpp"
#include "gtest/gtest.h"

/*
 * int search(int A[], int n, int key) // find key, the rotated sorted array has no duplicate
 *
 * int searchII(int A[], int n, int key) // find key, the rotated sorted array has duplicate
 *
 * int findMinII(vector<int>&)
 *
 *
 * */
TEST(findMin_Test, Positive){
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

TEST(findMin_Test, Edge){
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

TEST(searchI_Test, Positive01){
    Solution s;

    int arr1[] = {5, 6, 1, 2, 3};
    int n = sizeof(arr1)/sizeof(int);

    for(int i = 0; i < n; i++){
        int expected = i;
        int key = arr1[i];
        EXPECT_EQ(expected, s.search(arr1, n, key));
    }

    EXPECT_EQ(-1, s.search(arr1, n, 0));
    EXPECT_EQ(-1, s.search(arr1, n, 4));
    EXPECT_EQ(-1, s.search(arr1, n, 7));
}

TEST(searchI_Test, Positive02){
    Solution s;

    int arr1[] = {2, 3, 4, 6, 8, 1};
    int n = sizeof(arr1)/sizeof(int);

    for(int i = 0; i < n; i++){
        int expected = i;
        int key = arr1[i];
        EXPECT_EQ(expected, s.search(arr1, n, key));
    }
}

TEST(searchII_Test, Positive01){
    Solution s;

    int arr1[] = {1, 1, 5, 1, 1, 1, 1, 1};
    int n = sizeof(arr1)/sizeof(int);

    int key = 5;
    int expected = 2;
    EXPECT_EQ(expected, s.searchII(arr1, n, key));

    EXPECT_EQ(-1, s.search(arr1, n, 0));
    EXPECT_EQ(-1, s.search(arr1, n, 2));
    EXPECT_EQ(-1, s.search(arr1, n, 4));
    EXPECT_EQ(-1, s.search(arr1, n, 8));
}

TEST(searchII_Test, Positive02){
    Solution s;

    int arr1[] = {5, 5, 6, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr1)/sizeof(int);

    EXPECT_EQ(2, s.searchII(arr1, n, 6));
    EXPECT_EQ(3, s.searchII(arr1, n, 1));
    EXPECT_EQ(6, s.searchII(arr1, n, 3));
}

TEST(searchII_Test, Positive03){
    Solution s;

    int arr1[] = {2, 2, 3, 4, 5, 5, 1};
    int n = sizeof(arr1)/sizeof(int);

    EXPECT_EQ(2, s.searchII(arr1, n, 3));
    EXPECT_EQ(3, s.searchII(arr1, n, 4));
    EXPECT_EQ(6, s.searchII(arr1, n, 1));
}
