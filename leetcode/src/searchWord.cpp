/*
 * given a matrix composed of char, search another word whether exist in the matrix
 *
 * [ABCD,
 * DEFC]
 * ABE,  true
 * DF: flase
 * */
#include "../include/preliminary.h"

bool searchOneChar(vector<int> pos[], string s, int currpos, int *used, int rows, int cols){
    if(s.empty())    return true;
    char ch = s[0];
    int l = s.size();
    int r = currpos / cols, c = currpos % cols;
    vector<int> options = pos[(int)ch];
    for(int i=0; i<(int)options.size(); i++){
        int nr = options[i] / cols;
        int nc = options[i] % cols;
        if(abs(nr - r) + abs(nc - c) != 1 || used[options[i]] == 1)  // check if not successive, if used already
            continue;
        used[options[i]] = 1;
        if(searchOneChar(pos, s.substr(1, l-1), options[i], used, rows, cols))
            return true;
        used[options[i]] = 0;
    }
    return false;
}

bool exist(vector<vector<char> >& board, string word){
    if(word.empty())    return true;
    if(board.size() == 0 || board[0].size() == 0)    return false;
    int m = board.size(), n = board[0].size(), l= word.size();
    if(l > m*n)    return false;   // length exceed

    vector<int> pos[256];
    for(int i=0; i < 256; i++){    // to support char search in O(1)
        pos[i] = vector<int>();
    }
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            pos[(int)board[i][j]].push_back(i * n + j);
        }
    }

    int used[m*n];
    memset(used, 0, sizeof(used));
    vector<int> options = pos[(int)word[0]];
    for(int i=0; i<(int)options.size();i++){
        used[options[i]] = 1;
        if(searchOneChar(pos, word.substr(1, l-1), options[i], used, m, n))
            return true;
        used[options[i]] = 0;
    }
    return false;
}

void test(){
    vector<vector<char> > board;
    char row0[] = {'A', 'B', 'C', 'D'};
    board.push_back(vector<char>(row0, row0 + sizeof(row0)/sizeof(char)));
    char row1[] = {'E', 'F', 'G', 'H'};
    board.push_back(vector<char>(row1, row1 + sizeof(row1)/sizeof(char)));
    char row2[] = {'D', 'E', 'B', 'A'};
    board.push_back(vector<char>(row2, row2 + sizeof(row2)/sizeof(char)));
    string word1("BCE");
    printf("%s, %s\n", word1.c_str(), exist(board, word1) ? "true" : "false");
    string word2("ABC");
    printf("%s, %s\n", word2.c_str(), exist(board, word2) ? "true" : "false");
}

int main(){
    test();
    return 0;
}

