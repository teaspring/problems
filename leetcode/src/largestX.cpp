/*
 * given a matrix of 0/1, find the largest X made up of 1
 * */

#include "stdio.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution{

public:
    /*
     *
     * */
    int solve(const vector<vector<char> >& board){
        const int m = board.size();
        const int n = board[0].size();
        if(m < 3 || n < 3)    return 0;

        int d = 1;
        int cx = d, cy = d; // cx is horizontal size, cy is vertical size

        while(cx + d < m && cy + d < n){
            if(check(board, cx, cy, d)){
                ++d;
                cx = d;
                cy = d;
            }else{
                ++cy;
                if(cy + d == m){
                    ++cx;
                    cy = d;
                }
            }
        }

        return d-1;
    }

private:
    bool check(const vector<vector<char> >& board, int cx, int cy, int d){
        if(board[cx][cy] != '1')    return false;

        for(int k = d; k >= 1; k--){
            if(board[cx-k][cy-k] != '1'     // NW
            || board[cx-k][cy+k] != '1'     // NE
            || board[cx+k][cy-k] != '1'     // SW
            || board[cx+k][cy+k] != '1'){   // SE
                return false;
            }
        }

        return true;
    }
};

/* unit test is in ../cpp_unittest/largestX_unittest */
