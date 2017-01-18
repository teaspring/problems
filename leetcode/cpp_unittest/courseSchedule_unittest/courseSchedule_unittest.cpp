#include "courseSchedule.cpp"
#include "gtest/gtest.h"

/*
 * bool canFinish(int numCourses, vector<pair<int, int> >& prerequisits)
 * */
TEST(canFinishTest, Positive01){
    Solution s;
    vector<pair<int, int> > prerequisites;
    pair<int, int> pre1(1, 0);
    prerequisites.push_back(pre1);
    pair<int, int> pre2(2, 1);
    prerequisites.push_back(pre2);
    pair<int, int> pre3(3, 2);
    prerequisites.push_back(pre3);
    pair<int, int> pre4(4, 2);
    prerequisites.push_back(pre4);

    EXPECT_TRUE(s.canFinish(5, prerequisites));
    prerequisites.clear();
}

TEST(canFinishTest, Negative01){
    Solution s;
    vector<pair<int, int> > prerequisites;
    pair<int, int> pre1(1, 0);
    prerequisites.push_back(pre1);
    pair<int, int> pre2(0, 1);
    prerequisites.push_back(pre2);

    EXPECT_FALSE(s.canFinish(2, prerequisites));
    prerequisites.clear();
}

TEST(canFinishTest, Negative02){
    Solution s;
    vector<pair<int, int> > prerequisites;
    pair<int, int> pre1(1, 0);
    prerequisites.push_back(pre1);
    pair<int, int> pre2(2, 1);
    prerequisites.push_back(pre2);
    pair<int, int> pre3(3, 2);
    prerequisites.push_back(pre3);
    pair<int, int> pre4(4, 3);
    prerequisites.push_back(pre4);
    pair<int, int> pre5(0, 4);
    prerequisites.push_back(pre5);

    EXPECT_FALSE(s.canFinish(5, prerequisites));
    prerequisites.clear();
}

