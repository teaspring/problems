/*
 * a matrix is made up of '1' and '0', find the maximum rectangle which ONLY contains '1'
 *
 * [1, 2, 4, 0, 2], every int has one unit of width. max area is 4
 */

#include "../include/preliminary.h"

class Solution{
public:
    int maximumRectangle(vector<vector<char> >& matrix){ //to project 2D matrix to 1D array eventually
        if(matrix.empty())    return 0;

        const int m = matrix.size();
        const int n = matrix[0].size();
        int res = 0;
        if(n == 0)    return 0;

        int horizon[n];
        memset(horizon, 0, sizeof(horizon));

        for(int i = 0; i < m; i++){ // each row
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    horizon[j] += 1;
                }else{
                    horizon[j] = 0;
                }
            }
            vector<int> height(horizon, horizon + n);
            int tmp = largestRectangleArea(height);
            res = max(res, tmp);

            height.clear();
        }
        return res;
    }

    int largestRectangleArea(const vector<int>& heights){ //max rectangle in one array, time is O(n)
        const int n = heights.size();
        if(n == 0)    return 0;

        int res = 0;
        stack<int> stk; // store index

        for(int i = 0; i <= n; i++){  // include i == n avoids the appendix process
            int h = (i == n ? 0 : heights[i]);
            while(!stk.empty() && heights[stk.top()] > h){ // before lower height push to stack, pop higher height
                int p = stk.top();                         // and calculate their rectangle
                stk.pop();

                if(!stk.empty() && heights[stk.top()] == heights[p])    continue;

                int start = (stk.empty() ? -1 : stk.top());  // start is exclusive left index

                int tmp = (i-1 - start) * heights[p]; // i-1 is inclusive right index
                res = max(res, tmp);
            }
            stk.push(i); // push height which is greater than or equal to [stk.top()]
        }
        return res;
    }
};

/* unit test is in ../cpp_unittest/max2DRectangle_unittest */
