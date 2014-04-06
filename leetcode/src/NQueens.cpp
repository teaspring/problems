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
* ColumnForRow[i] means column x possessed for queen stands on row i.
1. conflict in column: ColumnsForRow[i] = ColumnForRow[j]
2. conflict in diagonal: ColumnForRow[i] - ColumnForRow[j] == i-j || ColumnForRow[i] - ColumnForRow[j] == j-i
*/

class NQueens{
    public:
        NQueens(int n): N(n), total(0){
            columnForRow = new int[N]();
        }
        virtual ~NQueens(){
            delete[] columnForRow;
        }
        vector<vector<string> > solve();
        int totalNQueens();
            
    private:
        void printBoard(vector<vector<string> >& res);
        bool check(int r);
        void placeQueen(int r, vector<vector<string> >& res);
        
        int N;
        int total;
        int *columnForRow;
};

void NQueens::printBoard(vector<vector<string> >& res){
    vector<string> board;
    for(int i=0; i<N; i++){    // row i
        char *row = new char[N+1];
        for(int j=0;j<N;j++){  //column j
            row[j] = j==columnForRow[i] ? 'Q' : '.';
        }
        row[N] = '\0';
        board.push_back(string(row));
        delete[] row;
    }
    res.push_back(board);
    ++total;
    return;
}

bool NQueens::check(int r){
    for(int i=0; i<r; i++){ //avoid check of same row
        int tmp = columnForRow[i] - columnForRow[r];
        if(tmp==0           //same column
        ||tmp == (i-r)      // '/' diagnol                
        ||tmp == (r-i)){    // '\' diagnol, same to r1+c1 = r2+c2
            return false;
        }
    }
    return true;
}

void NQueens::placeQueen(int r, vector<vector<string> >& res){
    if(r == N){
        printBoard(res);
        return;
    }
    for(int i=0; i<N; i++){
        columnForRow[r] = i; //try to place queen at row (r) to any column
        if(check(r)){
            placeQueen(r+1, res);
        }
    }
}

vector<vector<string> > NQueens::solve(){
    vector<vector<string> > res;
    placeQueen(0, res);
    return res;
}

int NQueens::totalNQueens(){
    total=0;
    solve();
    return total;
}

void display(const vector<vector<string> > &combinations){
    int n = combinations.size();
    for(int i=0;i<n;++i){
        int m = combinations[i].size();
        for(int j=0;j<m;j++){
            printf("%s\n", combinations[i][j].c_str());
        }
        printf("---------------------------------\n");
    }
    printf("total combinations: %d\n", n);
}

int main(int, char**){
    string str;
    while(1){
        printf("pleast input N:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int n = atoi(str.c_str());
        NQueens *pnq = new NQueens(n);
        //vector<vector<string> > res = pnq->solve();
        //display(res);
        printf("total solutions: %d\n", pnq->totalNQueens());
        delete pnq;
    }
    return 0;
}
