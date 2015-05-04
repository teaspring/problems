#include "maxPoints.cpp"
#include "gtest/gtest.h"

/*
 * int maxPoints(vector<Point>&)
 * */

TEST(maxPoints_Test, Positive01){
    Solution s;

    int arr[] = {1,1, 3,3, 0,-1, 1,0, 4,4, 3,4, 5,4, 2,2, 1,2, 0,0, 2,1, 3,3};

    const int n = sizeof(arr) / sizeof(int);
    vector<Point> points;
    for(int i = 0; i < (n >> 1); i++){
        points.push_back(Point(arr[2*i], arr[2*i + 1]));
    }

    int expected = 6;

    EXPECT_EQ(expected, s.maxPoints(points));

    points.clear();
}

TEST(maxPoints_Test, Positive02){
    Solution s;

    int arr[] = {1,1, 3,3, 0,-1, 4,4};

    const int n = sizeof(arr) / sizeof(int);
    vector<Point> points;
    for(int i = 0; i < (n >> 1); i++){
        points.push_back(Point(arr[2*i], arr[2*i + 1]));
    }

    int expected = 3;

    EXPECT_EQ(expected, s.maxPoints(points));

    points.clear();
}
