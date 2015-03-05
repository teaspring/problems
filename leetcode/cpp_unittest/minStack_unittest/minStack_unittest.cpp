#include "minStack.cpp"
#include "gtest/gtest.h"

// Test case: minStackIV_Test
// Test name: positive01
TEST(minStackIV_Test, Positive01){
    MinStackIV s;
    s.push(3);
    s.push(1);
    s.push(2);
    s.push(-1);
    EXPECT_EQ(-1, s.getMin());
    EXPECT_NO_THROW(s.pop());
    EXPECT_EQ(1, s.getMin());
    EXPECT_EQ(2, s.top());
    EXPECT_NO_THROW(s.pop());
    EXPECT_EQ(1, s.top());
    EXPECT_NO_THROW(s.pop());
    EXPECT_EQ(3, s.getMin());
    EXPECT_NO_THROW(s.pop());
}

// Test case: minStackIV_Test
// Test name: positive02
TEST(minStackIV_Test, Positive02){
    MinStackIV s;
    s.push(-1);
    EXPECT_EQ(-1, s.top());
    EXPECT_EQ(-1, s.getMin());
}

// Test case: minStackIV_Test
// Test name: negative
TEST(minStackIV_Test, Negative){
    MinStackIV s;
    s.push(-1);
    EXPECT_EQ(-1, s.top());
    EXPECT_EQ(-1, s.getMin());
    s.push(0);
    EXPECT_EQ(0, s.top());
    EXPECT_EQ(-1, s.getMin());
    EXPECT_NO_THROW(s.pop());
    EXPECT_NO_THROW(s.pop());
}
