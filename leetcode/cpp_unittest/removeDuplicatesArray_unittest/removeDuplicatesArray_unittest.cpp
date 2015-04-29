#include "removeDuplicatesArray.cpp"
#include "gtest/gtest.h"

/*
 * int remove(int A[], int n)
 * int removeII(int A[], int n);
 * */

void assertArray(int expected[], const int n, int result[]){
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/* ----------------- test body -------------------- */
TEST(removeTest, Positive01){
    Solution s;

    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 4, 5};

    int resultLength = s.remove(arr, n);

    assertArray(expected, resultLength, arr);
}

TEST(removeIITest, Positive01){
    Solution s;

    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5, 5, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 1, 2, 3, 3, 4, 5, 5, 6};

    int resultLength = s.removeII(arr, n);

    assertArray(expected, resultLength, arr);
}
