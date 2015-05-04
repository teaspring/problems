#include "plusOne.cpp"
#include "gtest/gtest.h"

/*
 * vector<int> plusOne(const vector<int>&)
 * */

void assertList(vector<int> &expected, vector<int> &result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/* ----------------- test body ---------------- */
TEST(plusOneTest, Positive01){
    Solution s;

    int A[] = {9};
    vector<int> digits(A, A + sizeof(A) / sizeof(int));

    int B[] = {1, 0};
    vector<int> expected(B, B + sizeof(B) / sizeof(int));

    vector<int> result = s.plusOne(digits);

    assertList(expected, result);

    digits.clear();
    expected.clear();
    result.clear();
}

TEST(plusOneTest, Positive02){
    Solution s;

    int A[] = {8, 9, 9};
    vector<int> digits(A, A + sizeof(A) / sizeof(int));

    int B[] = {9, 0, 0};
    vector<int> expected(B, B + sizeof(B) / sizeof(int));

    vector<int> result = s.plusOne(digits);

    assertList(expected, result);

    digits.clear();
    expected.clear();
    result.clear();
}
