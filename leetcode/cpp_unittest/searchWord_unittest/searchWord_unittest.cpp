#include "searchWord.cpp"
#include "gtest/gtest.h"
#include <algorithm>

// bool exist(const vector<vector<char> >& board, const string& word)
TEST(searchWordTest, Positive01){
    Solution1 s;

    const int rows = 3, cols = 4;
    char arr[][cols] = {
        {'A', 'B', 'C', 'D'},
        {'B', 'F', 'C', 'H'},
        {'A', 'C', 'B', 'A'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    string word1("BCE");
    EXPECT_FALSE(s.exist(board, word1));

    string word2("CFA");
    EXPECT_FALSE(s.exist(board, word2));

    string word3("BABA");
    EXPECT_TRUE(s.exist(board, word3));

    string word4("BCCB");
    EXPECT_TRUE(s.exist(board, word4));

    board.clear();
}

// facilitate methods to help to assert string vector
bool comparestr(string str1, string str2){ // comparator of two strings in ascending order
    return strcmp(str1.c_str(), str2.c_str()) <= 0;
}

bool assertTwoStrVectors(vector<string>& expected, vector<string>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    sort(expected.begin(), expected.end(), comparestr);
    sort(result.begin(), result.end(), comparestr);

    for(int i = 0; i < n; i++){
        EXPECT_STREQ(expected[i].c_str(), result[i].c_str());
    }
    return true;
}

// Solution1::vector<string> findWords(vector<vector<string> >& board, vector<string>& words)
TEST(searchWordII_Solution1_Test, Positive01){
    Solution1 s;

    const int rows = 3, cols = 4;
    char arr[][cols] = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    vector<string> words;
    words.push_back("oath");
    words.push_back("pea");
    words.push_back("eat");
    words.push_back("rain");

    vector<string> result = s.findWords(board, words);

    vector<string> expected;
    expected.push_back("oath");
    expected.push_back("eat");

    assertTwoStrVectors(expected, result);
    board.clear();
}

TEST(searchWordII_Solution1_Test, Negative01){
    Solution1 s;

    const int rows = 1, cols = 2;
    char arr[][cols] = {
        {'a', 'a'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    vector<string> words;
    words.push_back("aaa");

    vector<string> result = s.findWords(board, words);

    EXPECT_TRUE(result.empty());;
    board.clear();
}

TEST(searchWordII_Solution1_Test, Negative02){
    Solution1 s;

    const int rows = 1, cols = 1;
    char arr[][cols] = {{'a'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    vector<string> words;
    words.push_back("a");
    words.push_back("a");

    vector<string> result = s.findWords(board, words);

    vector<string> expected;
    expected.push_back("a");

    assertTwoStrVectors(expected, result);
    board.clear();
}

// Solution2::vector<string> findWords(vector<vector<string> >& board, vector<string>& words)
TEST(searchWordII_Solution2_Test, Positive01){
    Solution2 s;

    const int rows = 3, cols = 4;
    char arr[][cols] = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    vector<string> words;
    words.push_back("oath");
    words.push_back("pea");
    words.push_back("eat");
    words.push_back("rain");

    vector<string> result = s.findWords(board, words);

    vector<string> expected;
    expected.push_back("oath");
    expected.push_back("eat");

    assertTwoStrVectors(expected, result);
    board.clear();
}

TEST(searchWordII_Solution2_Test, Negative01){
    Solution2 s;

    const int rows = 1, cols = 2;
    char arr[][cols] = {
        {'a', 'a'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    vector<string> words;
    words.push_back("aaa");

    vector<string> result = s.findWords(board, words);

    EXPECT_TRUE(result.empty());;
    board.clear();
}

TEST(searchWordII_Solution2_Test, Negative02){
    Solution2 s;

    const int rows = 1, cols = 1;
    char arr[][cols] = {{'a'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    vector<string> words;
    words.push_back("a");
    words.push_back("a");

    vector<string> result = s.findWords(board, words);

    vector<string> expected;
    expected.push_back("a");

    assertTwoStrVectors(expected, result);
    board.clear();
}
