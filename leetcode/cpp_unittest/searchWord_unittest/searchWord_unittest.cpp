#include "searchWord.cpp"
#include "gtest/gtest.h"

/*
 * bool exist(const vector<vector<char> >& board, const string& word)
 * */

TEST(searchWordTest, Positive01){
    Solution s;

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
