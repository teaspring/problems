#include "excelColumnTitle.cpp"
#include "gtest/gtest.h"

/* int Solution::titleToNumber(string) */
TEST(ExcelTitleToNumber_Test, Positive1){
    Solution s;
    
    EXPECT_EQ(26, s.titleToNumber(string("Z")));
    EXPECT_EQ(27, s.titleToNumber(string("AA")));
    EXPECT_EQ(52, s.titleToNumber(string("AZ")));
    EXPECT_EQ(53, s.titleToNumber(string("BA")));
    EXPECT_EQ(731, s.titleToNumber(string("ABC")));
}

/* string Solution::numToTitle(int) */
TEST(ExcelNumberToTitle_Test, Positive1){
    Solution s;
    
    EXPECT_EQ("A", s.numToTitle(1));
    EXPECT_EQ("Z", s.numToTitle(26));
    EXPECT_EQ("AA", s.numToTitle(27));
    EXPECT_EQ("BA", s.numToTitle(53));
    EXPECT_EQ("ABC", s.numToTitle(731));
}
