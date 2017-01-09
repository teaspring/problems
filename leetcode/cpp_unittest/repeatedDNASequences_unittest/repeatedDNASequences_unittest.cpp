#include "repeatedDNASequences.cpp"
#include "gtest/gtest.h"

/*
 * verify vector<string>
 * */
void assert_strings(vector<string>& expected, vector<string>& result){
    EXPECT_EQ(expected.size(), result.size());
    for(size_t i = 0; i < expected.size(); i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/*
 * vector<string> Solution::findRepeatedDnaSequences(const string&)
 * */
TEST(repeatedDNASequencesTest, Positive1_01){
    Solution s;
    string str("AGGTCTACCTTACCTTACCTAGGTCTACCT");

    vector<string> expected;
    expected.push_back(string("TACCTTACCT"));
    expected.push_back(string("AGGTCTACCT"));

    vector<string> res = s.findRepeatedDnaSequences(str);
    assert_strings(expected, res);
}

TEST(repeatedDNASequencesTest, Positive1_02){
    Solution s;
    string str("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

    vector<string> expected;
    expected.push_back(string("AAAAACCCCC"));
    expected.push_back(string("CCCCCAAAAA"));

    vector<string> res = s.findRepeatedDnaSequences(str);
    assert_strings(expected, res);
}

TEST(repeatedDNASequencesTest, Positive1_03){
    Solution s;
    string str("AACCAAAGTTACACCAAAGTTAGTA");

    vector<string> expected;
    expected.push_back(string("ACCAAAGTTA"));

    vector<string> res = s.findRepeatedDnaSequences(str);
    assert_strings(expected, res);
}

