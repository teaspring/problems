using System.Collections.Generic;
using System.Text;

namespace Codingame;

public class SudokuSolver
{
    public bool SolveSudoku(IList<string> board)
    {
        for (var row = 0; row < 9; row++)
        {
            for (var col = 0; col < 9; col++)
            {
                if (board[row][col] != '0') continue;
                for (var ch = '1'; ch <= '9'; ch++)
                {
                    if (IsValid(board, row, col, ch))
                    { 
                        SetCellOnBoard(board, row, col, ch);
                        if (SolveSudoku(board)) return true; // if going well, supposed to return true
                        SetCellOnBoard(board, row, col, '0');
                    }
                }
                return false; // cannot set valid number to this cell, fail now
            }
        }
        return true; // all resolved
    }

    // set a char in a cell on board
    private void SetCellOnBoard(IList<string> board, int row, int col, char ch)
    {
        var line = board[row];
        var builder = new StringBuilder(line.Substring(0, col));
        builder.Append(ch);
        builder.Append(line.Substring(col + 1, line.Length - col - 1));
        // replace one item of IList in specified index
        board[row] = builder.ToString();
    }

    private bool IsValid(IList<string> board, int row, int col, char ch)
    {
        for (var i = 0; i < 9; i++)
        {
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;
            var r = 3 * (row / 3) + i / 3;
            var c = 3 * (col / 3) + i % 3;
            if (board[r][c] == ch) return false;
        }
        return true;
    }
 }