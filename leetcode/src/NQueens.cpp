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
 * columnForRow[i] means column x possessed for queen stands on row i.
 * 1. conflict in column: ColumnsForRow[i] = ColumnForRow[j]
 * 2. conflict in diagonal: ColumnForRow[i] - ColumnForRow[j] == i-j || ColumnForRow[i] - ColumnForRow[j] == j-i
 * */

class NQueens{

public:
    NQueens(int n): N(n), total(0){
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
    * return total options count
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
    * if queen put in (r, columnForRow[r]), whether will conflict with all the placed queens in rows [0, r)
    * */
    bool check(int r){
        for(int i = 0; i < r; i++){ // avoid check of same row
            int tmp = columnForRow[i] - columnForRow[r];
            if(tmp == 0     // same column
            ||tmp == (i-r)  // '/' diagnol
            ||tmp == (r-i)){ // '\' diagnol, same to r1 + c1 = r2 + c2
                return false;
            }
        }
        return true;
    }

    /*
    * try to put queen on row r, r is 0-based
    * */
    void placeQueen(int r, vector<vector<string> >& res){
        if(r == N){
            printBoard(res);
            return;
        }

        for(int i = 0; i < N; i++){
            columnForRow[r] = i; // try any column of this row to put queen
            if(check(r)){
                placeQueen(r + 1, res);
            }
        }
    }

    int N; // dimension size of board

    int total; // total valid options

    // columnForRow[i] = x means column x possessed for queen stands on row i.
    int *columnForRow;
};

/* unit test is in ../cpp_unittest/NQueens_unittest */
