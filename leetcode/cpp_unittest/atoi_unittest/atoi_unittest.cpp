#include "atoi.cpp"
#include "gtest/gtest.h"

/* int Solution::myatoi(const char*) */

TEST(atoiTest, Positive01){
    Solution s;
    const char *arr = "+2";

    int expected = 2;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Positive02){
    Solution s;
    const char *arr = " 110d";

    int expected = 110;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Positive03){
    Solution s;
    const char *arr = " -13d";

    int expected = -13;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Positive04){
    Solution s;
    const char *arr = " 2147483647"; // 2^31 - 1

    int expected = 2147483647;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Positive05){
    Solution s;
    const char *arr = " -2147483648"; // -2^31

    int expected = -2147483648;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Positive06){
    Solution s;
    const char *arr = " 14dof"; // -2^31

    int expected = 14;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Zero01){
    Solution s;
    const char *arr = "++2";

    int expected = 0;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Zero02){
    Solution s;
    const char *arr = " .3 2";

    int expected = 0;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Zero03){
    Solution s;
    const char *arr = " --3";

    int expected = 0;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Zero04){
    Solution s;
    const char *arr = " fx";

    int expected = 0;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Zero05){
    Solution s;
    const char *arr = "-(1+2)";

    int expected = 0;
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Negative01){
    Solution s;
    const char *arr = " 2147483648";  // 2^31

    int expected = 2147483647; // 2^31 - 1
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Negative02){
    Solution s;
    const char *arr = " 2147483649";  // 2^31 + 1

    int expected = 2147483647; // 2^31 - 1
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Negative03){
    Solution s;
    const char *arr = " 2147483650";  // 2^31 + 2

    int expected = 2147483647;  // 2^31 - 1
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Negative04){
    Solution s;
    const char *arr = " -2147483649";  // -2^31 - 1

    int expected = -2147483648;  // -2^31
    EXPECT_EQ(expected, s.myatoi(arr));
}

TEST(atoiTest, Negative05){
    Solution s;
    const char *arr = " -2147483650";  // -2^31 - 2

    int expected = -2147483648;  // -2^31
    EXPECT_EQ(expected, s.myatoi(arr));
}
