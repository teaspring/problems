#include "textJustification.cpp"
#include "gtest/gtest.h"

/*
 * vector<string> Solution::fullJustify(vector<int>& words, int L)
 * */

void assert_strings(vector<string>& expected, vector<string>& result){
    EXPECT_EQ(expected.size(), result.size());
    for(size_t i = 0; i < expected.size(); i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/* ----------------- test body -------------------- */
TEST(textJustificationTest, Positive01){
    Solution s;

    string wordsArr[] = {string("this"), string("is"), string("an"), string("example"),
        string("of"), string("text"), string("justification")};

    vector<string> words(wordsArr, wordsArr + 7);
    int L = 16;

    string expectedArr[] = {
        string("this    is    an"),
        string("example  of text"),
        string("justification   ")
    };

    vector<string> expected(expectedArr, expectedArr + 3);
    vector<string> result = s.fullJustify(words, L);

    assert_strings(expected, result);

    words.clear();
    expected.clear();
    result.clear();
}

TEST(textJustificationTest, Positive02){
    Solution s;

    string wordsArr[] = {string("this"), string("would"), string("be"), string("justification")};
    vector<string> words(wordsArr, wordsArr + 4);
    int L = 14;

    string expectedArr[] = {
        string("this  would be"),
        string("justification ")
    };

    vector<string> expected(expectedArr, expectedArr + 2);
    vector<string> result = s.fullJustify(words, L);

    assert_strings(expected, result);

    words.clear();
    expected.clear();
    result.clear();
}

TEST(textJustificationTest, Positive03){
    Solution s;

    string wordsArr[] = {string("to"), string("a"), string("few.")};
    vector<string> words(wordsArr, wordsArr + 3);
    int L = 6;

    string expectedArr[] = {
        string("to   a"),
        string("few.  ")
    };

    vector<string> expected(expectedArr, expectedArr + 2);
    vector<string> result = s.fullJustify(words, L);

    assert_strings(expected, result);

    words.clear();
    expected.clear();
    result.clear();
}

TEST(textJustificationTest, Positive04){
    Solution s;

    string wordsArr[] = {string("what"), string("must"), string("be"), string("shall"), string("be.")};
    vector<string> words(wordsArr, wordsArr + 5);
    int L = 12;

    string expectedArr[] = {
        string("what must be"),
        string("shall    be.")
    };

    vector<string> expected(expectedArr, expectedArr + 2);
    vector<string> result = s.fullJustify(words, L);

    assert_strings(expected, result);

    words.clear();
    expected.clear();
    result.clear();
}

TEST(textJustificationTest, Positive05){
    Solution s;

    string wordsArr[] = {string("Don't"), string("go"), string("around"), string("saying"),
        string("the"), string("world"), string("owes"), string("you"), string("a"), string("living")};

    vector<string> words(wordsArr, wordsArr + 10);
    int L = 30;

    string expectedArr[] = {
        string("Don't  go  around  saying  the"),
        string("world     owes  you  a  living")
    };

    vector<string> expected(expectedArr, expectedArr + 2);
    vector<string> result = s.fullJustify(words, L);

    assert_strings(expected, result);

    words.clear();
    expected.clear();
    result.clear();
}
