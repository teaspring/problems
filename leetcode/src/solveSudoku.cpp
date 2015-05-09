/*
 * solve a sudoku of 9*9 board. null cell is marked as '.'
 * */
#include <string>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     * verify each alternative int 0-9 on every cell position recursely
     * */
    void solveSudoku(vector<vector<char> >& board){
        dfs(board, 0);
    }

private:
    bool dfs(vector<vector<char> >& board, int pos){
        const int n = board.size();

        if(pos == n*n)    return true;

        int x = pos / n, y = pos % n; // x is n-1 in maximum, y is n-1 in maximum

        if(board[x][y] == '.'){
            for(char ch = '1'; ch <= '9'; ch++){
                board[x][y] = ch;
                if(validate(board, pos) && dfs(board, pos + 1))    return true;
            }

            board[x][y] = '.';
        }else{
            if(dfs(board, pos + 1))    return true;
        }

        return false;
    }

    /*
     * validate row, column, and the 3*3 cubic that this point resides
     * */
    bool validate(vector<vector<char> >& board, int pos){
        const int n = board.size();

        int x = pos / n, y = pos % n; // [x][y] is real position on board, both x and y are n-1 in maximum

        char ch = board[x][y];

        for(int i = 0; i < n; i++){
            if(i != x && board[i][y] == ch)    return false;  // the column that [x][y] resides
            if(i != y && board[x][i] == ch)    return false;  // the row that [x][y] resides
        }

        int cx = x / 3 * 3;  // [cx][cy] is the left up corner of the 3*3 cubic
        int cy = y / 3 * 3;

        for(int i = cx; i < cx + 3; i++){
            for(int j = cy; j < cy + 3; j++){
                if(i != x && j != y && board[i][j] == ch)    return false;
            }
        }

        return true;
    }
};
