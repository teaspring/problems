/*
 * set matrix zeroes. given a m*n matrix, if an element is 0, set its entire row and column to 0. do it in place
 * */
#include "stdio.h"
#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int> >& grid){
    int m = grid.size();
    if(m==0)    return;
    int n = grid[0].size();
    if(n==0)    return;
    bool row = false, col = false;
    
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j] == 0){
                 if(i==0)    row = true;
                 if(j==0)    col = true;
                 grid[i][0] = 0;   // projection to column 0
                 grid[0][j] = 0;   // projection to row 0
            }
        }
    }
    for(int i=1; i<m; ++i){
        for(int j=1; j<n; ++j){
            if(grid[i][0] == 0 || grid[0][j] == 0){
                grid[i][j] = 0;
            }
        }
    }
    if(row){    // set row 0 to all zeroes
        for(int j=0; j<n; ++j){
            grid[0][j] = 0;
        }
    }
    if(col){
        for(int i=0; i<m; ++i){
            grid[i][0] = 0;
        }
    }
    return;
}

int main(){
    return 0;
}

