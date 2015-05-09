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

class Solution{

public:
    /*
     * typical binary search problem
     * */
    bool searchMatrix_01(vector<vector<int> >& matrix, int target){
        const int n = matrix.size();  // row
        if(n < 1)    return false;

        const int m = matrix[0].size();  // column
        int v = 0, u = m*n - 1, mid = v;  // init u is inclusive

        while(v < u){ // as v equals to u in maximum, both v and u are inclusive forever, even breaking loop
            mid = (v + u) >> 1;
            int i = mid / m;  // row, n-1 in maximum
            int j = mid % m;  // col, m-1 in maximum
            if(target == matrix[i][j]){
                return true;
            }else if(target < matrix[i][j]){
                u = mid;
            }else{
                v = mid + 1;
            }
        }

        mid = (v + u) >> 1;
        return matrix[mid / m][mid % m] == target;
    }

    bool searchMatrix_02(vector<vector<int> >& matrix, int target){
        const int n = matrix.size();
        if(n < 1)    return false;

        const int m = matrix[0].size();
        int v = 0, u = m*n;  // init u is exclusive

        while(v < u){ // as v equals to u in maximum and u is exclusive, all the valid [i,j] compare must be inside the clause
            int mid = (v + u) >> 1;
            int i = mid / m;  // row, n-1 in maximum
            int j = mid % m;  // col, m-1 in maximum
            if(target == matrix[i][j]){
                return true;
            }else if(target < matrix[i][j]){
                u = mid;
            }else{
                v = mid + 1;
            }
        }

        return false;
    }
};

