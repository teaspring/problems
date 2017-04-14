/*
 * Problem I:
 * given a matrix composed of char, search a word whether exists in it.
 * Note:
 * 1. the word can be constructed from adjacent letter cells, which means horizontally and vertically(up/down/left/right)
 * 2. one letter cannot be used more than once
 *
 * [ABCD,
 *  DEFC]
 * ABE: true
 * DBCF: false
 *---------------------------------------------------------------------------------------
 * Problem II:
 * given a 2D board and a list of words from the dictionary, find all words in the board.
 * Each word must be constructed from the letters of sequentially adjacent cell, where 'adjacent' cells means horizontally or vertically(right/left/up/down)
 * one letter cell cannot be used more than once in a word. all inputs are lowercase letters a-z
 *
 * ['o','a','a','n';
 *  'e','t','a','e';
 *  'i','h','k','r';
 *  'i','f','l','v'], words = ["oath", "pea", "eat", "rain"]
 * return: ["eat","oath"]
 * */
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// for exist():bool, and raw versioned findWords():vector<string>
class Solution1{
public:
    // idea from findWords()
    bool exist(vector<vector<char> >& board, const string& word) {
        if(board.empty())    return false;
        const int Rows = board.size();
        const int Cols = board[0].size();

        for(int i = 0; i < Rows; ++i) {
            for(int j = 0; j < Cols; ++j) {
                if(checkNextChar(board, i, j, word, 0))    return true;
            }
        }
        return false;
    }

    // several points to pay attention:
    // 0. words[] may has duplicate word
    // 1. if one word is found already, how to stop searching remaining area?
    // 2. how to separate the covered area and not yet area?
    // 3. how to avoid useless search of one word if its prefix is confirmed not existing?
    // Unfortunately, this solution meets Time Limit Error for some extreme cases, like below:
    // ['a','e','a','d';
    //  'a','b','c','a';
    //  'd','a','c','d'], with words ["aaaaaaaaa","aaaaaaaab","aaaaaaaaac"...]
    // insight: it needs to have some preprocess about the @arg words, Trie as the best data structure to do it
    // lesson learned: tags matrix covered[][] is wrong which will miss the earlier reviewed cells
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        if(board.empty())    return vector<string>();
        const int Rows = board.size();
        const int Cols = board[0].size();
        set<string> result; // use set<> to avoid duplicated search

        for(string word : words) { // this level loop leads to drawback of this solution, it will be extermely redundant for large words[]
            for(int i = 0; i < Rows; ++i) {
                for(int j = 0; j < Cols; ++j) {
                    findNextChar(board, i, j, word, 0, result);
                }
            }
        }
        return vector<string>(result.begin(), result.end()); // NOTE vector<>(set<>) is illegal
    }

private:
    // spawned from findNextChar()
    bool checkNextChar(vector<vector<char> >& grid, int i, int j, const string& word, int idx) {
        if(i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size())    return false;
        if(grid[i][j] == '*' || grid[i][j] != word[idx])    return false; // idx increases by 1 once from 0, so it must be less than len

        if(idx == (int)word.size() - 1)    return true;

        int charIdx = grid[i][j] - 'A';
        grid[i][j] = '*'; // drown the cell
        bool result = checkNextChar(grid, i-1, j, word, idx+1) ||
                      checkNextChar(grid, i, j-1, word, idx+1) ||
                      checkNextChar(grid, i+1, j, word, idx+1) ||
                      checkNextChar(grid, i, j+1, word, idx+1);
        grid[i][j] = 'A' + charIdx; // recover the cell
        return result;
    }

    // check adjacent cells recursively
    void findNextChar(vector<vector<char> >& grid, int i, int j, const string& word, int idx, set<string>& result) {
        if(result.find(word) != result.end())    return; // word has been in <result> already
        if(i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size())    return;
        if(grid[i][j] == '*' || grid[i][j] != word[idx])    return; // idx increases by 1 once from 0, so it must be less than len

        if(idx == (int)word.size() - 1) {
            result.insert(word);
            return;
        }

        int charIdx = grid[i][j] - 'a';
        grid[i][j] = '*'; // drown the cell
        findNextChar(grid, i-1, j, word, idx+1, result);
        findNextChar(grid, i, j-1, word, idx+1, result);
        findNextChar(grid, i+1, j, word, idx+1, result);
        findNextChar(grid, i, j+1, word, idx+1, result);
        grid[i][j] = 'a' + charIdx; // recover the cell
    }
};

// for findWords() based on prefix tree(Trie) and DFS
class Solution2{
private:
    class Trie{
    public:
        Trie* children[26];
        bool isLeaf;
        int wordIdx;
        int prefixCount; // trick

        Trie() : isLeaf(false), wordIdx(0), prefixCount(0) {
            memset(children, 0, sizeof(children));
        }

        ~Trie() {
            for (int i = 0; i < 26; ++i) {
                if(children[i])    delete children[i];
            }
        }
    };

private:
    void insertWord(Trie* root, const vector<string>& words, int idx) {
        Trie *node = root;
        root->prefixCount++; // after all words are inserted, root0->prefixCount is count of words
        for(int i = 0; i < (int)words[idx].size(); ++i) {
            int childID = words[idx][i] - 'a';
            if(!node->children[childID]) {
                node->children[childID] = new Trie();
            }
            node = node->children[childID];
            node->prefixCount++; // after all words are inserted, prefixCount of one node tells how many words has prefix of this node
        }
        node->isLeaf = true;
        node->wordIdx = idx;
    }

    Trie* buildTrie(const vector<string>& words) {
        Trie *root = new Trie();
        const int n = words.size();
        for(int i = 0; i < n; ++i) {
            insertWord(root, words, i);
        }
        return root;
    }

    // @arg words is used to pick up the string to save in result<> with idx
    int dfsTrie(vector<string>& res, Trie *root, vector<vector<char> >& board, int row, int col, vector<string>& words) {
        int detected = 0;
        if(root->isLeaf) {
            ++detected;
            root->isLeaf = false; // reset to avoid this if-block is executed for 1+ times for that very node
            res.push_back(words[root->wordIdx]);
        }

        if(row < 0 || row >= (int)board.size() || col < 0 || col >= (int)board[0].size() || board[row][col] == '*')
            return detected;
        int charIdx = board[row][col] - 'a';
        if(!(root->children[charIdx]) || root->children[charIdx]->prefixCount <= 0)    return detected;

        board[row][col] = '*'; // drown the island :)
        detected += dfsTrie(res, root->children[charIdx], board, row-1, col, words) +
                    dfsTrie(res, root->children[charIdx], board, row, col-1, words) +
                    dfsTrie(res, root->children[charIdx], board, row+1, col, words) +
                    dfsTrie(res, root->children[charIdx], board, row, col+1, words);
        root->prefixCount -= detected; // smart counter !!!

        board[row][col] = 'a' + charIdx; // recover the char
        return detected;
    }

public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        int M = 0, N = 0, num = 0;
        vector<string> res;
        if(!(M = board.size()) || !(N = board[0].size()) || !(num = words.size()))    return res;

        Trie *root = buildTrie(words);
        for(int i = 0; i < M && root->prefixCount; ++i) {
            for(int j = 0; j < N; ++j) {
                dfsTrie(res, root, board, i, j, words);
            }
        }
        delete root;
        return res;
    }
};

