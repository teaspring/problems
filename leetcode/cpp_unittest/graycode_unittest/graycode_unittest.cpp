#include "graycode.cpp"
#include "gtest/gtest.h"

/*
 * vector<int> Solution::graycode_01(int)
 *
 * vector<int> Solution::graycode_02(int)
 * */

bool vectorContains(vector<int>& expected, int x){
    const int n = expected.size();
    for(int i = 0; i < n; i++){
        if(expected[i] == x)    return true;
    }
    return false;
}

bool assertVectorInt(vector<int>& expected, vector<int>& result){
    EXPECT_EQ(expected.size(), result.size());
    const int n = expected.size();

    for(int i = 0; i < n; i++){
        vectorContains(expected, result[i]);
        vectorContains(result, expected[i]);
    }
    return true;
}

/* ------------- test case -------------- */
TEST(grayCode_Test, Positive01){
    Solution s;

    int n = 3;
    int arr[] = {0,  /* 000 */
                 1,  /* 001 */
                 3,  /* 011 */
                 2,  /* 010 */
                 6,  /* 110 */
                 7,  /* 111 */
                 5,  /* 101 */
                 4}; /* 100 */
    vector<int> expected(arr, arr + sizeof(arr)/sizeof(int));

    vector<int> result1 = s.grayCode_1(n);
    EXPECT_TRUE(assertVectorInt(expected, result1));

    vector<int> result2 = s.grayCode_2(n);
    EXPECT_TRUE(assertVectorInt(expected, result2));

    result1.clear();
    result2.clear();
    expected.clear();
}
