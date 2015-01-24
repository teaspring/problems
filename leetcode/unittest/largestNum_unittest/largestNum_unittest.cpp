#include "largestNum.cpp"
#include "gtest/gtest.h"

// Test case: Function_Test
// Test name: Positive01
TEST(Function_Test, Positive01){
    Solution s;
    int arr[] = {3, 30, 34, 5, 9};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));
    string str = s.largestNumber(num);
    EXPECT_EQ("9534330", str);
}

// Test case: Function_Test
// Test name: Positive02
TEST(Function_Test, Positive02){
    Solution s;
    int arr[] = {824, 8247};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));
    string str = s.largestNumber(num);
    EXPECT_EQ("8248247", str);
}

// Test case: Function_Test
// Test name: Positive03
TEST(Function_Test, Positive03){
    Solution s;
    int arr[] = {12, 121};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));
    string str = s.largestNumber(num);
    EXPECT_EQ("12121", str);
}

// Test case: Function_Test
// Test name: Positive04
TEST(Function_Test, Positive04){
    Solution s;
    int arr[] = {12, 121, 122};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));
    string str = s.largestNumber(num);
    EXPECT_EQ("12212121", str);
}

// Test case: Edge_Test
// Test name: Zero
TEST(Edge_Test, Zero){
    Solution s;
    int arr[] = {1, 2, 0, 0, 3};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));
    string str = s.largestNumber(num);
    EXPECT_EQ("32100", str);
}

// Test case: Edge_Test
// Test name: AllZero
TEST(Edge_Test, AllZero){
    Solution s;
    int arr[] = {0, 0, 0, 0};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));
    string str = s.largestNumber(num);
    EXPECT_EQ("0", str);
}

// Test case: Edge_Test
// Test name: MultiZero
TEST(Edge_Test, MultiZero){
    Solution s;
    int arr[] = {0, 0, 0, 1, 0};
    vector<int> num(arr, arr + sizeof(arr)/sizeof(int));
    string str = s.largestNumber(num);
    EXPECT_EQ("10000", str);
}
