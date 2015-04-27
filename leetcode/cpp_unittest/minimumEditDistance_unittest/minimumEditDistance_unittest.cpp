#include "minimumEditDistance.cpp"
#include "gtest/gtest.h"

/*
 * int minDistance(const string& word1, const string& word2)
 * */

TEST(minimumEditDistanceTest, Positive01){
    Solution s;

    string word1("");
    string word2("a");

    int expected = 1;
    EXPECT_EQ(expected, s.minDistance(word1, word2));
}

TEST(minimumEditDistanceTest, Positive02){
    Solution s;

    string word1("a");
    string word2("b");

    int expected = 1;
    EXPECT_EQ(expected, s.minDistance(word1, word2));
}

TEST(minimumEditDistanceTest, Positive03){
    Solution s;

    string word1("eabc");
    string word2("acd");

    int expected = 3;
    EXPECT_EQ(expected, s.minDistance(word1, word2));
}

TEST(minimumEditDistanceTest, Positive04){
    Solution s;

    string word1("abcde");
    string word2("acda");

    int expected = 2;
    EXPECT_EQ(expected, s.minDistance(word1, word2));
}
