import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;


public class SixteenSudoku {

    // short int to represent 16 bits 
    private short[] rowUsed = new short[16];
    private short[] colUsed = new short[16];
    private short[] blockUsed = new short[16];
    private List<int[]> empties = new ArrayList<int[]>();

    public boolean solveSudoku(String[] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[i].charAt(j) == '.') {
                    int[] pair = {i, j};
                    empties.add(pair);
                } else {
                    setUsed(rowUsed, colUsed, blockUsed, i, j, board[i].charAt(j));
                }
            }
        }
        return backtrack(board, 0);
    }

    private int idx(char ch) { return ch - 'A'; } // ch is in ranged from A to P
    private int block(int r, int c) { return (r / 4) * 4 + (c / 4); }
    // calculate all bits of 1 in the 16 bits short integer
    private int oneBits(short val) {
        int res = 0;
        for (int i = 0; i < 16; i++) {
            if ((0x0001 & val) == 1)  res += 1;
            val >>= 1;
        }
        return res;
    }

    private void setUsed(short[] rowUsed, short[] colUsed, short[] blockUsed, int r, int c, char ch) {
        short pos = (short)(1 << idx(ch));
        rowUsed[r] |= pos;
        colUsed[c] |= pos;
        blockUsed[block(r, c)] |= pos;
    }

    private void unsetUsed(short[] rowUsed, short[] colUsed, short[] blockUsed, int r, int c, char ch) {
        // to avoid error of imcompatible types of lossy conversion from int to short
        short pos = (short)(~(1 << idx(ch)));
        rowUsed[r] &= pos;
        colUsed[c] &= pos;
        blockUsed[block(r, c)] &= pos;
    }

    private boolean backtrack(String[] board, int pos)
    {
        // scan all pos in empties, find the one with least choices
        int min_choices = 17, min_pos = -1;
        for (int i = pos; i < empties.size(); i++) {
            int[] posPair = empties.get(i);
            if (posPair.length < 2) continue;
            int r = posPair[0], c = posPair[1];
            // bit of 1 means a char from 'A' to 'P' has been occupied there
            short optBits = (short)(rowUsed[r] | colUsed[c] | blockUsed[block(r, c)]); // collect all the unavailable(occupied) chars
            int choices = 16 - oneBits(optBits); // rest optional char from 'A' to 'P'
            if (choices == 0)   return false; // no choices, prune this path
            if (choices < min_choices) {
                min_choices = choices;
                min_pos = i;
                if (choices == 1)   break; // cannot get better than choices = 1
            }
        }
        if (min_pos == -1)  return true; // empties is empty, board is full 

        // start to backtrack from min_pos
        swapItemsOfList(empties, pos, min_pos); // in order to keep the iteration order in empties
        int[] posPair = empties.get(pos);
        if (posPair.length < 2) return false;
        int r = posPair[0], c = posPair[1];
        short optBits = (short)(rowUsed[r] | colUsed[c] | blockUsed[block(r, c)]);
        for (int i = 0; i < 16; i++) {
            if (((1 << i) & optBits) > 0) continue;
            char ch = (char)('A' + i);
            board[r] = setCharInStr(board[r], c, ch);
            setUsed(rowUsed, colUsed, blockUsed, r, c, ch);
            if (backtrack(board, pos+1))  return true; // proceed by DFS
            unsetUsed(rowUsed, colUsed, blockUsed, r, c, ch);
            board[r] = setCharInStr(board[r], c, '.');
        }
        return false;
    }

    // swap two items in a List
    private void swapItemsOfList(List<int[]> list, int pos1, int pos2) {
        int[] item1 = list.get(pos1);
        int[] item2 = list.get(pos2);
        list.set(pos1, item2);
        list.set(pos2, item1);
    }

    // replace one char in a string with another char
    private String setCharInStr(String str, int pos, char ch) {
        StringBuilder builder = new StringBuilder(str.substring(0, pos));
        builder.append(ch);
        builder.append(str.substring(pos+1, str.length()));
        return builder.toString();
    }
}