#include "addSearchWord.cpp"
#include "gtest/gtest.h"

/*
 * addSearchWord.cpp, class WordDictionary()
 * void insert(string word)
 * bool search(string word)
 * */
TEST(WordDictionaryTest, Positive01){
    WordDictionary *trie = new WordDictionary();
    trie->addWord(string("bad"));
    trie->addWord(string("dad"));
    trie->addWord(string("mad"));

    EXPECT_FALSE(trie->searchWord(string("pad")));
    EXPECT_TRUE(trie->searchWord(string("bad")));
    EXPECT_TRUE(trie->searchWord(string(".ad")));
    EXPECT_FALSE(trie->searchWord(string("b.")));
    EXPECT_TRUE(trie->searchWord(string("b..")));
    EXPECT_FALSE(trie->searchWord(string(".b.")));
    EXPECT_TRUE(trie->searchWord(string(".a.")));

    delete trie;
    trie = NULL;
}

