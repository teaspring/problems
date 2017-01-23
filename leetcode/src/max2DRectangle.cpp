/*
 * Problem: a matrix is made up of '1' and '0', find the maximum rectangle which ONLY contains '1'
 *
 * Sub prolem: given integer array which int val is expressed as height of unit width, get the maximum rectangle area
 * E.g. [1, 2, 4, 0, 2], every int has one unit of width. max area is 4
 */

#include "../include/preliminary.h"

class Solution{
public:
    int maximumRectangle(vector<vector<char> >& matrix){ //to project 2D matrix to 1D array eventually
        if(matrix.empty() || matrix[0].empty())    return 0;

        const int m = matrix.size();
        const int n = matrix[0].size();
        int res = 0;
        vector<int> horizon(n, 0);

        for(int i = 0; i < m; i++){ // each row
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    horizon[j] += 1;
                }else{
                    horizon[j] = 0;
                }
            }

            int tmp = largestRectangleInArray(horizon);
            res = max(res, tmp);
        }
        return res;
    }

    // sub problem: get max rectangle area in int array, time in O(n)
    int largestRectangleInArray(const vector<int>& heights){
        if(heights.empty())    return 0;

        int res = 0;
        const int n = heights.size();
        stack<int> stk; // store index

        for(int i = 0; i <= n; i++){  // include i == n avoids the appendix process
            int h = (i == n ? 0 : heights[i]);
            while(!stk.empty() && heights[stk.top()] > h){ // before push lower height to stack, pop higher height
                int idx = stk.top();                       // and calculate its rectangle. this while-loop in time O(1)
                stk.pop();

                if(!stk.empty() && heights[stk.top()] == heights[idx])    continue;

                int start = (stk.empty() ? -1 : stk.top());  // start is exclusive left index

                int tmp = (i-1 - start) * heights[idx]; // i-1 is inclusive right index
                res = max(res, tmp);
            }
            stk.push(i); // push height which is greater than or equal to [stk.top()]
        }
        return res;
    }
};

/* unit test is in ../cpp_unittest/max2DRectangle_unittest */
