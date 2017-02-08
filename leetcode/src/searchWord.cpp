/*
 * Problem I:
 * given a matrix composed of char, search a word whether exists in it.
 * Note:
 * 1. there can be duplicate char in board
 * 2. the word flow can go right/up/down
 *
 * [ABCD,
 *  DEFC]
 * ABE:  true
 * DF: false
 *---------------------------------------------------------------------------------------
 * Problem II:
 * given a 2D board and a list of words from the dictionary, find all words in the board
 * Each word must be constructed from the letters of sequentially adjacent cell, where 'adjacent' cells means horizontally or vertically
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
    bool exist(const vector<vector<char> >& board, const string& word){
        if(word.empty())    return true;
        if(board.empty() || board[0].empty())    return false;

        const int m = board.size();
        const int n = board[0].size();
        const int l = word.size();
        if(l > m*n)    return false;   // out of range

        vector<int> pos[256];
        for(int i = 0; i < 256; i++){ // support char search in O(1)
            pos[i] = vector<int>();
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pos[(int)board[i][j]].push_back(i * n + j); // save occurance positions of char on board
            }
        }

        vector<int> used(m*n, 0);
        vector<int> options = pos[(int)word[0]];
        const int t = options.size();

        for(int i = 0; i < t; i++){
            used[options[i]] = 1;
            if(searchOneChar(pos, word, 1, options[i], used, m, n))    return true;
            used[options[i]] = 0;
        }
        return false;
    }

    // several points to pay attention:
    // 1. if one word is found already, how to stop searching remaining area?
    // 2. how to separate the covered area and not yet area?
    // 3. how to avoid useless search of one word if its prefix is confirmed not existing?
    // Unfortunately, this solution meets Time Limit Error for some extreme cases, like below:
    // ['a','e','a','d';
    //  'a','b','c','a';
    //  'd','a','c','d'], with words ["aaaaaaaaa","aaaaaaaab","aaaaaaaaac"...]
    //  insight: it needs to have some preprocess about the @arg words, Trie as the best data structure to do it
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        if(board.empty())    return vector<string>();
        const int Rows = board.size();
        const int Cols = board[0].size();
        set<string> result; // use set<> to avoid duplicated search

        for(string word : words) {
            vector<vector<bool> > covered(Rows, vector<bool>(Cols, false)); // tags to tell covered cells
            for(int i = 0; i < Rows; ++i) {
                for(int j = 0; j < Cols; ++j) {
                    findNextChar(board, i, j, covered, word, 0, result);
                }
            }
        }
        return vector<string>(result.begin(), result.end()); // NOTE vector<>(set<>) is illegal
    }

private:
    /*
     * check next optional char whether is next to current char
     * */
    bool searchOneChar(vector<int> pos[],
                       const string& word,
                       int charIdx,
                       int currpos,
                       vector<int>& used,  // int[m*n]
                       int rows,
                       int cols){
        if(charIdx == (int)word.size())    return true;

        char ch = word[charIdx];
        int r = currpos / cols, c = currpos % cols;

        vector<int> options = pos[(int)ch];
        const int n = options.size();

        for(int i = 0; i < n; i++){
            int nr = options[i] / cols;
            int nc = options[i] % cols;
            if(abs(nr - r) + abs(nc - c) != 1 || used[options[i]] == 1)  // check if not successive, if used already
                continue;

            used[options[i]] = 1;

            if(searchOneChar(pos, word, charIdx + 1, options[i], used, rows, cols))
                return true;

            used[options[i]] = 0;
        }
        return false;
    }

    // process adjacent cells recursively
    void findNextChar(vector<vector<char> >& grid, int i, int j, vector<vector<bool> >& covered,
                const string& word, int idx, set<string>& result) {

        if(result.find(word) != result.end())    return; // word has been in <result> already

        const int len = word.size();
        if(i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || covered[i][j] || idx >= len || grid[i][j] != word[idx])
            return;

        covered[i][j] = true;
        if(idx == len - 1) {
            result.insert(word);
            return;
        }

        findNextChar(grid, i-1, j, covered, word, idx+1, result);
        findNextChar(grid, i, j-1, covered, word, idx+1, result);
        findNextChar(grid, i+1, j, covered, word, idx+1, result);
        findNextChar(grid, i, j+1, covered, word, idx+1, result);
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
        root->prefixCount++; // ??
        for(int i = 0; i < (int)words[idx].size(); ++i) {
            int childID = words[idx][i] - 'a';
            if(!node->children[childID]) {
                node->children[childID] = new Trie();
            }
            node = node->children[childID];
            node->prefixCount++;
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
    int dfsTrie(vector<string>& res, Trie *root, vector<vector<char> >& board, vector<string>& words, int row, int col) {
        int detected = 0;
        if(root->isLeaf) {
            ++detected;
            root->isLeaf = false; // ??
            res.push_back(words[root->wordIdx]);
        }

        if(row < 0 || row >= (int)board.size() || col < 0 || col >= (int)board[0].size() || board[row][col] == '*')
            return detected;
        int charIdx = board[row][col] - 'a';
        if(!root->children[charIdx] || root->children[charIdx]->prefixCount <= 0)    return detected;

        board[row][col] = '*'; // drown the island :)
        detected += dfsTrie(res, root->children[charIdx], board, words, row-1, col) +
                    dfsTrie(res, root->children[charIdx], board, words, row, col-1) +
                    dfsTrie(res, root->children[charIdx], board, words, row+1, col) +
                    dfsTrie(res, root->children[charIdx], board, words, row, col+1);
        root->prefixCount -= detected; // ??

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
                dfsTrie(res, root, board, words, i, j);
            }
        }
        delete root;
        return res;
    }
};

