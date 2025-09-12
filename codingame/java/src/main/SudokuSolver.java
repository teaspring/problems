import java.util.ArrayList;
import java.util.List;

public class SudokuSolver{
    public boolean solveSudoku(List<String> board) {
        for (int r = 0 ; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board.get(r).charAt(c) != '0')  continue;
                // try to set cell at [r, c]
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, r, c, ch)) {
                        setCharInStr(board, r, c, ch);
                        if (solveSudoku(board)) return true; // if everything going well, it is supposed to return here
                        setCharInStr(board, r, c, '0');
                    }
                }
                return false; // no number can be filled in this cell, fail now
            }
        }
        return true; // completely solved
    }

    // replace the cell of [row, col] with given char on board
    private void setCharInStr(List<String> board, int row, int col, char ch) {
        // NOTE: remove() will throw NotsupportedOperationException cuz it might be ArrayList(but LinkedList support remove) 
        String line = board.get(row);
        StringBuilder builder = new StringBuilder(line.substring(0, col));
        builder.append(ch);
        builder.append(line.substring(col+1, line.length()));
        // replace the item in List
        board.set(row, builder.toString());
    }

    private boolean isValid(List<String> board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board.get(row).charAt(i) == ch) return false;
            if (board.get(i).charAt(col) == ch) return false;
            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;
            if (board.get(r).charAt(c) == ch)   return false;
        }
        return true;
    }
}