/**
 * given a 9*9 Sudoku board represented by a vector<string>, solve it by filling int numbers into all empty cells if it's valid;
 * if not valid, return false;
 * NOTE: 0 for empty cell, 1-9 for int number
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
    public:
    bool solve_sudoku(vector<string>& board) 
    {
        for (size_t row=0; row < 9; row++)
        {
            for (size_t col=0; col < 9; col++)
            {
                if (board[row][col] != '0') continue;
                // try to fill number in a cell
                for (auto ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, row, col, ch)) {
                        board[row][col] = ch;
                        if (solve_sudoku(board)) return true; // recurse
                        board[row].replace(col, 1, 1, '0'); // equivalent with board[row][col] = ch
                    }
                }
                return false; // no valid number found
            }
        }
        return true; // completely solved
    }

    private:
    /*
    * check the row, column, the 3*3 box where the cell locates in
    */
    bool is_cell_valid(const vector<string>& board, const int& row, const int& col, const char& ch)
    {
        // check row
        for (auto i = 0; i < 9; i++) {
            if (board[row][i] == ch)    return false;
        }
        // check column
        for (auto j = 0; j < 9; j++) {
            if (board[j][col] == ch)    return false;
        }
        // check 3*3 box
        for (auto i = 3*(row/3); i < 3*(row/3) + 3; i++) {
            for (auto j = 3*(col/3); j < 3*(col/3) + 3; j++) {
                if (board[i][j] == ch)  return false;
            }
        }
        return true;
    }

    // optimized
    bool isValid(const vector<string>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num)   return false; // Check row
            if (board[i][col] == num)   return false; // Check column
            int boxRow = 3 * (row / 3) + i / 3; // update once by i updated by 3
            int boxCol = 3 * (col / 3) + i % 3; // update once by i once in cycle of 3
            if (board[boxRow][boxCol] == num)   return false; // Check 3x3 box
        }
        return true;
    }
};