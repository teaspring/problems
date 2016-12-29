#include "reverseBits.cpp"
#include "gtest/gtest.h"

/*
 * uint32_t Solution::reverseBits(uint32_t string&)
 * */
TEST(reverseBitsTest, Positive1_01){
    Solution s;

    uint32_t num = 43261596;
    EXPECT_EQ(964176192, s.reverseBits(num));
}

