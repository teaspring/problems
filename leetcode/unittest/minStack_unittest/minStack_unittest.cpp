#include "minStack.cpp"
#include "gtest/gtest.h"

// Test case: minStackI_Test
// Test name: positive
TEST(minStackI_Test, Positive){
    MinStackI s;
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

// Test case: minStackII_Test
// Test name: positive
TEST(minStackII_Test, Positive){
    MinStackII s;
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

// Test case: minStackII_Test
// Test name: negative
TEST(minStackII_Test, Negative){
    MinStackII s;
    s.push(-1);
    EXPECT_EQ(-1, s.top());
    EXPECT_EQ(-1, s.getMin());
    s.push(0);
    EXPECT_EQ(0, s.top());
    EXPECT_EQ(-1, s.getMin());
    EXPECT_NO_THROW(s.pop());
    EXPECT_NO_THROW(s.pop());
}
