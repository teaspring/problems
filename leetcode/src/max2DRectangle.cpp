/*
 * a matrix is made up of '1' and '0', find the maximum rectangle which ONLY contains '1'
 */

#include "../include/preliminary.h"

class Max2DRectangle{
public:
    int maximumRectangle(vector<vector<char> >& matrix){ //to project 2D matrix to 1D array eventually
        if(matrix.empty())    return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        if(n==0)    return 0;
        int horizon[n];
        memset(horizon, 0, sizeof(horizon));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    horizon[j] += 1;
                }else{
                    horizon[j] = 0;
                }
            }
            vector<int> height(horizon, horizon + n);
            int tmp = largestRectangleArea(height);
            res = max(res, tmp);
        }
        return res;
    }

    int largestRectangleArea(const vector<int>& height){ //max rectangle in one array, time is O(n)
        int n = height.size(), res = 0;
        if(n == 0)    return res;
        stack<int> stk;    // store index
        for(int i=0; i<=n; i++){  // include i==n avoids the appendix process
            int h = i == n ? 0 : height[i];
            while(!stk.empty()){
                int p = stk.top();
                if(height[p] < h)    break;
                stk.pop();
                int start = stk.empty() ? -1 : stk.top();  // start is exclusive index in left
                res = max(res, (i-1 - start) * height[p]); // i-1 is inclusive index
            }
            stk.push(i);
        }
        return res;
    }

    void test_01(){
        vector<vector<char> > matrix;
        char arr0[] = {'1', '0'};
        matrix.push_back(vector<char>(arr0, arr0 + sizeof(arr0)/sizeof(char)));
        char arr1[] = {'0', '1'};
        matrix.push_back(vector<char>(arr1, arr1 + sizeof(arr1)/sizeof(char)));
        cout << maximumRectangle(matrix) << endl;
    }

    void test_02(){
        vector<vector<char> > matrix;
        char arr0[] = {'1'};
        matrix.push_back(vector<char>(arr0, arr0 + sizeof(arr0)/sizeof(char)));
        cout << maximumRectangle(matrix) << endl;
    }

};

int main(){
    Max2DRectangle m2d;
    m2d.test_01();
    m2d.test_02();
    return 0;
}
