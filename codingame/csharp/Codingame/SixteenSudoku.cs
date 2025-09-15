using System.Collections.Generic;
using System.Text;

namespace Codingame;

public class SixteenSudoku
{
    public bool SolveSudoku(string[] board)
    {
        for (var r = 0; r < board.Length; r++)
        {
            for (var c = 0; c < board[0].Length; c++)
            {
                if (board[r][c] == '.')
                {
                    var pair = new int[] { r, c };
                    empties.Add(pair);
                }
                else
                {
                    setUsed(r, c, board[r][c]);
                }
            }
        }
        return backtrack(board, 0);
    }

    private ushort[] rowUsed = new ushort[16];
    private ushort[] colUsed = new ushort[16];
    private ushort[] blockUsed = new ushort[16];
    private List<int[]> empties = new List<int[]>();

    private int idx(char ch) { return (int)(ch - 'A'); }
    private int block(int r, int c) { return (r / 4) * 4 + c / 4; }

    private void setUsed(int r, int c, char ch)
    {
        var ch_idx = (ushort)(1 << idx(ch)); // among 16 bits, singel 1
        rowUsed[r] |= ch_idx;
        colUsed[c] |= ch_idx;
        blockUsed[block(r, c)] |= ch_idx;
    }

    private void unsetUsed(int r, int c, char ch)
    {
        var ch_idx = 1 << idx(ch);
        var reversed_idx = (ushort)~ch_idx; // among 16 bits, single 0
        rowUsed[r] &= reversed_idx;
        colUsed[c] &= reversed_idx;
        blockUsed[block(r, c)] &= reversed_idx;
    }

    // calculate all one bit in this 16 bits of ushort type
    private int allOneBit(ushort num)
    {
        int res = 0;
        for (var i = 0; i < 16; i++)
        {
            if ((ushort)(0x0001 & num) == 1) res += 1;
            num >>= 1;
        }
        return res;
    }

    private bool backtrack(string[] board, int pos)
    {
        int min_choices = 17, min_pos = -1;
        for (var i = pos; i < empties.Count; i++)
        {
            var pair = empties[i];
            int row = pair[0], col = pair[1];
            ushort usedBits = (ushort)(rowUsed[row] | colUsed[col] | blockUsed[block(row, col)]);
            int choices = 16 - allOneBit(usedBits);
            if (choices == 0) return false; // prune path
            if (min_choices > choices)
            {
                min_choices = choices;
                min_pos = i;
            }
            if (min_choices == 1) break; // cannot get better
        }
        if (min_pos == -1) return true; // board is full, solved

        swapPosInEmpties<int[]>(empties, pos, min_pos); // proceed from pos
        int r = empties[pos][0], c = empties[pos][1];
        var used_bits = (ushort)(rowUsed[r] | colUsed[c] | blockUsed[block(r, c)]);
        for (var i = 0; i < board.Length; i++)
        {
            if (((1 << i) & used_bits) == 0) // not occupied yet
            { 
                var ch = (char)('A' + i);
                setCellOnBoard(board, r, c, ch);
                setUsed(r, c, ch);
                if (backtrack(board, pos + 1)) return true;
                unsetUsed(r, c, ch);
                setCellOnBoard(board, r, c, '.');
            }
        }
        swapPosInEmpties<int[]>(empties, pos, min_pos); // restore order
        return false;
    }

    private void setCellOnBoard(string[] board, int row, int col, char ch)
    {
        var line = board[row];
        var builder = new StringBuilder(line.Substring(0, col));
        builder.Append(ch);
        builder.Append(line.Substring(col + 1, line.Length - col - 1));
        // replace one item of IList in specified index
        board[row] = builder.ToString();
    }

    private void swapPosInEmpties<T>(List<T> list, int pos1, int pos2)
    {
        T val1 = list[pos1];
        T val2 = list[pos2];
        list[pos1] = val2;
        list[pos2] = val1;
    }
}