/*
 * solve a sudoku of 9*9 board. null cell is marked as '.'
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    void solveSudoku(vector<vector<char> >& board){
        dfs(board, 0);
    }

    bool dfs(vector<vector<char> >& board, int pos){
        int n = board.size();
        if(pos == n*n)    return true;
        int x = pos / n, y = pos % n;
        if(board[x][y] == '.'){
            for(char ch = '1'; ch <= '9'; ch++){
                board[x][y] = ch;
                if(validate(board, pos) && dfs(board, pos+1))    return true;
            }
            board[x][y] = '.';
        }else{
            if(dfs(board, pos+1))    return true;
        }
        return false;
    }

    bool validate(vector<vector<char> >& board, int pos){
        int n = board.size();
        int x = pos/n, y = pos%n;
        char ch = board[x][y];
        for(int i=0; i<n; i++){
            if(i != x && board[i][y] == ch)    return false;
            if(i != y && board[x][i] == ch)    return false;
        }
        int cx = x/3 * 3;   // 3 is the height and width of the 3*3 cubic of sudoku
        int cy = y/3 * 3;
        for(int i=cx; i<cx+3; i++){
            for(int j=cy; j<cy+3; j++){
                if(i != x && j != y && board[i][j] == ch)    return false;
            }
        }
        return true;
    }
};
