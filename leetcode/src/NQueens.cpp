/*
 * problem 1. put N queens on a N*N square board. output all the options
 *
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include "stdlib.h"

using namespace std;

/*
 * columnForRow[i] = x means one queen standing on position of [row, col] as [i, x]
 * 1. conflict in one column: ColumnsForRow[i] = ColumnForRow[j]
 * 2. conflict in one diagonal: 
 * 2.1 (i-j) == ColumnForRow[i] - ColumnForRow[j]
 * |\
 * | \
 * |  \
 * -----
 * 2.2 (i-j) == ColumnForRow[j] - ColumnForRow[i]
 *    /|
 *   / |
 *  /  |
 *  ----
 * */

/**
 * open question: how many times is check() called? and what about placeQueen()?
 * Answer:
 * 1.C(check) = N * C(placeQ);
 * 2.for once placeQueen(r), internal placeQueen(r+1) will be called around (N-r) times(here r is 1-based); then each placeQueen(r+1) will
 * lead to placeQueen(r+2) is called (N-r-1) times;
 * 3.so C(placeQ) = N*(N-1)*(N-2)..*2*1 = N!
 * */
class NQueens{
public:
    NQueens(int n): N(n), total(0){
        total = 0;
        columnForRow = new int[N]();
    }

    virtual ~NQueens(){
        delete[] columnForRow;
        columnForRow = NULL;
    }

    /*
    * return board which has placed N queens
    * */
    vector<vector<string> > solve(){
        vector<vector<string> > res;
        placeQueen(0, res);
        return res;
    }

    /*
    * rerun to get the total options count
    * */
    int totalNQueens(){
        total = 0;
        solve();
        return total;
    }

private:
    /*
    * in the return vector<vector<string> >
    * string is N chars, 'Q' for queen, '.' for space
    * vector<string> is N string, which compose a N*N board which places N queens
    * vector<vector<string> > are all of the optional boards
    * */
    void printBoard(vector<vector<string> >& res){
        vector<string> board;
        for(int i = 0; i < N; i++){    // row i
            char *row = new char[N+1];
            for(int j = 0; j < N; j++){  // column j
                row[j] = (j == columnForRow[i] ? 'Q' : '.');
            }
            row[N] = '\0';
            board.push_back(string(row));
            delete[] row;
        }
        res.push_back(board);
        ++total;
        return;
    }

    /*
    * if a new queen lands in (r, columnForRow[r]), does it conflict with the existing (r-1) queens?
    * */
    bool check(int r){
        for(int i = 0; i < r; i++){ // avoid check of same row
            int distance = columnForRow[i] - columnForRow[r];
            if(distance == 0     // in one column
            || distance == (i-r)  // '/' diagnol
            || distance == (r-i)){ // '\' diagnol
                return false;
            }
        }
        return true;
    }

    /*
    * recursive method to try to put queen on 0-based row r
    * */
    void placeQueen(int r, vector<vector<string> >& res){
        if(r == N){
            printBoard(res);
            return;
        }

        for(int i = 0; i < N; i++){
            columnForRow[r] = i; // try to put one new queen on row r, column i
            if(check(r)){
                placeQueen(r+1, res);
            }
        }
    }

    int N; // N * N board
    int total; // total valid options
    int *columnForRow;
};

/* unit test is in ../cpp_unittest/NQueens_unittest */
