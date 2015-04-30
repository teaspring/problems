#include "removeElement.cpp"
#include "gtest/gtest.h"

/*
 * int removeElement(int[], int n, int element)
 * */

void assertArray(int expected[], const int n, int result[]){
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/* ------------------- test body ------------------- */
TEST(removeElementTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 4, 4, 4, 2, 2, 2, 1};
    const int n = sizeof(arr) / sizeof(int);

    int x = 2;
    int resultLen = s.removeElement(arr, n, x);

    int expected[] = {1, 4, 4, 4, 1};

    assertArray(expected, resultLen, arr);
}
