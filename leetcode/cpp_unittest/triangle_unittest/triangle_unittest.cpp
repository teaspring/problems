#include "triangle.cpp"
#include "gtest/gtest.h"

/*
 * int minTotal_01(vector<vector<int> >&)
 * int minTotal_02(vector<vector<int> >&)
 * */

/* ------------ test cases of solution 1 ------------- */
TEST(triangle1_Test, Positive01){
    Solution s;

    int arr0[] = {2};
    int arr1[] = {3, 4};
    int arr2[] = {6, 5, 7};
    int arr3[] = {4, 1, 8, 3};

    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    triangle.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    triangle.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    triangle.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));

    int expected = 2 + 3 + 5 + 1;

    EXPECT_EQ(expected, s.minTotal_01(triangle));

    triangle.clear();
}

TEST(triangle1_Test, Positive02){
    Solution s;

    int arr0[] = {2};
    int arr1[] = {3, 4};
    int arr2[] = {6, 5, 7};
    int arr3[] = {4, 1, 8, 3};
    int arr4[] = {0, 2, 3, 1, 2};
    int arr5[] = {3, 1, 0, 2, 4, 1};
    int arr6[] = {2, 3, 5, 1, 3, 1, 2};


    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    triangle.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    triangle.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    triangle.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));
    triangle.push_back(vector<int>(arr4, arr4 + sizeof(arr4) / sizeof(int)));
    triangle.push_back(vector<int>(arr5, arr5 + sizeof(arr5) / sizeof(int)));
    triangle.push_back(vector<int>(arr6, arr6 + sizeof(arr6) / sizeof(int)));

    int expected = 2 + 3 + 5 + 1 + 2 + 0 + 1;

    EXPECT_EQ(expected, s.minTotal_01(triangle));

    triangle.clear();
}

/* ------------ test cases of solution 2 ------------- */
TEST(triangle2_Test, Positive01){
    Solution s;

    int arr0[] = {2};
    int arr1[] = {3, 4};
    int arr2[] = {6, 5, 7};
    int arr3[] = {4, 1, 8, 3};

    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    triangle.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    triangle.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    triangle.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));

    int expected = 2 + 3 + 5 + 1;

    EXPECT_EQ(expected, s.minTotal_02(triangle));

    triangle.clear();
}

TEST(triangle2_Test, Positive02){
    Solution s;

    int arr0[] = {2};
    int arr1[] = {3, 4};
    int arr2[] = {6, 5, 7};
    int arr3[] = {4, 1, 8, 3};
    int arr4[] = {0, 2, 3, 1, 2};
    int arr5[] = {3, 1, 0, 2, 4, 1};
    int arr6[] = {2, 3, 5, 1, 3, 1, 2};


    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    triangle.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    triangle.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    triangle.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));
    triangle.push_back(vector<int>(arr4, arr4 + sizeof(arr4) / sizeof(int)));
    triangle.push_back(vector<int>(arr5, arr5 + sizeof(arr5) / sizeof(int)));
    triangle.push_back(vector<int>(arr6, arr6 + sizeof(arr6) / sizeof(int)));

    int expected = 2 + 3 + 5 + 1 + 2 + 0 + 1;

    EXPECT_EQ(expected, s.minTotal_02(triangle));

    triangle.clear();
}
