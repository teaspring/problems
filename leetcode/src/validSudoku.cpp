/*
 * determine if a Sudoku is valid. null cell is char '.'
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>    //double abs()

using namespace std;

void displayVector(const vector<char>& vec){
    int n = vec.size();
    for(int i=0;i<n;i++){
        printf("%c ", vec[i]);
    }
    printf("\n");
}

bool check(const vector<char>& vec){
    set<int> st;
    char cstr[2];
    cstr[1] = '\0';
    for(size_t i=0; i<vec.size();i++){
        if(vec[i] == '.')    continue;
        cstr[0] = vec[i];
        int d = atoi(cstr);
        if(d>9 || d<0 || st.find(d) != st.end()){
            //displayVector(vec);
            return false;
        }
        st.insert(d);
    }
    return true;
}

bool isValidSudoku(const vector<vector<char> > &board){
    int n = board.size();
    if(n != 9)    return false;
    vector<char> block;
    for(int i=0;i<n;++i){    //row
        block.clear();
        for(int j=0;j<n;++j){
            block.push_back(board[i][j]);
        }
        if(!check(block))    return false;
    }
    
    for(int j=0;j<n;++j){    //column
        block.clear();
        for(int i=0;i<n;++i){
            block.push_back(board[i][j]);
        }
        if(!check(block))    return false;
    }

    for(int i=0,j=0;i<=6;j+=3){
        if(j>6){
            j=0;
            i+=3;
        }
        if(i>6)    break;
        block.clear();
        for(int t=i, k=j;t <= 2+i; ++k){
            if(k > 2+j){
                k=j;
                ++t;
            }
            if(t > 2+i)    break;
            //printf("d=%d, k=%d\n", t, k);
            block.push_back(board[t][k]);
        }
        if(!check(block))    return false;
    }
    /*
    for(int s=0;s<=12;s+=3){    //3*3 square
        for(int i=0, j=s-i; j>=0; i+=3, j-=3){
            if(max(i,j) > 6)    continue;
            block.clear();
            for(int d=0; d<=4; ++d){
                for(int t=i, k=j+d-(t-i); k>=j; t++, k--){  //init: t-i=0, k-j=d-(t-i); determine: k-j >=0
                    if(max(t-i, k-j) > 2)    continue;
                    block.push_back(board[t][k]);
                }
            }
            if(!check(block))    return false;
        }
    }
    */
    return true;
}

void test_01(){
    vector<vector<char> > board;
    char row0[] = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    vector<char> vec0(row0, row0 + 9);
    board.push_back(vec0);

    char row1[] = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    vector<char> vec1(row1, row1 + 9);
    board.push_back(vec1);

    char row2[] = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    vector<char> vec2(row2, row2 + 9);
    board.push_back(vec2);

    char row3[] = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    vector<char> vec3(row3, row3 + 9);
    board.push_back(vec3);
    
    char row4[] = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    vector<char> vec4(row4, row4 + 9);
    board.push_back(vec4);

    char row5[] = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    vector<char> vec5(row5, row5 + 9);
    board.push_back(vec5);

    char row6[] = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    vector<char> vec6(row6, row6 + 9);
    board.push_back(vec6);

    char row7[] = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    vector<char> vec7(row7, row7 + 9);
    board.push_back(vec7);

    char row8[] = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    vector<char> vec8(row8, row8 + 9);
    board.push_back(vec8);

    printf("%s\n", isValidSudoku(board) ? "true" : "false");
}

void test_02(){
    vector<vector<char> > board;
    char row0[] = {'.', '.', '.', '.', '.', '.', '5', '.', '.'};
    vector<char> vec0(row0, row0 + 9);
    board.push_back(vec0);

    char row1[] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> vec1(row1, row1 + 9);
    board.push_back(vec1);

    char row2[] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> vec2(row2, row2 + 9);
    board.push_back(vec2);

    char row3[] = {'9', '3', '.', '.', '2', '.', '4', '.', '.'};
    vector<char> vec3(row3, row3 + 9);
    board.push_back(vec3);
    
    char row4[] = {'.', '.', '7', '.', '.', '.', '3', '.', '.'};
    vector<char> vec4(row4, row4 + 9);
    board.push_back(vec4);

    char row5[] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> vec5(row5, row5 + 9);
    board.push_back(vec5);

    char row6[] = {'.', '.', '.', '3', '4', '.', '.', '.', '.'};
    vector<char> vec6(row6, row6 + 9);
    board.push_back(vec6);

    char row7[] = {'.', '.', '.', '.', '.', '3', '.', '.', '.'};
    vector<char> vec7(row7, row7 + 9);
    board.push_back(vec7);

    char row8[] = {'.', '.', '.', '.', '.', '5', '2', '.', '.'};
    vector<char> vec8(row8, row8 + 9);
    board.push_back(vec8);

    printf("%s\n", isValidSudoku(board) ? "true" : "false");
}

int main(int, char**){
    test_01();
    test_02();
    return 0;
}
