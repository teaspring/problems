#include "findmedian.cpp"
#include "gtest/gtest.h"

/* int Solution::findMedianSortedArrays(int *A, int m, int *B, int n) */

TEST(findmedianTest, SameSize01){
    Solution s;

    int A[] = {1, 2};
    int B[] = {3, 4};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, SameSize02){
    Solution s;

    int A[] = {1, 2};
    int B[] = {4, 5};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 3.0;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, SameSize03){
    Solution s;

    int A[] = {1, 3};
    int B[] = {2, 4};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, SameSize04){
    Solution s;

    int A[] = {1, 2};
    int B[] = {1, 2};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 1.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, SameSize05){
    Solution s;

    int A[] = {1, 4};
    int B[] = {2, 3};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, SameSize06){
    Solution s;

    int A[] = {1, 3, 5, 8};
    int B[] = {2, 4, 6, 7};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 4.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Empty01){
    Solution s;

    int A[] = {};
    int B[] = {1, 2, 3, 4};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Empty02){
    Solution s;

    int A[] = {1, 2, 3};
    int B[] = {};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.0;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Single01){
    Solution s;

    int A[] = {1};
    int B[] = {1};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 1.0;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Single02){
    Solution s;

    int A[] = {1};
    int B[] = {2, 3, 4};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Single03){
    Solution s;

    int A[] = {1};
    int B[] = {2, 3, 4, 5};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 3.0;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Single04){
    Solution s;

    int A[] = {2};
    int B[] = {1, 3, 4};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Single05){
    Solution s;

    int A[] = {3};
    int B[] = {1, 2, 4};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Single06){
    Solution s;

    int A[] = {1, 2, 3, 5, 6};
    int B[] = {4};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 3.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, Single07){
    Solution s;

    int A[] = {1, 2, 3, 4};
    int B[] = {5};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 3.0;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}


TEST(findmedianTest, DiffSize01){
    Solution s;

    int A[] = {1, 1};
    int B[] = {2, 3, 4, 5};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 2.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, DiffSize02){
    Solution s;

    int A[] = {1, 2, 3};
    int B[] = {4, 5};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 3.0;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, DiffSize03){
    Solution s;

    int A[] = {6, 7, 8};
    int B[] = {1, 2, 3, 4, 5};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 4.5;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, DiffSize04){
    Solution s;

    int A[] = {0, 1, 2};
    int B[] = {4, 5, 6, 7};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 4.0;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}

TEST(findmedianTest, DiffSize05){
    Solution s;

    int A[] = {4, 5, 6, 7};
    int B[] = {3, 8, 9};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    double expected = 6.0;

    EXPECT_EQ(expected, s.findMedianSortedArrays(A, m, B, n));
}
