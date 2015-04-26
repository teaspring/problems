#include "waterjug.cpp"
#include "gtest/gtest.h"

/*
 * void sortjugs(int *A, int *B, int n)
 * */

TEST(waterjugs_Test, Positive01){
    Solution s;

    int arrA[] = {1, 3, 10, 8, 12, 5, 15, 7, 2, 11};
    int arrB[] = {5, 2, 11, 3, 8, 12, 1, 15, 10, 7};

    const int n = sizeof(arrA) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 7, 8, 10, 11, 12, 15};
    s.sortjugs(arrA, arrB, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arrA[i]);
        //EXPECT_EQ(expected[i], arrB[i]);
    }
}

