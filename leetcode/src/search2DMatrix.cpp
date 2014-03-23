/*
 * write an efficient algorithm that searches for a value in an m * n matrix.
 * the matrix is: integers in each row are sorted from left to right; 1st integer of each row is greater than the last integer of previous row
 * e.g.
 * 1   3   5   7
 * 10 11  16  20
 * 23 30  34  50
 * search for 3, return yes
 * */
#include "stdio.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool searchMatrix_01(vector<vector<int> >& matrix, int target){
    int n = matrix.size();
    if(n < 1)    return false;
    int m = matrix[0].size();
    int v=0, u=m*n-1, mid=v, i=0, j=0;  //search range [v,u]
    while(v <= u){
        mid = (v+u) >> 1;
        i = mid/m;
        j = mid%m;
        if(target == matrix[i][j]){
            return true;
        }else if(target < matrix[i][j]){
            u = mid - 1;
        }else{
            v = mid + 1;
        }
    }
    return matrix[i][j] == target;
}

bool searchMatrix_02(vector<vector<int> >& matrix, int target){
    int n = matrix.size();
    if(n < 1)    return false;
    int m = matrix[0].size();
    int v=0, u=m*n, mid=v, i=0, j=0;  //search range [v,u)
    while(v < u){
        mid = (v+u) >> 1;
        i = mid/m;
        j = mid%m;
        if(target == matrix[i][j]){
            return true;
        }else if(target < matrix[i][j]){
            u = mid;
        }else{
            v = mid + 1;
        }
    }
    return matrix[i][j] == target;
}

void test_01(){
    int arr0[] = {1, 3, 5, 7};
    vector<int> vec0(arr0, arr0 + 4);
    int arr1[] = {10, 11, 16, 20};
    vector<int> vec1(arr1, arr1 + 4);
    int arr2[] = {23, 30, 34, 50};
    vector<int> vec2(arr2, arr2 + 4);
    vector<vector<int> > matrix;
    matrix.push_back(vec0);
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    cout << (searchMatrix_01(matrix, 3) ? "true" : "false") << endl;
    return;
}

int main(int, char**){
    test_01();
    return 0;
}

