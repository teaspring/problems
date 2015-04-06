/*
 * problem 1. place n queens on an n*n chessboard such that no two queens attack each other
 * */

import java.io.*;
import java.util.*;

public class NQueens{
    public NQueens(int n){
        N = n;
    }

    // dimension size of board
    private int N;

    // elegent data structure to save queen placement position
    private int[] columnForRow;

    // valid N queens placement options in total
    private int total;

    public int totalOptions(){
        total = 0;
        solve();
        return total;
    }

    public ArrayList<String[]> solve(){
        columnForRow = new int[N];
        ArrayList<String[]> res = new ArrayList<String[]>();
        placeQueen(0, res);
        return res;
    }

    private void placeQueen(int r, ArrayList<String[]> res){
        if(r == N){
            printBoard(res);
            return;
        }

        for(int i = 0; i < N; i++){
            columnForRow[r] = i;
            if(check(r))    placeQueen(r+1, res);
        }
    }

    /*
     * if Queen is put in columnForRow[r], check if it conflict with rows [0, r) with Queens
     * */
    private boolean check(int r){
        for(int i = 0; i < r; i++){
            int tmp = columnForRow[i] - columnForRow[r];
            if(tmp == 0        //same column
              || tmp == (i-r)  // '/' diagnol
              || tmp == (r-i)){ // '\' diagnol
                return false;
            }
        }
        return true;
    }

    private void printBoard(ArrayList<String[]> res){
        String[] board = new String[N];
        for(int i = 0; i < N; i++){
            StringBuilder builder = new StringBuilder();
            for(int j = 0; j < N; j++){
                builder.append(j==columnForRow[i] ? 'Q' : '.');
            }
            board[i] = builder.toString();
        }
        res.add(board);
        ++total;
    }
}

/* unit test is in ../java_unittest/NQueens_junit */
