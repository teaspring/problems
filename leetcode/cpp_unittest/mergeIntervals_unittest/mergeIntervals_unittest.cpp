#include "mergeIntervals.cpp"
#include "gtest/gtest.h"

/*
 * vector<Interval> merge(vector<Interval>& intervals)
 * */

vector<Interval> constructIntervals(int *A, int *B, int n){
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

/* ------------- test body -------------- */
TEST(mergeIntervalsTest, Positive01){
    Solution s;

    int A[] = {1, 8, 2, 15};
    int B[] = {3, 10, 6, 18};
    vector<Interval> intervals = constructIntervals(A, B, sizeof(A)/sizeof(int));

    int C[] = {1, 8, 15};
    int D[] = {6, 10, 18};
    vector<Interval> expected = constructIntervals(C, D, sizeof(C)/sizeof(int));

    vector<Interval> result = s.merge(intervals);
    assertIntervals(expected, result);

    intervals.clear();
    expected.clear();
    result.clear();
}

TEST(mergeIntervalsTest, Positive02){
    Solution s;

    int A[] = {1, 5, 2, 4, 11};
    int B[] = {4, 6, 3, 5, 13};
    vector<Interval> intervals = constructIntervals(A, B, sizeof(A)/sizeof(int));

    int C[] = {1, 11};
    int D[] = {6, 13};
    vector<Interval> expected = constructIntervals(C, D, sizeof(C)/sizeof(int));

    vector<Interval> result = s.merge(intervals);
    assertIntervals(expected, result);

    intervals.clear();
    expected.clear();
    result.clear();
}
