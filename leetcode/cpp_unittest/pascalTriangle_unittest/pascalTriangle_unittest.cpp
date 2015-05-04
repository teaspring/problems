/*
 * vector<vector<int> > generate(int nrows)
 * */

#include "pascalTriangle.cpp"
#include "gtest/gtest.h"
#include <algorithm>

/*
 * customized methods to facilitate test method
 * */
void assertList(vector<int>& expected, vector<int>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

void assertDuoList(vector<vector<int> >& expected, vector<vector<int> >& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        assertList(expected[i], result[i]);
    }
}

/*---------------------- test case ----------------------*/
TEST(pascalTriangleTest, Positive){
    Solution s;

    int arr0[] = {1};
    int arr1[] = {1, 1};
    int arr2[] = {1, 2, 1};
    int arr3[] = {1, 3, 3, 1};
    int arr4[] = {1, 4, 6, 4, 1};
    int arr5[] = {1, 5, 10, 10, 5, 1};

    vector<vector<int> > triangle;

    triangle.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    triangle.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    triangle.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    triangle.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));
    triangle.push_back(vector<int>(arr4, arr4 + sizeof(arr4) / sizeof(int)));
    triangle.push_back(vector<int>(arr5, arr5 + sizeof(arr5) / sizeof(int)));

    vector<vector<int> > expected;
    const int rows = triangle.size();

    for(int i = 1; i <= rows; i++){
        for(int j = 0; j < i; j++){
            expected.push_back(triangle[j]);
        }

        vector<vector<int> > result = s.generate(i);
        assertDuoList(expected, result);

        expected.clear();
        result.clear();
    }
}
