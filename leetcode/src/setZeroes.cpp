/*
 * set matrix zeroes. given a m*n matrix, if an element is 0, set its entire row and column to 0. do it in place
 * */
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

class Solution{

public:
    /*
     * record [row, col] of each element 0, then reset the related rows and columns
     * this solution source code looks more readable and easier to maintain
     * */
    void setZeroes(vector<vector<int> >& grid){
        if(grid.empty())    return;

        const int m = grid.size();
        const int n = grid[0].size();
        set<int> brushRows;
        set<int> brushColumns;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    brushRows.insert(i);
                    brushColumns.insert(j);
                }
            }
        }

        for(set<int>::iterator it = brushRows.begin(); it != brushRows.end(); it++){
            resetRow(grid, *it);
        }

        for(set<int>::iterator it = brushColumns.begin(); it != brushColumns.end(); it++){
            resetColumn(grid, *it);
        }
    }

private:
    void resetRow(vector<vector<int> >& grid, int r){
        const int m = grid[0].size();
        for(int j = 0; j < m; j++){
            grid[r][j] = 0;
        }
    }

    void resetColumn(vector<vector<int> >& grid, int c){
        const int n = grid.size();
        for(int i = 0; i < n; i++){
            grid[i][c] = 0;
        }
    }
};
