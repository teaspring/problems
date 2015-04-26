#include "sortColors.cpp"
#include "gtest/gtest.h"

/*
 * void sortColors_1(int[], int n)
 * void sortColors_2(int[], int n)
 * */

TEST(sortColors1_Test, Positive01){
    Solution s;

    int arr[] = {1, 2, 2, 0, 1, 0, 1, 0, 2, 1};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {0, 0, 0, 1, 1, 1, 1, 2, 2, 2};

    s.sortColors_1(arr, n);
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(sortColors2_Test, Positive01){
    Solution s;

    int arr[] = {1, 2, 2, 0, 1, 0, 1, 0, 2, 1};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {0, 0, 0, 1, 1, 1, 1, 2, 2, 2};

    s.sortColors_2(arr, n);
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}
