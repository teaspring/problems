#include "uniqueBST.cpp"
#include "gtest/gtest.h"

/*
 * int numTrees(int)
 * */

TEST(uniqueBSTTest, Positive){
    Solution s;

    EXPECT_EQ(5, s.numTrees(3));

    EXPECT_EQ(14, s.numTrees(4));

    EXPECT_EQ(42, s.numTrees(5));
}
