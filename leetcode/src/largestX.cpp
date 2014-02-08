/*
 * given a matrix of 0/1, find the largest X made up of 1
 * */

#include "stdio.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(const vector<vector<char> >& board, int cx, int cy, int d){
    if(board[cx][cy] != '1')    return false;
    for(int k=d;k >= 1;k--){
        if(board[cx-k][cy-k] != '1'        //NW
        || board[cx-k][cy+k] != '1'        //NE
        || board[cx+k][cy-k] != '1'        //SW
        || board[cx+k][cy+k] != '1'){      //SE
            return false;
        }
    }
    return true;
}

int solve(const vector<vector<char> >& board){
    int m = board.size();
    int n = board.size();
    if(m<3 || n<3)    return 0;
    int d=1;
    for(int cx=d, cy=d; cx+d<m && cy+d<n;){
        if(check(board, cx, cy, d)){
            ++d;
            cx=d;
            cy=d;
        }else{
            ++cy;
            if(cy+d >= m){
                ++cx;
                cy=d;
            }
        }
    }
    return d-1;
}

void display(const vector<vector<char> >& board){
    int m=board.size();
    int n=board.size();
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void display(const vector<char>& line){
    int m = line.size();
    for(int i=0;i<m;i++){
        printf("%c ", line[i]);
    }
    printf("\n");
}

void test_01(){
    vector<vector<char> > board;
    char arr0[] = {'1', '0', '1', '1', '1', '0', '1'};
    vector<char> vec0(arr0, arr0 + sizeof(arr0)/sizeof(char));
    board.push_back(vec0);

    char arr1[] = {'0', '1', '0', '1', '1', '1', '0'};
    vector<char> vec1(arr1, arr1 + sizeof(arr1)/sizeof(char));
    board.push_back(vec1);
    
    char arr2[] = {'1', '0', '1', '0', '1', '0', '1'};
    vector<char> vec2(arr2, arr2 + sizeof(arr2)/sizeof(char));
    board.push_back(vec2);
    
    char arr3[] = {'1', '1', '1', '1', '0', '1', '1'};
    vector<char> vec3(arr3, arr3 + sizeof(arr3)/sizeof(char));
    board.push_back(vec3);
    
    char arr4[] = {'1', '1', '1', '0', '1', '1', '0'};
    vector<char> vec4(arr4, arr4 + sizeof(arr4)/sizeof(char));
    board.push_back(vec4);
    
    char arr5[] = {'1', '0', '1', '1', '0', '1', '1'};
    vector<char> vec5(arr5, arr5 + sizeof(arr5)/sizeof(char));
    board.push_back(vec5);
    
    char arr6[] = {'1', '1', '1', '1', '1', '0', '1'};
    vector<char> vec6(arr6, arr6 + sizeof(arr6)/sizeof(char));
    board.push_back(vec6);
    
    display(board);
    printf("largest x is leg of %d\n", solve(board));
}

void test_02(){
    vector<vector<char> > board;
    char arr0[] = {'1', '0', '0', '0', '0', '0', '1'};
    vector<char> vec0(arr0, arr0 + sizeof(arr0)/sizeof(char));
    board.push_back(vec0);

    char arr1[] = {'0', '1', '0', '0', '0', '1', '0'};
    vector<char> vec1(arr1, arr1 + sizeof(arr1)/sizeof(char));
    board.push_back(vec1);
    
    char arr2[] = {'1', '0', '1', '0', '1', '0', '1'};
    vector<char> vec2(arr2, arr2 + sizeof(arr2)/sizeof(char));
    board.push_back(vec2);
    
    char arr3[] = {'0', '0', '0', '1', '0', '0', '0'};
    vector<char> vec3(arr3, arr3 + sizeof(arr3)/sizeof(char));
    board.push_back(vec3);
    
    char arr4[] = {'0', '0', '1', '0', '1', '1', '0'};
    vector<char> vec4(arr4, arr4 + sizeof(arr4)/sizeof(char));
    board.push_back(vec4);
    
    char arr5[] = {'0', '1', '0', '0', '0', '1', '1'};
    vector<char> vec5(arr5, arr5 + sizeof(arr5)/sizeof(char));
    board.push_back(vec5);
    
    char arr6[] = {'1', '0', '0', '0', '0', '0', '1'};
    vector<char> vec6(arr6, arr6 + sizeof(arr6)/sizeof(char));
    board.push_back(vec6);
    
    display(board);
    printf("largest x is leg of %d\n", solve(board));
}
int main(int, char**){
    test_01();
    test_02();
    return 0;
}
