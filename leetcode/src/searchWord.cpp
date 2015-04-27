/*
 * given a matrix composed of char, search a word whether exists in it.
 * Note:
 * 1. there can be duplicate char in board
 * 2. the word flow can go right/up/down
 *
 * [ABCD,
 * DEFC]
 * ABE,  true
 * DF: flase
 * */
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution{

public:
    /*
     *
     * */
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

        int used[m*n];
        memset(used, 0, sizeof(used));

        vector<int> options = pos[(int)word[0]];
        const int t = options.size();
        for(int i = 0; i < t; i++){
            used[options[i]] = 1;
            if(searchOneChar(pos, word, 1, options[i], used, m, n))
                return true;
            used[options[i]] = 0;
        }
        return false;
    }

private:
    /*
     * check next optional char whether is next to current char
     * */
    bool searchOneChar(vector<int> pos[], const string& word, int charIdx,
                int currpos, int *used, int rows, int cols){
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
};

/* unit test is in ../cpp_unittest/searchWord_unittest */
