/*
 * vector<int> getRow(int k)
 * */

#include "pascalTriangleII.cpp"
#include "gtest/gtest.h"

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

/*---------------------- test case ----------------------*/
TEST(pascalTriangleIITest, Positive){
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

    const int rows = triangle.size();
    for(int i = 0; i < rows; i++){
        vector<int> expected = triangle[i];

        vector<int> result = s.getRow(i);
        assertList(expected, result);

        expected.clear();
        result.clear();
    }
}
