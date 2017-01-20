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

/*
 * vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisits)
 * */
void assertTopoOrder(int numCourses, vector<pair<int, int> >& prerequisites, vector<int>& order) {
    for(auto relation : prerequisites) {
        const int n = order.size();
        EXPECT_EQ(numCourses, n);

        int preIdx = -1, baseIdx = -1;
        for(int i = 0; i < n; i++) {
            if(order[i] == relation.second)    preIdx = i;
            if(order[i] == relation.first)    baseIdx = i;
        }
        EXPECT_TRUE(preIdx < baseIdx);
    }
}

TEST(findOrderTest, Positive01){
    Solution s;
    vector<pair<int, int> > prerequisites;
    pair<int, int> pre1(1, 0);
    prerequisites.push_back(pre1);
    pair<int, int> pre2(2, 0);
    prerequisites.push_back(pre2);
    pair<int, int> pre3(3, 1);
    prerequisites.push_back(pre3);
    pair<int, int> pre4(3, 2);
    prerequisites.push_back(pre4);

    int num = 4;
    vector<int> res = s.findOrder(num, prerequisites);
    assertTopoOrder(num, prerequisites, res);
    prerequisites.clear();
}

