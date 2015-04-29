#include "mergeSortedArray.cpp"
#include "gtest/gtest.h"

/*
 * void merge(int A[], int m, int B[], int n)
 * */

void assertArray(int expected[], int result[], const int n){
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/* ------------------- test body ------------------ */
TEST(mergeSortedArrayTest, Positive01){
    Solution s;

    int A[10] = {1, 2, 4};
    const int n1 = 3;

    int B[] = {0, 3, 6, 8, 10};
    const int n2 = sizeof(B)/sizeof(int);

    s.merge(A, n1, B, n2);

    int expected[] = {0, 1, 2, 3, 4, 6, 8, 10};

    assertArray(expected, A, n1 + n2);
}

TEST(mergeSortedArrayTest, Positive02){
    Solution s;

    int A[10] = {6, 8, 10};
    const int n1 = 3;

    int B[] = {0, 1, 2, 3, 4};
    const int n2 = sizeof(B)/sizeof(int);

    s.merge(A, n1, B, n2);

    int expected[] = {0, 1, 2, 3, 4, 6, 8, 10};

    assertArray(expected, A, n1 + n2);
}

TEST(mergeSortedArrayTest, Positive03){
    Solution s;

    int A[10] = {1, 4, 10};
    const int n1 = 3;

    int B[] = {0, 2, 3, 6, 8};
    const int n2 = sizeof(B)/sizeof(int);

    s.merge(A, n1, B, n2);

    int expected[] = {0, 1, 2, 3, 4, 6, 8, 10};

    assertArray(expected, A, n1 + n2);
}
