#include "gtest/gtest.h"

using namespace std;

template<typename T>
void EXPECT_EQ_VEC(const vector<T>& expected, const vector<T>& result)
{
    EXPECT_EQ(expected.size(), result.size());
    for(auto e_it = expected.cbegin(), r_it = result.cbegin();
        e_it < expected.cend() && r_it < result.cend();
        e_it++, r_it++)
    {
        EXPECT_EQ(*e_it, *r_it);
    }
}