#include "insertIntervals.cpp"
#include "gtest/gtest.h"

/*
 * vector<Interval> insert(vector<Interval>& intervals, Interval newElement)
 * */

vector<Interval> constructVector(int *A, int *B, int n){
    vector<Interval> vec;
    for(int i = 0; i < n; i++){
        vec.push_back(Interval(A[i], B[i]));
    }
    return vec;
}

void assertIntervals(const vector<Interval>& expected, const vector<Interval>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i].start, result[i].start);
        EXPECT_EQ(expected[i].end, result[i].end);
    }
}

/* ----------------- test body ---------------- */

// insert intermedia position
TEST(insertIntervalsTest, Positive01){
    Solution s;

    int A[] = {1, 4, 6};
    int B[] = {2, 5, 7};
    vector<Interval> intervals = constructVector(A, B, sizeof(A)/sizeof(int));

    Interval nElement(3, 4);

    int C[] = {1, 3, 4, 6};
    int D[] = {2, 4, 5, 7};
    vector<Interval> expected = constructVector(C, D, sizeof(C)/sizeof(int));

    vector<Interval> result = s.insert(intervals, nElement);
    assertIntervals(expected, result);

    intervals.clear();
    expected.clear();
    result.clear();
}

// insert after tail
TEST(insertIntervalsTest, Positive02){
    Solution s;

    int A[] = {1, 4, 6};
    int B[] = {2, 5, 7};
    vector<Interval> intervals = constructVector(A, B, sizeof(A)/sizeof(int));

    Interval nElement(7, 9);

    int C[] = {1, 4, 6, 7};
    int D[] = {2, 5, 7, 9};
    vector<Interval> expected = constructVector(C, D, sizeof(C)/sizeof(int));

    vector<Interval> result = s.insert(intervals, nElement);
    assertIntervals(expected, result);

    intervals.clear();
    expected.clear();
    result.clear();
}

// insert in front of head
TEST(insertIntervalsTest, Positive03){
    Solution s;

    int A[] = {1, 4, 6};
    int B[] = {2, 5, 7};
    vector<Interval> intervals = constructVector(A, B, sizeof(A)/sizeof(int));

    Interval nElement(0, 1);

    int C[] = {0, 1, 4, 6};
    int D[] = {1, 2, 5, 7};
    vector<Interval> expected = constructVector(C, D, sizeof(C)/sizeof(int));

    vector<Interval> result = s.insert(intervals, nElement);
    assertIntervals(expected, result);

    intervals.clear();
    expected.clear();
    result.clear();
}
