#include "prefixTree.cpp"
#include "gtest/gtest.h"

/*
 * prefixTree.cpp, class Trie()
 * Trie()
 * ~Trie()
 * void insert(string word)
 * bool search(string word)
 * bool startWith(string prefix)
 *
 * */
TEST(TrieTest, Positive01){
    Trie *trie = new Trie();

    trie->insert(string("christmas"));
    trie->insert(string("Sunday"));
    trie->insert(string("Sunshine"));
    trie->insert(string("xman"));
    trie->insert(string("xwoman"));

    EXPECT_TRUE(trie->search(string("xman")));
    EXPECT_TRUE(trie->search(string("Sunday")));

    EXPECT_FALSE(trie->search(string("Sun")));
    EXPECT_TRUE(trie->startWith(string("Sun")));

    delete trie;
    trie = NULL;
}

TEST(TrieTest, Positive02){
    Trie *trie = new Trie();
    trie->insert(string("a"));

    EXPECT_TRUE(trie->search(string("a")));
    EXPECT_TRUE(trie->startWith(string("a"))); // test case from oj.leetcode.com, understand its meaning of startWith()

    delete trie;
    trie = NULL;
}

TEST(TrieTest, Positive03){
    Trie *trie = new Trie();

    trie->insert(string("abc"));
    EXPECT_TRUE(trie->search(string("abc")));
    EXPECT_FALSE(trie->search(string("ab")));

    trie->insert(string("ab"));
    EXPECT_TRUE(trie->search(string("ab")));

    trie->insert(string("ab"));
    EXPECT_TRUE(trie->search(string("ab")));

    delete trie;
    trie = NULL;
}

/*
 * prefixTree.cpp, class TrieInts()
 * Trie()
 * ~Trie()
 * void insert(string word)
 * bool search(string word)
 * bool startWith(string prefix)
 *
 * */
TEST(TrieIntsTest, Positive01){
    Trie *trie = new Trie();

    trie->insert(string("christmas"));
    trie->insert(string("sunday"));
    trie->insert(string("sunshine"));
    trie->insert(string("xman"));
    trie->insert(string("xwoman"));

    EXPECT_TRUE(trie->search(string("xman")));
    EXPECT_TRUE(trie->search(string("sunday")));

    EXPECT_FALSE(trie->search(string("sun")));
    EXPECT_TRUE(trie->startWith(string("sun")));

    delete trie;
    trie = NULL;
}

TEST(TrieIntsTest, Positive02){
    Trie *trie = new Trie();
    trie->insert(string("a"));

    EXPECT_TRUE(trie->search(string("a")));
    EXPECT_TRUE(trie->startWith(string("a"))); // test case from oj.leetcode.com, understand its meaning of startWith()

    delete trie;
    trie = NULL;
}

TEST(TrieIntsTest, Positive03){
    Trie *trie = new Trie();

    trie->insert(string("abc"));
    EXPECT_TRUE(trie->search(string("abc")));
    EXPECT_FALSE(trie->search(string("ab")));

    trie->insert(string("ab"));
    EXPECT_TRUE(trie->search(string("ab")));

    trie->insert(string("ab"));
    EXPECT_TRUE(trie->search(string("ab")));
}
